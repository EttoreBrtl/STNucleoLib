/**
  ******************************************************************************
  * @file    stnucleolib_time.h
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

#ifndef STNUCLEOLIB_STNUCLEOLIB_TIME_H_
#define STNUCLEOLIB_STNUCLEOLIB_TIME_H_

/**
 * @brief Function to initialize the system ticks
 * @param None
 * @return None
 */
extern void localStnucleoTimeInit(void);

/*!
 * @brief Function to wait for a given time (in milliseconds)
 *
 * @param[in] ms Milliseconds to wait
 * @return None
 */
extern void localDelay(const uint64_t ms);

/*!
 * @brief Function to get the number of milliseconds elapsed since system start
 *
 * @param None
 * @return ms Milliseconds elapsed since system start
 */
extern uint64_t localMillis(void);

/**
  * @brief  This function is the SysTick interrupt handler.
  * @param  None
  * @retval None
  */
extern void localSysTick_Handler(void);

#endif /* STNUCLEOLIB_STNUCLEOLIB_TIME_H_ */
