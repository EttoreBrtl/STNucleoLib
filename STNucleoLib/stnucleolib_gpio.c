/**
  ******************************************************************************
  * @file    stnucleolib_gpio.c
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

#include "stnucleolib_gpio.h"

/*! STM32 GPIO description struct */
typedef struct
{
    GPIO_TypeDef *port;  /*!< STM32 GPIO port */
    uint16_t      pin;   /*!< GPIO pin number */
} STM32Pin_t;

/*! Table that maps Arduino connector pins to STM32 pins.
 *  The symbols are defined in the platform specific definitions file
 */
static const STM32Pin_t _arduinoPinTable[] =
{
    PIN_D0,
    PIN_D1,
    PIN_D2,
    PIN_D3,
    PIN_D4,
    PIN_D5,
    PIN_D6,
    PIN_D7,
    PIN_D8,
    PIN_D9,
    PIN_D10,
    PIN_D11,
    PIN_D12,
    PIN_D13,
    PIN_D14,
    PIN_D15,
    PIN_A0,
    PIN_A1,
    PIN_A2,
    PIN_A3,
    PIN_A4,
    PIN_A5,
};

/*!
 * @brief Function to set the pin direction of an Arduino connector pin.
 *
 * @param[in] pin Arduino connector pin to configure
 * @param[in] mode Pin direction
 * @return None
 */
void localPinMode(const STNucleoArduinoPin_t pin, const STNucleoPinMode_t mode)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Configure pin */
    GPIO_InitStructure.Pin = _arduinoPinTable[pin].pin;
    GPIO_InitStructure.Mode = mode;
    GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(_arduinoPinTable[pin].port, &GPIO_InitStructure);
}

/*!
 * @brief Function to set the logic state of an Arduino connector pin.
 *
 * @param[in] pin Arduino connector pin to write
 * @param[in] state Pin logic state
 * @return None
 */
void localDigitalWrite(const STNucleoArduinoPin_t pin, const STNucleoPinState_t state)
{
    /* Write the GPIO pin */
    HAL_GPIO_WritePin(_arduinoPinTable[pin].port,
            _arduinoPinTable[pin].pin, state);
}

/*!
 * @brief Function to set the logic state of an Arduino connector pin.
 *
 * @param[in] pin Arduino connector pin to read
 * @return state Pin logic state
 */
STNucleoPinState_t localDigitalRead(const STNucleoArduinoPin_t pin)
{
    /* Read the GPIO pin */
    const STNucleoPinState_t retval = (STNucleoPinState_t) (HAL_GPIO_ReadPin(_arduinoPinTable[pin].port,
            _arduinoPinTable[pin].pin));

    return (retval);
}
