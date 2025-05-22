#include "mgc3130.h"
#include "lvgl.h"
#include "ui.h"
extern I2C_HandleTypeDef hi2c1;
extern lv_obj_t * info_label;

void MGC3130_Init(MGC3130_t *dev) {
    MGC3130_SetTsInput(dev);   // 设置 TS 引脚为输入
    MGC3130_Reset(dev);        // 复位 MGC3130
    dev->position = 0;
    dev->lastTimeStamp = 0;
    // I2C 初始化由外部完成，这里不调用 HAL_I2C_Init
   HAL_Delay(200);

}

void MGC3130_Reset(MGC3130_t *dev) {
    HAL_GPIO_WritePin(dev->resetPort, dev->resetPin, GPIO_PIN_RESET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(dev->resetPort, dev->resetPin, GPIO_PIN_SET);
    HAL_Delay(200); // 等待 MGC3130 启动完成
}

void MGC3130_SetTsInput(MGC3130_t *dev) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = dev->tsPin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(dev->tsPort, &GPIO_InitStruct);
}

void MGC3130_SetTsOutput(MGC3130_t *dev) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = dev->tsPin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(dev->tsPort, &GPIO_InitStruct);
}

void MGC3130_WriteTs(MGC3130_t *dev, GPIO_PinState state) {
    HAL_GPIO_WritePin(dev->tsPort, dev->tsPin, state);
}

GPIO_PinState MGC3130_ReadTs(MGC3130_t *dev) {
    return HAL_GPIO_ReadPin(dev->tsPort, dev->tsPin);
}

int8_t MGC3130_EnableDataOutput(MGC3130_t *dev)
{
    uint8_t pBuf[] = {
        0xA0, 0x00, 0x00, 0x00,    // Command ID
        0x1E, 0x00, 0x00, 0x00,    // DataOutputConfigMask
        0xFF, 0xFF, 0xFF, 0xFF     // Enable all output
    };
    uint8_t recvBuf[16];
    int8_t ret = -1;

    MGC3130_SetRuntimeParameter(dev, pBuf, sizeof(pBuf));
    if (MGC3130_ReadData(dev, recvBuf, sizeof(recvBuf)) != 0) {
        if (recvBuf[4] == 0xA2) {
            uint16_t errorCode = ((uint16_t)recvBuf[7] << 8) | recvBuf[6];
            if (errorCode == 0) {
                ret = 0;
            }
        }
    }
    return ret;
}

int8_t MGC3130_LockDataOutput(MGC3130_t *dev)
{
    uint8_t pBuf[] = {
        0xA1, 0x00, 0x00, 0x00,    // Command ID
        0x1E, 0x00, 0x00, 0x00,    // DataOutputConfigMask
        0xFF, 0xFF, 0xFF, 0xFF     // Lock all output
    };
    uint8_t recvBuf[16];
    int8_t ret = -1;

    MGC3130_SetRuntimeParameter(dev, pBuf, sizeof(pBuf));
    if (MGC3130_ReadData(dev, recvBuf, sizeof(recvBuf)) != 0) {
        if (recvBuf[4] == 0xA2) {
            uint16_t errorCode = ((uint16_t)recvBuf[7] << 8) | recvBuf[6];
            if (errorCode == 0) {
                ret = 0;
            }
        }
    }
    return ret;
}

int8_t MGC3130_EnableGestures(MGC3130_t *dev)
{
    uint8_t pBuf[] = {
        0x85, 0x00, 0x00, 0x00,   // Command ID: 0x0085
        0x7F, 0x00, 0x00, 0x00,   // Gesture Enable Mask
        0x7F, 0x00, 0x00, 0x00    // Gesture Valid Mask
    };

    uint8_t recvBuf[16];
    int8_t ret = -1;

    if (MGC3130_SetRuntimeParameter(dev, pBuf, sizeof(pBuf)) != 0) {
        if (MGC3130_ReadData(dev, recvBuf, sizeof(recvBuf)) != 0) {
            if (recvBuf[4] == 0xA2) {
                uint16_t errorCode = (recvBuf[7] << 8) | recvBuf[6];
                if (errorCode == 0) {
                    ret = 0;
                }
            }
        }
    }

    return ret;
}

