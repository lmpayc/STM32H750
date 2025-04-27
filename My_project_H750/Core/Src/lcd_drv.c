#include "main.h"
#include "lcd_169_drv.h"

#define  LCD_SPI hspi4           // SPI局部宏，方便修改和移植
// 该函数修改于HAL的SPI库函数，专为 LCD_Clear() 清屏函数修改，
// 目的是为了SPI传输数据不限数据长度的写入
HAL_StatusTypeDef LCD_SPI_Transmit(SPI_HandleTypeDef *hspi, uint16_t pData, uint32_t Size);
HAL_StatusTypeDef LCD_SPI_TransmitBuffer (SPI_HandleTypeDef *hspi, uint16_t *pData, uint32_t Size);



//---------指定位置画点------------------------
void LCD_DrawPixel(uint16_t x, uint16_t y, uint32_t color) {
    
	  if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT) { // 确保坐标在屏幕范围内
        //frameBuffer[y * SCREEN_WIDTH + x] = color; // 设置像素颜色
			  DIS_BUFFER[(y) * (SCREEN_WIDTH) + x]=color;
    }
}
// -------------------清屏函数--------------------------
void ClearScreen(uint16_t color) {
    
	  unsigned int i,ROW,column;
    TFT_SET_ADD(0,0,TFT_COLUMN_NUMBER-1,TFT_LINE_NUMBER-1);
    i=0;
		for(ROW=0;ROW<TFT_LINE_NUMBER;ROW++)             //ROW loop
    {     
        for(column=0;column<TFT_COLUMN_NUMBER;column++)  //column loop
        {             
			
					DIS_BUFFER[i++]=color;
        }
    }
		TransmitLargeData(DIS_BUFFER,TFT_COLUMN_NUMBER*TFT_LINE_NUMBER);
		
}


//**************************SPI模块发送函数************************************************

void SPI_SendByte(uint8_t *txData,  uint16_t size)
{       
    LCD_CSL;  //拉低NSS引脚，开始传输 
	// 进行数据传输	   
    HAL_SPI_Transmit(&hspi1, txData, 1, HAL_MAX_DELAY);	    
	  LCD_CSH;
}
//--------------写命令-------------------------------------
void TFT_SEND_CMD(uint8_t data)
{
    uint8_t txData[2];
	  txData[0]=data;
	  LCD_CDL;  //命令模式	
	  LCD_CSL;  //拉低NSS引脚，开始传输
	// 进行数据传输	   
    HAL_SPI_Transmit(&hspi1, txData, 1, HAL_MAX_DELAY);	
    LCD_CSH;
}
//--------------写数据-------------------------------------
void TFT_SEND_DATA(uint8_t data)
{
    uint8_t txData[2];
	  txData[0]=data;
	  LCD_CDH;  //数据模式	  
	  LCD_CSL;  //拉低NSS引脚，开始传输
    HAL_SPI_Transmit(&hspi1, txData, 1, HAL_MAX_DELAY);	
    LCD_CSH;
}

//-----------设置显示区域-----------------------------------
void TFT_SET_ADD(unsigned short int x_start,unsigned short int y_start,unsigned short int x_end,unsigned short int y_end)
{
	unsigned short int x = x_start + TFT_COLUMN_OFFSET,y=x_end+ TFT_COLUMN_OFFSET;
    TFT_SEND_CMD(0x2a);     //Column address set
    TFT_SEND_DATA(x>>8);    //start column
    TFT_SEND_DATA(x); 
    TFT_SEND_DATA(y>>8);    //end column
    TFT_SEND_DATA(y);
		x = y_start + TFT_LINE_OFFSET;
		y=y_end+ TFT_LINE_OFFSET;
    TFT_SEND_CMD(0x2b);     //Row address set
    TFT_SEND_DATA(x>>8);    //start row
    TFT_SEND_DATA(x); 
    TFT_SEND_DATA(y>>8);    //end row
    TFT_SEND_DATA(y);
    TFT_SEND_CMD(0x2C);     //Memory write    
}
//------------清屏函数-------------------------------------
void TFT_clear(unsigned int color)
{
    unsigned int i,ROW,column;
    TFT_SET_ADD(0,0,TFT_COLUMN_NUMBER-1,TFT_LINE_NUMBER-1);
    i=0;
		for(ROW=0;ROW<TFT_LINE_NUMBER;ROW++)             //ROW loop
    {     
        for(column=0;column<TFT_COLUMN_NUMBER;column++)  //column loop
        {     
			
					DIS_BUFFER[i++]=color;
        }
    }
		TransmitLargeData(DIS_BUFFER,TFT_COLUMN_NUMBER*TFT_LINE_NUMBER);  
}


