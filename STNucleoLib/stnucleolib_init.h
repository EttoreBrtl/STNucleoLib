/**
  ******************************************************************************
  * @file    stnucleolib_init.h
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

#ifndef STNUCLEOLIB_STNUCLEOLIB_INIT_H_
#define STNUCLEOLIB_STNUCLEOLIB_INIT_H_

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
extern void localStnucleoInit(void);

#endif /* STNUCLEOLIB_STNUCLEOLIB_INIT_H_ */