int8_t MGC3130_EnableTouchDetection(MGC3130_t *dev)
{
    uint8_t pBuf[] = {
        0x97, 0x00, 0x00, 0x00,   // Command ID: 0x0097
        0x08, 0x00, 0x00, 0x00,   // Touch Enable Mask
        0x08, 0x00, 0x00, 0x00    // Touch Valid Mask
    };

    uint8_t recvBuf[16];
    int8_t ret = -1;

    if (MGC3130_SetRuntimeParameter(dev, pBuf, sizeof(pBuf)) != 0) {
        if (MGC3130_ReadData(dev, recvBuf, sizeof(recvBuf)) != 0) {
            if (recvBuf[4] == 0xA2) {
                uint16_t errorCode = (recvBuf[7] << 8) | recvBuf[6];
                if (errorCode == 0) {
                    ret = 0;
                }
            }
        }
    }

    return ret;
}

int8_t MGC3130_EnableApproachDetection(MGC3130_t *dev)
{
    uint8_t pBuf[] = {
        0x97, 0x00, 0x00, 0x00,   // Command ID: 0x0097
        0x01, 0x00, 0x00, 0x00,   // Approach Enable
        0x01, 0x00, 0x00, 0x00    // Approach Valid
    };

    uint8_t recvBuf[16];
    int8_t ret = -1;

    if (MGC3130_SetRuntimeParameter(dev, pBuf, sizeof(pBuf)) != 0) {
        if (MGC3130_ReadData(dev, recvBuf, sizeof(recvBuf)) != 0) {
            if (recvBuf[4] == 0xA2) {
                uint16_t errorCode = (recvBuf[7] << 8) | recvBuf[6];
                if (errorCode == 0) {
                    ret = 0;
                }
            }
        }
    }

    return ret;
}




void MGC3130_ReceiveSensorData(MGC3130_t *dev)
{
    uint8_t pbuf[24];
    static uint16_t rest_cnt = 0;
    uint8_t temp_size = 0;

    dev->position = false;
    memset(&dev->info, 0, sizeof(MGC3130_Info_t));

    temp_size = MGC3130_ReadData(dev, pbuf, sizeof(pbuf));
    if(temp_size!=0){     //(MGC3130_ReadData(dev, pbuf, sizeof(pbuf)) != 0) {
        // 判断消息类型是否为 SensorDataOutput (0x91) + DataOutputConfig (0x1E)
        if (pbuf[3] == 0x91 && pbuf[4] == 0x1E) {
            dev->info.gestureInfo = 
                pbuf[8]  | ((uint32_t)pbuf[9] << 8) |
                ((uint32_t)pbuf[10] << 16) | ((uint32_t)pbuf[11] << 24);

            dev->info.touchInfo = 
                pbuf[12] | ((uint32_t)pbuf[13] << 8) |
                ((uint32_t)pbuf[14] << 16) | ((uint32_t)pbuf[15] << 24);

            dev->nowTimeStamp = pbuf[14] | ((uint32_t)pbuf[15] << 8);
            dev->nowTouch = pbuf[12] | ((uint32_t)pbuf[13] << 8);

            if (pbuf[7] & 0x02) {  // AirWheel valid flag
                dev->info.airWheelInfo = pbuf[16] | ((uint32_t)pbuf[17] << 8);
            }

            if (pbuf[7] & 0x01) {  // Position valid flag
                dev->position = true;
                dev->info.xPosition = pbuf[18] | ((uint32_t)pbuf[19] << 8);
                dev->info.yPosition = pbuf[20] | ((uint32_t)pbuf[21] << 8);
                dev->info.zPosition = pbuf[22] | ((uint32_t)pbuf[23] << 8);
            }

        } else if (pbuf[4] == 0x1F) {
            // 数据流未开启，尝试开启
            while (MGC3130_EnableDataOutput(dev) != 0) {
                HAL_Delay(50);
            }
            while (MGC3130_LockDataOutput(dev) != 0) {
                HAL_Delay(50);
            }
        }

        //lv_label_set_text_fmt(info_label, "pbuf[3]:%#x,pbuf[4]:%#x,touch:%d", pbuf[3],pbuf[4],dev->info.touchInfo); // 更新 UI 显示
        
        lv_label_set_text_fmt(info_label,"zPosition:%d,position:%d",dev->info.zPosition,dev->position); // 更新 UI 显示

        // if(pbuf[3]==0&&pbuf[4]==0){
        //     rest_cnt++;
        //     if(rest_cnt>20){

        //         MGC3130_Init(dev); // 重新初始化
        //         MGC3130_EnableGestures(dev); // 重新使能手势
        //         HAL_Delay(50);  
        //         MGC3130_EnableTouchDetection(dev); // 重新使能触摸检测
        //         HAL_Delay(50);
        //         rest_cnt = 0;
        //         return;
        //     }
        // }
        
        // if(dev->info.gestureInfo==GESTURE_FLICK_R){
        //     lv_label_set_text(info_label, "Flick Right to Left");
        //   }
        //   else if(dev->info.gestureInfo==GESTURE_FLICK_L){
        //     lv_label_set_text(info_label, "Flick Left to Right");
        //   }
        //   else if(dev->info.gestureInfo==GESTURE_FLICK_U){
        //     lv_label_set_text(info_label, "Flick Down to Up");
        //   }
        //   else if(dev->info.gestureInfo==GESTURE_FLICK_D){
        //     lv_label_set_text(info_label, "Flick Up to Down");
        //   }
        

        //lv_label_set_text(info_label, "MGC3130 data received!"); // 更新 UI 显示

    } else {
		lv_label_set_text(info_label, "ReceiveSensorData null!!");
        // HAL_Delay(500);
    }
    
    
}