//------------LCD 初始化函数-------------------------------
void TFT_init(void)				////ST7789V2
  {
	
	LCD_RST_L;
	HAL_Delay(10);
	LCD_RST_H;
	HAL_Delay(10);
  TFT_SEND_CMD(0x11); 			//Sleep Out
	HAL_Delay(120);               //DELAY120ms 
	 	  //-----------------------ST7789V Frame rate setting-----------------//

  TFT_SEND_CMD(0x3A);        //65k mode
  TFT_SEND_DATA(0x05);
  TFT_SEND_CMD(0xC5); 		//VCOM
  TFT_SEND_DATA(0x1A);
  TFT_SEND_CMD(0x36);                 // 屏幕显示方向设置
  TFT_SEND_DATA(0x00);
  //-------------ST7789V Frame rate setting-----------//
  TFT_SEND_CMD(0xb2);		//Porch Setting
  TFT_SEND_DATA(0x05);
  TFT_SEND_DATA(0x05);
  TFT_SEND_DATA(0x00);
  TFT_SEND_DATA(0x33);
  TFT_SEND_DATA(0x33);

  TFT_SEND_CMD(0xb7);			//Gate Control
  TFT_SEND_DATA(0x05);			//12.2v   -10.43v
  //--------------ST7789V Power setting---------------//
  TFT_SEND_CMD(0xBB);//VCOM
  TFT_SEND_DATA(0x3F);

	TFT_SEND_CMD(0xC0); //Power control
  TFT_SEND_DATA(0x2c);
  TFT_SEND_CMD(0xC2);		//VDV and VRH Command Enable
  TFT_SEND_DATA(0x01);

  TFT_SEND_CMD(0xC3);			//VRH Set
  TFT_SEND_DATA(0x0F);		//4.3+( vcom+vcom offset+vdv)

  TFT_SEND_CMD(0xC4);			//VDV Set
  TFT_SEND_DATA(0x20);				//0v

  TFT_SEND_CMD(0xC6);				//Frame Rate Control in Normal Mode
  TFT_SEND_DATA(0X01);			//111Hz

  TFT_SEND_CMD(0xd0);				//Power Control 1
  TFT_SEND_DATA(0xa4);
  TFT_SEND_DATA(0xa1);

  TFT_SEND_CMD(0xE8);				//Power Control 1
  TFT_SEND_DATA(0x03);

  TFT_SEND_CMD(0xE9);				//Equalize time control
  TFT_SEND_DATA(0x09);
  TFT_SEND_DATA(0x09);
  TFT_SEND_DATA(0x08);
  //---------------ST7789V gamma setting-------------//
  TFT_SEND_CMD(0xE0); //Set Gamma
  TFT_SEND_DATA(0xD0);
  TFT_SEND_DATA(0x05);
  TFT_SEND_DATA(0x09);
  TFT_SEND_DATA(0x09);
  TFT_SEND_DATA(0x08);
  TFT_SEND_DATA(0x14);
  TFT_SEND_DATA(0x28);
  TFT_SEND_DATA(0x33);
  TFT_SEND_DATA(0x3F);
  TFT_SEND_DATA(0x07);
  TFT_SEND_DATA(0x13);
  TFT_SEND_DATA(0x14);
  TFT_SEND_DATA(0x28);
  TFT_SEND_DATA(0x30);
                 
  TFT_SEND_CMD(0XE1); //Set Gamma
  TFT_SEND_DATA(0xD0);
  TFT_SEND_DATA(0x05);
  TFT_SEND_DATA(0x09);
  TFT_SEND_DATA(0x09);
  TFT_SEND_DATA(0x08);
  TFT_SEND_DATA(0x03);
  TFT_SEND_DATA(0x24);
  TFT_SEND_DATA(0x32);
  TFT_SEND_DATA(0x32);
  TFT_SEND_DATA(0x3B);
  TFT_SEND_DATA(0x14);
  TFT_SEND_DATA(0x13);
  TFT_SEND_DATA(0x28);
  TFT_SEND_DATA(0x2F);
  TFT_SEND_CMD(0x21); 		//反显
  
  // 以下进行一些驱动的默认设置
  //LCD_Set_Dir(Dir_V);  	      //	设置显示方向
  TFT_SEND_CMD(0x29);         //开启显示 

}


