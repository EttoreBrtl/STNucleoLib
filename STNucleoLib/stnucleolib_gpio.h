/**
  ******************************************************************************
  * @file    stnucleolib_gpio.h
  * @date    10-October-2015
  * @brief   STNucleoLib module that handles GPIOs
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

#ifndef STNUCLEOLIB_STNUCLEOLIB_GPIO_H_
#define STNUCLEOLIB_STNUCLEOLIB_GPIO_H_

#include "stnucleolib.h"

/*!
 * @brief Function to set the pin direction of an Arduino connector pin.
 *
 * @param[in] pin Arduino connector pin to configure
 * @param[in] mode Pin direction
 * @return None
 */
extern void localPinMode(const STNucleoArduinoPin_t pin, const STNucleoPinMode_t mode);

/*!
 * @brief Function to set the logic state of an Arduino connector pin.
 *
 * @param[in] pin Arduino connector pin to write
 * @param[in] state Pin logic state
 * @return None
 */
extern void localDigitalWrite(const STNucleoArduinoPin_t pin, const STNucleoPinState_t state);

/*!
 * @brief Function to set the logic state of an Arduino connector pin.
 *
 * @param[in] pin Arduino connector pin to read
 * @return state Pin logic state
 */
extern STNucleoPinState_t localDigitalRead(const STNucleoArduinoPin_t pin);

#endif /* STNUCLEOLIB_STNUCLEOLIB_GPIO_H_ */
