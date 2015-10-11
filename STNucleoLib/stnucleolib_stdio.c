/**
  ******************************************************************************
  * @file    stnucleolib_stdio.c
  * @date    10-October-2015
  * @brief   STNucleoLib module that handles semihosting/UART prints
  ******************************************************************************
  * @attention
  *
  * Copyright (C) 2015 Ettore Barattelli
  *
  * This file is part of STNucleoLib.
  *
  * STNucleoLib is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * STNucleoLib is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with STNucleoLib.  If not, see <http://www.gnu.org/licenses/>.
  *
  *******************************************************************************/

#include <stdio.h>

#include "stnucleof411re_definitions.h"
#include "stnucleolib_stdio.h"
#include "stnucleolib_it.h"

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

#define UART_INSTANCE     USART2
#define UART_BAUD_RATE    115200U
#define UART_WORD_LENGTH  UART_WORDLENGTH_8B
#define UART_STOP_BITS    UART_STOPBITS_1
#define UART_PARITY       UART_PARITY_NONE
#define UART_HWCONTROL    UART_HWCONTROL_NONE
#define UART_MODE         UART_MODE_TX

/*! UART peripheral descriptor */
static UART_HandleTypeDef huart2;

/**
 * @brief Function to initialize the UART peripheral.
 *        Called by the init module at startup
 * @param None
 * @return None
 */
void localStnucleoStdioInit(void)
{
    /* Set UART configuration parameters */
    huart2.Instance        = UART_INSTANCE;
    huart2.Init.BaudRate   = UART_BAUD_RATE;
    huart2.Init.WordLength = UART_WORD_LENGTH;
    huart2.Init.StopBits   = UART_STOP_BITS;
    huart2.Init.Parity     = UART_PARITY;
    huart2.Init.HwFlowCtl  = UART_HWCONTROL;
    huart2.Init.Mode       = UART_MODE;

    /* Initialize peripheral */
    if(HAL_UART_Init(&huart2) != HAL_OK)
    {
      /* Initialization Error */
      Error_Handler();
    }

    /* Disable stdout buffering so that printf sends data immediately */
    setvbuf(stdout, NULL, _IONBF, 0);
}

/*!
 * @brief Function to print a string on the serial line
 *
 * @param[in] format printf-like format string
 * @param[in] va_args Other printf-like parameters
 * @return None
 */
void localSerialPrintf(const char *fmt, va_list ap)
{
    /* Forward the '...' to vprintf */
    vprintf(fmt, ap);
}

/**
 * @brief Hook function called by the HAL UART init function.
 *        Used to configure the UART pins
 * @param[in] huart UART peripheral descriptor
 * @return None
 */
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  if(huart->Instance==USART2)
  {
      /* Enable clocks */
    __GPIOA_CLK_ENABLE();
    __USART2_CLK_ENABLE();

    /* Configure pin for UART TX */
    GPIO_InitStruct.Pin = UART_TX_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(UART_TX_PORT, &GPIO_InitStruct);
  }
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval ch transmitted character
  */
PUTCHAR_PROTOTYPE
{
  /* Transmit the character */
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}