//-------------SPI LCD 大缓存写显存函数--------------------------------------------------
void TransmitLargeData(uint16_t* data, uint32_t size) {

		LCD_CDH;     // 数据指令选择 引脚输出高电平，代表本次传输 数据	
		LCD_CSL;  //拉低NSS引脚，开始传输
		// 修改为16位数据宽度，写入数据更加效率，不需要拆分	
		hspi1.Init.DataSize 	= SPI_DATASIZE_16BIT;   //	16位数据宽度
		HAL_SPI_Init(&hspi1);	
  
		LCD_SPI_TransmitBuffer(&hspi1,data,size);
		
		LCD_CSH;  //拉低NSS引脚，开始传输
		//修改回8位数据宽度
		hspi1.Init.DataSize 	= SPI_DATASIZE_8BIT;   //	8位数据宽度
		HAL_SPI_Init(&hspi1);	
}

/****************************************************
*
* 以下几个函数修改于HAL的库函数，目的是为了SPI传输数据不限数据长度的写入，并且提高清屏的速度
*
**************************************************************/


/**
  * @brief Handle SPI Communication Timeout.
  * @param hspi: pointer to a SPI_HandleTypeDef structure that contains
  *              the configuration information for SPI module.
  * @param Flag: SPI flag to check
  * @param Status: flag state to check
  * @param Timeout: Timeout duration
  * @param Tickstart: Tick start value
  * @retval HAL status
  */
HAL_StatusTypeDef LCD_SPI_WaitOnFlagUntilTimeout(SPI_HandleTypeDef *hspi, uint32_t Flag, FlagStatus Status,
                                                    uint32_t Tickstart, uint32_t Timeout)
{
   /* Wait until flag is set */
   while ((__HAL_SPI_GET_FLAG(hspi, Flag) ? SET : RESET) == Status)
   {
      /* Check for the Timeout */
      if ((((HAL_GetTick() - Tickstart) >=  Timeout) && (Timeout != HAL_MAX_DELAY)) || (Timeout == 0U))
      {
         return HAL_TIMEOUT;
      }
   }
   return HAL_OK;
}


/**
 * @brief  Close Transfer and clear flags.
 * @param  hspi: pointer to a SPI_HandleTypeDef structure that contains
 *               the configuration information for SPI module.
 * @retval HAL_ERROR: if any error detected
 *         HAL_OK: if nothing detected
 */
 void LCD_SPI_CloseTransfer(SPI_HandleTypeDef *hspi)
{
  uint32_t itflag = hspi->Instance->SR;

  __HAL_SPI_CLEAR_EOTFLAG(hspi);
  __HAL_SPI_CLEAR_TXTFFLAG(hspi);

  /* Disable SPI peripheral */
  __HAL_SPI_DISABLE(hspi);

  /* Disable ITs */
  __HAL_SPI_DISABLE_IT(hspi, (SPI_IT_EOT | SPI_IT_TXP | SPI_IT_RXP | SPI_IT_DXP | SPI_IT_UDR | SPI_IT_OVR | SPI_IT_FRE | SPI_IT_MODF));

  /* Disable Tx DMA Request */
  CLEAR_BIT(hspi->Instance->CFG1, SPI_CFG1_TXDMAEN | SPI_CFG1_RXDMAEN);

  /* Report UnderRun error for non RX Only communication */
  if (hspi->State != HAL_SPI_STATE_BUSY_RX)
  {
    if ((itflag & SPI_FLAG_UDR) != 0UL)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_UDR);
      __HAL_SPI_CLEAR_UDRFLAG(hspi);
    }
  }

  /* Report OverRun error for non TX Only communication */
  if (hspi->State != HAL_SPI_STATE_BUSY_TX)
  {
    if ((itflag & SPI_FLAG_OVR) != 0UL)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_OVR);
      __HAL_SPI_CLEAR_OVRFLAG(hspi);
    }
  }

  /* SPI Mode Fault error interrupt occurred -------------------------------*/
  if ((itflag & SPI_FLAG_MODF) != 0UL)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_MODF);
    __HAL_SPI_CLEAR_MODFFLAG(hspi);
  }

  /* SPI Frame error interrupt occurred ------------------------------------*/
  if ((itflag & SPI_FLAG_FRE) != 0UL)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FRE);
    __HAL_SPI_CLEAR_FREFLAG(hspi);
  }

  hspi->TxXferCount = (uint16_t)0UL;
  hspi->RxXferCount = (uint16_t)0UL;
}

/**
  * @brief  专为屏幕清屏而修改，将需要清屏的颜色批量传输
  * @param  hspi   : spi的句柄
  * @param  pData  : 要写入的数据
  * @param  Size   : 数据大小
  * @retval HAL status
  */

