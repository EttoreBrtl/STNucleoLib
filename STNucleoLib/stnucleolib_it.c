/**
  ******************************************************************************
  * @file    stnucleolib_it.c
  * @date    10-October-2015
  * @brief   STNucleoLib module that handles main interrupts and errors
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


#include "stnucleolib_it.h"
#include "stnucleolib_time.h"


/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  while(1)
  {
  }
}

/**
  * @brief  This function is the SysTick interrupt handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
    /* Call the SysTick handler in the time module */
    localSysTick_Handler();
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param[in] file pointer to the source file name
  * @param[in] line assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
    /*TODO: add error reporting */

    /* Infinite loop */
    while (1)
    {
    }
}
#endif

