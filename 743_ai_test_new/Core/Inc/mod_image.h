#ifndef _MOD_IMAGE_H
#define _MOD_IMAGE_H

#include "main.h"
#include "lcd_169_drv.h"
#include "dcmi_ov2640.h"  
#include<string.h>

void Copy_Camera_Buffer(uint16_t dst[Modified_Height][Modified_Width],uint16_t *src);
void Copy_Process_to_Display(uint16_t *dst, uint16_t src[Modified_Height][Modified_Width]);
void Display_Process_Buffer_Directly(uint16_t src[Modified_Height][Modified_Width]);

#endif