HAL_StatusTypeDef LCD_SPI_Transmit(SPI_HandleTypeDef *hspi,uint16_t pData, uint32_t Size)
{
   uint32_t    tickstart;  
   uint32_t    Timeout = 1000;      // 超时判断
   uint32_t    LCD_pData_32bit;     // 按32位传输时的数据
   uint32_t    LCD_TxDataCount;     // 传输计数
   HAL_StatusTypeDef errorcode = HAL_OK;

	/* Check Direction parameter */
	assert_param(IS_SPI_DIRECTION_2LINES_OR_1LINE_2LINES_TXONLY(hspi->Init.Direction));

	/* Process Locked */
	__HAL_LOCK(hspi);

	/* Init tickstart for timeout management*/
	tickstart = HAL_GetTick();

	if (hspi->State != HAL_SPI_STATE_READY)
	{
		errorcode = HAL_BUSY;
		__HAL_UNLOCK(hspi);
		return errorcode;
	}

	if ( Size == 0UL)
	{
		errorcode = HAL_ERROR;
		__HAL_UNLOCK(hspi);
		return errorcode;
	}

	/* Set the transaction information */
	hspi->State       = HAL_SPI_STATE_BUSY_TX;
	hspi->ErrorCode   = HAL_SPI_ERROR_NONE;

	LCD_TxDataCount   = Size;                // 传输的数据长度
	LCD_pData_32bit   = (pData<<16)|pData ;  // 按32位传输时，合并2个像素点的颜色  

	/*Init field not used in handle to zero */
	hspi->pRxBuffPtr  = NULL;
	hspi->RxXferSize  = (uint16_t) 0UL;
	hspi->RxXferCount = (uint16_t) 0UL;
	hspi->TxISR       = NULL;
	hspi->RxISR       = NULL;

	/* Configure communication direction : 1Line */
	if (hspi->Init.Direction == SPI_DIRECTION_1LINE)
	{
		SPI_1LINE_TX(hspi);
	}

// 不使用硬件 TSIZE 控制，此处设置为0，即不限制传输的数据长度
	MODIFY_REG(hspi->Instance->CR2, SPI_CR2_TSIZE, 0);

	/* Enable SPI peripheral */
	__HAL_SPI_ENABLE(hspi);

	if (hspi->Init.Mode == SPI_MODE_MASTER)
	{
		 /* Master transfer start */
		 SET_BIT(hspi->Instance->CR1, SPI_CR1_CSTART);
	}

	/* Transmit data in 16 Bit mode */
	while (LCD_TxDataCount > 0UL)
	{
		/* Wait until TXP flag is set to send data */
		if (__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_TXP))
		{
			if ((hspi->TxXferCount > 1UL) && (hspi->Init.FifoThreshold > SPI_FIFO_THRESHOLD_01DATA))
			{
				*((__IO uint32_t *)&hspi->Instance->TXDR) = (uint32_t )LCD_pData_32bit;
				LCD_TxDataCount -= (uint16_t)2UL;
			}
			else
			{
				*((__IO uint16_t *)&hspi->Instance->TXDR) =  (uint16_t )pData;
				LCD_TxDataCount--;
			}
		}
		else
		{
			/* Timeout management */
			if ((((HAL_GetTick() - tickstart) >=  Timeout) && (Timeout != HAL_MAX_DELAY)) || (Timeout == 0U))
			{
				/* Call standard close procedure with error check */
				LCD_SPI_CloseTransfer(hspi);

				/* Process Unlocked */
				__HAL_UNLOCK(hspi);

				SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_TIMEOUT);
				hspi->State = HAL_SPI_STATE_READY;
				return HAL_ERROR;
			}
		}
	}

	if (LCD_SPI_WaitOnFlagUntilTimeout(hspi, SPI_SR_TXC, RESET, tickstart, Timeout) != HAL_OK)
	{
		SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
	}

	SET_BIT((hspi)->Instance->CR1 , SPI_CR1_CSUSP); // 请求挂起SPI传输
	/* 等待SPI挂起 */
	if (LCD_SPI_WaitOnFlagUntilTimeout(hspi, SPI_FLAG_SUSP, RESET, tickstart, Timeout) != HAL_OK)
	{
		SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
	}
	LCD_SPI_CloseTransfer(hspi);   /* Call standard close procedure with error check */

	SET_BIT((hspi)->Instance->IFCR , SPI_IFCR_SUSPC);  // 清除挂起标志位


	/* Process Unlocked */
	__HAL_UNLOCK(hspi);

	hspi->State = HAL_SPI_STATE_READY;

	if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
	{
		return HAL_ERROR;
	}
	return errorcode;
}
/**
  * @brief  专为批量写入数据修改，使之不限长度的传输数据
  * @param  hspi   : spi的句柄
  * @param  pData  : 要写入的数据
  * @param  Size   : 数据大小
  * @retval HAL status
  */