uint8_t MGC3130_SetRuntimeParameter(MGC3130_t *dev, const uint8_t *pBuf, size_t size)
{
    if (pBuf == NULL) {
        //lv_label_set_text(info_label, "SetRuntime ERROR!! : null pointer");
        // 可以加打印或断言提示
        return 0;
    }

    uint8_t header[4] = { 0x10, 0x00, 0x00, 0xA2 }; // 与 Arduino 版相同
    uint8_t txBuf[64]; // 假设最大为 64 字节，可根据情况调大
    if (size + 4 > sizeof(txBuf)) return 0;

    memcpy(txBuf, header, 4);
    memcpy(txBuf + 4, pBuf, size);

    if (HAL_I2C_Master_Transmit(dev->hi2c, MGC3130_I2C_ADDR, txBuf, size + 4, HAL_MAX_DELAY) != HAL_OK) {
        //lv_label_set_text(info_label, "I2C Transmit ERROR!!");
        return 0;
    }

    return size;
}

uint8_t MGC3130_ReadData(MGC3130_t *dev, uint8_t *pBuf, size_t size)
{
    if (pBuf == NULL) {
        //lv_label_set_text(info_label, "MGC3130_ReadData ERROR!! : null pointer");
        return 0;
    }

    if (HAL_GPIO_ReadPin(dev->tsPort, dev->tsPin) != GPIO_PIN_RESET) {
        // lv_label_set_text(info_label, "TS Pin is not low!");
        return 0; // TS 引脚非低电平，不可读取
    }

    // 将 TS 引脚设为输出并拉低，表示读取请求
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = dev->tsPin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(dev->tsPort, &GPIO_InitStruct);
	HAL_GPIO_WritePin(dev->tsPort, dev->tsPin, GPIO_PIN_RESET);

		
    HAL_Delay(1); // 稍作延时确保稳定

    // 发起读取
    if (HAL_I2C_Master_Receive(dev->hi2c, MGC3130_I2C_ADDR, pBuf, size, HAL_MAX_DELAY) != HAL_OK) {
        return 0;
    }
    
    // 通信结束，将 TS 引脚拉高并设置为输入
    HAL_GPIO_WritePin(dev->tsPort, dev->tsPin, GPIO_PIN_SET);
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;  // 模拟外部10k上拉
    HAL_GPIO_Init(dev->tsPort, &GPIO_InitStruct);

    HAL_Delay(5); // 按照原逻辑延迟 5ms
    return size;
}

