#include "headshot.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

int center_x = -1;
int center_y = -1;

static uint8_t gray[HEIGHT][WIDTH];
static uint8_t binary[HEIGHT][WIDTH];
static uint8_t edge[HEIGHT][WIDTH];
static uint8_t eroded[HEIGHT][WIDTH];
static uint8_t visited[HEIGHT][WIDTH];

const int directions[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},          {0, 1},
    {1, -1},  {1, 0}, {1, 1}
};

// RGB565转灰度
static inline uint8_t RGB565_to_Gray(uint16_t pixel) {
    uint8_t r = (pixel >> 11) & 0x1F;
    uint8_t g = (pixel >> 5) & 0x3F;
    uint8_t b = pixel & 0x1F;
    // 转换为8位灰度，使用近似加权
    return (uint8_t)(((r << 3) * 299 + (g << 2) * 587 + (b << 3) * 114) / 1000 / 255.0 * 255);
}

// 灰度化
static void ToGray(void) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            gray[i][j] = RGB565_to_Gray(Process_Buffer[i][j+25]);
        }
    }
}

// OTSU阈值计算与二值化
static void OTSU_Binarize(void) {
    uint32_t hist[256] = {0};
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++) {
            hist[gray[i][j]]++;
        }

    // 加权暗区域
    for (int i = 0; i < 72; i++) hist[i] *= 3;

    uint32_t total = HEIGHT * WIDTH;
    double sum = 0;
    for (int t = 0; t < 256; t++) sum += t * hist[t];
    
    double max_sigma = 0;
    int best_thresh = 0;
    double w0 = 0, mu0 = 0;

    for (int t = 0; t < 256; t++) {
        w0 += hist[t];
        if (w0 == 0 || w0 == total) continue;
        mu0 += t * hist[t];
        double m0 = mu0 / w0;
        double m1 = (sum - mu0) / (total - w0);
        double sigma = (w0 / total) * (1 - w0 / total) * (m0 - m1) * (m0 - m1);
        if (sigma > max_sigma) {
            max_sigma = sigma;
            best_thresh = t;
        }
    }

    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            binary[i][j] = (gray[i][j] < best_thresh) ? 1 : 0;
}

// SUSAN边缘检测
static void SUSAN_EdgeDetect(void) {
    const int T = 15, R = 3;
    const int G = (2 * R + 1) * (2 * R + 1) / 2;
    const float threshold = 0.5f;

    memset(edge, 0, sizeof(edge));

    for (int i = R; i < HEIGHT - R; i++) {
        for (int j = R; j < WIDTH - R; j++) {
            int similar = 0;
            uint8_t center = gray[i][j];
            for (int dx = -R; dx <= R; dx++) {
                for (int dy = -R; dy <= R; dy++) {
                    if (abs(gray[i + dx][j + dy] - center) <= T)
                        similar++;
                }
            }
            float ratio = (float)(G - similar) / G;
            edge[i][j] = (ratio > threshold) ? 1 : 0;
        }
    }
}

// 合并OTSU和SUSAN结果
static void CombineBinaryAndEdge(void) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            binary[i][j] = binary[i][j] || edge[i][j];
}

// 腐蚀操作
static void Erode(void) {
    memcpy(eroded, binary, sizeof(binary));

    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            if (!binary[i][j]) continue;
            for (int d = 0; d < 8; d++) {
                int ni = i + directions[d][0];
                int nj = j + directions[d][1];
                if (!binary[ni][nj]) {
                    eroded[i][j] = 0;
                    break;
                }
            }
        }
    }
}

// BFS找最大连通域
static void BFS(int sx, int sy, int* size, int* sum_x, int* sum_y) {
    int queue[HEIGHT * WIDTH][2];
    int front = 0, rear = 0;

    queue[rear][0] = sx;
    queue[rear][1] = sy;
    rear++;
    visited[sx][sy] = 1;

    *size = 1;
    *sum_x = sx;
    *sum_y = sy;

    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;
        for (int d = 0; d < 8; d++) {
            int nx = x + directions[d][0];
            int ny = y + directions[d][1];
            if (nx >= 0 && nx < HEIGHT && ny >= 0 && ny < WIDTH && !visited[nx][ny] && eroded[nx][ny]) {
                queue[rear][0] = nx;
                queue[rear][1] = ny;
                rear++;
                visited[nx][ny] = 1;
                (*size)++;
                *sum_x += nx;
                *sum_y += ny;
            }
        }
    }
}

// 主接口函数
void Locate_Largest_Component(void) {
    ToGray();
    OTSU_Binarize();
    SUSAN_EdgeDetect();
    CombineBinaryAndEdge();
    Erode();
    memset(visited, 0, sizeof(visited));

    int max_size = 0;
    int best_sum_x = 0, best_sum_y = 0;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (!visited[i][j] && eroded[i][j]) {
                int size = 0, sum_x = 0, sum_y = 0;
                BFS(i, j, &size, &sum_x, &sum_y);
                if (size > max_size) {
                    max_size = size;
                    best_sum_x = sum_x;
                    best_sum_y = sum_y;
                }
            }
        }
    }

    if (max_size > 0) {
        center_x = best_sum_x / max_size;
        center_y = best_sum_y / max_size + 25;
    } else {
        center_x = -1;
        center_y = -1;
    }
}