HAL_StatusTypeDef LCD_SPI_TransmitBuffer (SPI_HandleTypeDef *hspi, uint16_t *pData, uint32_t Size)
{
   uint32_t    tickstart;  
   uint32_t    Timeout = 1000;      // 超时判断
   uint32_t    LCD_TxDataCount;     // 传输计数
   HAL_StatusTypeDef errorcode = HAL_OK;

	/* Check Direction parameter */
	assert_param(IS_SPI_DIRECTION_2LINES_OR_1LINE_2LINES_TXONLY(hspi->Init.Direction));

	/* Process Locked */
	__HAL_LOCK(hspi);

	/* Init tickstart for timeout management*/
	tickstart = HAL_GetTick();

	if (hspi->State != HAL_SPI_STATE_READY)
	{
		errorcode = HAL_BUSY;
		__HAL_UNLOCK(hspi);
		return errorcode;
	}

	if ( Size == 0UL)
	{
		errorcode = HAL_ERROR;
		__HAL_UNLOCK(hspi);
		return errorcode;
	}

	/* Set the transaction information */
	hspi->State       = HAL_SPI_STATE_BUSY_TX;
	hspi->ErrorCode   = HAL_SPI_ERROR_NONE;

	LCD_TxDataCount   = Size;                // 传输的数据长度

	/*Init field not used in handle to zero */
	hspi->pRxBuffPtr  = NULL;
	hspi->RxXferSize  = (uint16_t) 0UL;
	hspi->RxXferCount = (uint16_t) 0UL;
	hspi->TxISR       = NULL;
	hspi->RxISR       = NULL;

	/* Configure communication direction : 1Line */
	if (hspi->Init.Direction == SPI_DIRECTION_1LINE)
	{
		SPI_1LINE_TX(hspi);
	}

// 不使用硬件 TSIZE 控制，此处设置为0，即不限制传输的数据长度
	MODIFY_REG(hspi->Instance->CR2, SPI_CR2_TSIZE, 0);

	/* Enable SPI peripheral */
	__HAL_SPI_ENABLE(hspi);

	if (hspi->Init.Mode == SPI_MODE_MASTER)
	{
		 /* Master transfer start */
		 SET_BIT(hspi->Instance->CR1, SPI_CR1_CSTART);
	}

	/* Transmit data in 16 Bit mode */
	while (LCD_TxDataCount > 0UL)
	{
		/* Wait until TXP flag is set to send data */
		if (__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_TXP))
		{
			if ((LCD_TxDataCount > 1UL) && (hspi->Init.FifoThreshold > SPI_FIFO_THRESHOLD_01DATA))
			{
				*((__IO uint32_t *)&hspi->Instance->TXDR) = *((uint32_t *)pData);
				pData += 2;
				LCD_TxDataCount -= 2;
			}
			else
			{
				*((__IO uint16_t *)&hspi->Instance->TXDR) = *((uint16_t *)pData);
				pData += 1;
				LCD_TxDataCount--;
			}
		}
		else
		{
			/* Timeout management */
			if ((((HAL_GetTick() - tickstart) >=  Timeout) && (Timeout != HAL_MAX_DELAY)) || (Timeout == 0U))
			{
				/* Call standard close procedure with error check */
				LCD_SPI_CloseTransfer(hspi);

				/* Process Unlocked */
				__HAL_UNLOCK(hspi);

				SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_TIMEOUT);
				hspi->State = HAL_SPI_STATE_READY;
				return HAL_ERROR;
			}
		}
	}

	if (LCD_SPI_WaitOnFlagUntilTimeout(hspi, SPI_SR_TXC, RESET, tickstart, Timeout) != HAL_OK)
	{
		SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
	}

	SET_BIT((hspi)->Instance->CR1 , SPI_CR1_CSUSP); // 请求挂起SPI传输
	/* 等待SPI挂起 */
	if (LCD_SPI_WaitOnFlagUntilTimeout(hspi, SPI_FLAG_SUSP, RESET, tickstart, Timeout) != HAL_OK)
	{
		SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
	}
	LCD_SPI_CloseTransfer(hspi);   /* Call standard close procedure with error check */

	SET_BIT((hspi)->Instance->IFCR , SPI_IFCR_SUSPC);  // 清除挂起标志位


	/* Process Unlocked */
	__HAL_UNLOCK(hspi);

	hspi->State = HAL_SPI_STATE_READY;

	if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
	{
		return HAL_ERROR;
	}
	return errorcode;
}
//----------------------------END
