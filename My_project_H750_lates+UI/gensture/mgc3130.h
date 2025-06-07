#ifndef __MGC3130_H
#define __MGC3130_H

#include "stm32h7xx_hal.h"
#include "string.h"
#include "i2c.h"

#define MGC3130_I2C_ADDR      (0x42 << 1)  // STM32 HAL 要左移1位
#define false 0 
#define true 1
	
typedef enum {
    NO_ERROR                = 0x0000,   /**< OK */
    UNKNOWN_COMMAND         = 0x0001,   /**< Message ID is unknown */
    WRONG_PARAMETER_VALUE   = 0x0014,   /**< Value of Argument/Parameter is out of valid range */
    UNKNOWN_PARAMETER_ID    = 0x0015,   /**< RuntimeParameterID is out of range */
    WAKEUP_OCCURRED         = 0x001A    /**< A wake-up by Host was detected */
} MGC3130_ErrorCode_t;

typedef enum {
    GESTURE_NONE                = 0,    /**< No gesture */
    GESTURE_GARBAGE_MODEL,             /**< Garbage model */
    GESTURE_FLICK_R,                   /**< Flick Left to Right */
    GESTURE_FLICK_L,                   /**< Flick Right to Left */
    GESTURE_FLICK_U,                   /**< Flick Down to Up */
    GESTURE_FLICK_D,                   /**< Flick Up to Down */
    GESTURE_CIRCLE_CW,                 /**< Circle clockwise */
    GESTURE_CIRCLE_CCW                /**< Circle counterclockwise */
} MGC3130_Gesture_t;

typedef enum {
    TOUCH_DOWN           = (1 << 0),   /**< Touch Down electrode */
    TOUCH_LEFT           = (1 << 1),   /**< Touch Left electrode */
    TOUCH_UP             = (1 << 2),   /**< Touch Up electrode */
    TOUCH_RIGHT          = (1 << 3),   /**< Touch Right electrode */
    TOUCH_CENTER         = (1 << 4),   /**< Touch Center electrode */
    TAP_DOWN             = (1 << 5),   /**< Tap Down electrode */
    TAP_LEFT             = (1 << 6),   /**< Tap Left electrode */
    TAP_UP               = (1 << 7),   /**< Tap Up electrode */
    TAP_RIGHT            = (1 << 8),   /**< Tap Right electrode */
    TAP_CENTER           = (1 << 9),   /**< Tap Center electrode */
    DOUBLE_TAP_DOWN      = (1 << 10),  /**< Double Tap Down */
    DOUBLE_TAP_LEFT      = (1 << 11),  /**< Double Tap Left */
    DOUBLE_TAP_UP        = (1 << 12),  /**< Double Tap Up */
    DOUBLE_TAP_RIGHT     = (1 << 13),  /**< Double Tap Right */
    DOUBLE_TAP_CENTER    = (1 << 14)   /**< Double Tap Center */
} MGC3130_Touch_t;


typedef struct {
    uint32_t gestureInfo;
    uint32_t touchInfo;
    uint32_t airWheelInfo;
    uint16_t xPosition;
    uint16_t yPosition;
    uint16_t zPosition;
} MGC3130_Info_t;

typedef struct {
    I2C_HandleTypeDef *hi2c;
    GPIO_TypeDef *tsPort;
    uint16_t tsPin;
    GPIO_TypeDef *resetPort;
    uint16_t resetPin;
    MGC3130_Info_t info;
	uint8_t position;
	uint16_t lastTimeStamp,nowTimeStamp;
	uint16_t lastTouch,nowTouch;
} MGC3130_t;

void MGC3130_Init(MGC3130_t *dev);
void MGC3130_Reset(MGC3130_t *dev);
// TS 引脚控制
void MGC3130_SetTsInput(MGC3130_t *dev);
void MGC3130_SetTsOutput(MGC3130_t *dev);
void MGC3130_WriteTs(MGC3130_t *dev, GPIO_PinState state);
GPIO_PinState MGC3130_ReadTs(MGC3130_t *dev);


int8_t MGC3130_EnableGestures(MGC3130_t *dev);
int8_t MGC3130_EnableTouchDetection(MGC3130_t *dev);
int8_t MGC3130_EnableApproachDetection(MGC3130_t *dev);
int8_t MGC3130_EnableAirWheel(MGC3130_t *dev);

void MGC3130_ReceiveSensorData(MGC3130_t *dev);

int8_t MGC3130_EnableDataOutput(MGC3130_t *dev);
int8_t MGC3130_LockDataOutput(MGC3130_t *dev);


uint8_t MGC3130_SetRuntimeParameter(MGC3130_t *dev, const uint8_t *pBuf, size_t size);
uint8_t MGC3130_ReadData(MGC3130_t *dev, uint8_t *pBuf, size_t size);


#endif
