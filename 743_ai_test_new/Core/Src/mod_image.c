#include "mod_image.h"
#include "lcd_169_drv.h"

void Copy_Camera_Buffer(uint16_t dst[Modified_Height][Modified_Width],uint16_t *src){
  uint16_t i,j;
	for(i=0;i<Modified_Height;i++){
		for(j=0;j<Modified_Width;j++){
			uint16_t tmp=src[i*Display_Height/Modified_Height*Display_Width+j*Display_Width/Modified_Width];
			dst[Modified_Height-1-i][j]=tmp;
		}
	}
}

void Copy_Process_to_Display(uint16_t *dst, uint16_t src[Modified_Height][Modified_Width]){
	uint16_t i,j;
	for(i=0;i<Display_Height;i++){
		for(j=0;j<Display_Width;j++){
			uint16_t tmp=src[i*Modified_Height/Display_Height][j*Modified_Width/Display_Width];
			dst[i*Display_Width+j]=tmp;
		}
	}
}

void Display_Process_Buffer_Directly(uint16_t src[Modified_Height][Modified_Width])
{
    uint16_t i, j;

    for (i = 0; i < Display_Height; i++) {
        for (j = 0; j < Display_Width; j++) {
            uint16_t src_y = i * Modified_Height / Display_Height;
            uint16_t src_x = j * Modified_Width / Display_Width;
            line_buffer[j] = src[src_y][src_x];
        }

        // 使用你原来的可靠接口来写入每一行
        LCD_CopyBuffer(20, i, Display_Width, 1, line_buffer);
    }
}
