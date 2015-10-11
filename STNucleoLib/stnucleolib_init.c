/**
  ******************************************************************************
  * @file    stnucleolib_init.c
  * @date    10-October-2015
  * @brief   STNucleoLib module that handles clock and peripheral initialization
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

#include "stnucleof411re_definitions.h"
#include "stnucleolib_time.h"
#include "stnucleolib_stdio.h"

/**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
static void _systemClock_Config(void);

/*!
 * @brief Function to initialize the STNucleoLib library.
 *
 * This function initializes the STNucleoLib library.
 * This should be the first function called by main (via the API stnucleoInit).
 * It initializes the system clock and the required peripherals
 *
 * @param None
 * @return None
 */
void localStnucleoInit(void)
{
    /* Initialize the HAL */
    HAL_Init();

    /* Configure the system clock to 100 MHz */
    _systemClock_Config();

    /* Enable GPIO Peripheral clocks for port A,B,C */
    RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN);

    /* Initialize the time module */
    localStnucleoTimeInit();

    /* Initialize the STDIO module */
    localStnucleoStdioInit();
}

/**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
static void _systemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __PWR_CLK_ENABLE();

  /* Voltage scaling settings */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Configure oscillator: HSI source, 100MHz */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 400;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /* Configure system clock: use PLL clock, set dividers, use 2 and Flash latency */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);
}

