/**
  ******************************************************************************
  * @file    stnucleolib_time.c
  * @date    10-October-2015
  * @brief   STNucleoLib module that handles the time functions
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

/* System tick period: 1 ms */
#define TICK_FREQUENCY_HZ 1000U

/*! Current system ticks */
static volatile uint64_t _currTicks = 0;

/**
 * @brief Function to initialize the system ticks
 * @param None
 * @return None
 */
void localStnucleoTimeInit(void)
{
    /* Configure SysTick period */
    SysTick_Config (SystemCoreClock / TICK_FREQUENCY_HZ);
}

/*!
 * @brief Function to wait for a given time (in milliseconds)
 *
 * @param[in] ms Milliseconds to wait
 * @return None
 */
void localDelay(const uint64_t ms)
{
    /* Get end time */
    const uint64_t endTime = _currTicks + ms;

    /* Busy wait until the wait time has elapsed */
    while (endTime > _currTicks);
}

/*!
 * @brief Function to get the number of milliseconds elapsed since system start
 *
 * @param None
 * @return ms Milliseconds elapsed since system start
 */
uint64_t localMillis(void)
{
    return (_currTicks);
}

/**
  * @brief  This function is the SysTick interrupt handler.
  * @param  None
  * @retval None
  */
void localSysTick_Handler(void)
{
    /* Increment ticks */
    HAL_IncTick();
    _currTicks++;
}
