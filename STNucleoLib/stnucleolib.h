/**
  ******************************************************************************
  * @file    stnucleolib.h
  * @date    10-October-2015
  * @brief   This is the main STNucleoLib include file to access the
  *          API functions
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

#ifndef STNUCLEOLIB_H_
#define STNUCLEOLIB_H_

#include "stnucleof411re_definitions.h"
#include "stm32f4xx_hal_gpio.h"

/*! Pin logic state enumerator */
typedef enum
{
    LOW  = GPIO_PIN_RESET, /*!< LOW (0) state */
    HIGH = GPIO_PIN_SET    /*!< HIGH (1) state */
} STNucleoPinState_t;

/*! Pin direction enumerator */
typedef enum
{
    INPUT  = GPIO_MODE_INPUT,     /*!< INPUT pin direction */
    OUTPUT = GPIO_MODE_OUTPUT_PP  /*!< OUTPUT pin direction */
} STNucleoPinMode_t;

/*! Arduino connector pin enumerator */
typedef enum
{
    D0,  /*!< Arduino connector pin D0 */
    D1,  /*!< Arduino connector pin D1 */
    D2,  /*!< Arduino connector pin D2 */
    D3,  /*!< Arduino connector pin D3 */
    D4,  /*!< Arduino connector pin D4 */
    D5,  /*!< Arduino connector pin D5 */
    D6,  /*!< Arduino connector pin D6 */
    D7,  /*!< Arduino connector pin D7 */
    D8,  /*!< Arduino connector pin D8 */
    D9,  /*!< Arduino connector pin D9 */
    D10, /*!< Arduino connector pin D10 */
    D11, /*!< Arduino connector pin D11 */
    D12, /*!< Arduino connector pin D12 */
    D13, /*!< Arduino connector pin D13 */
    D14, /*!< Arduino connector pin D14 */
    D15, /*!< Arduino connector pin D15 */
    A0,  /*!< Arduino connector pin A0 */
    A1,  /*!< Arduino connector pin A1 */
    A2,  /*!< Arduino connector pin A2 */
    A3,  /*!< Arduino connector pin A3 */
    A4,  /*!< Arduino connector pin A4 */
    A5   /*!< Arduino connector pin A5 */
} STNucleoArduinoPin_t;

/*!
 * @brief Function to initialize the STNucleoLib library.
 *
 * This function initializes the STNucleoLib library.
 * This should be the first function called by main.
 * It initializes the system clock and the required peripherals
 *
 * @param None
 * @return None
 */
extern void stnucleoInit(void);

/*!
 * @brief Function to set the pin direction of an Arduino connector pin.
 *
 * @param[in] pin Arduino connector pin to configure
 * @param[in] mode Pin direction
 * @return None
 */
extern void pinMode(const STNucleoArduinoPin_t pin, const STNucleoPinMode_t mode);

/*!
 * @brief Function to set the logic state of an Arduino connector pin.
 *
 * @param[in] pin Arduino connector pin to write
 * @param[in] state Pin logic state
 * @return None
 */
extern void digitalWrite(const STNucleoArduinoPin_t pin, const STNucleoPinState_t state);

/*!
 * @brief Function to set the logic state of an Arduino connector pin.
 *
 * @param[in] pin Arduino connector pin to read
 * @return state Pin logic state
 */
extern STNucleoPinState_t digitalRead(const STNucleoArduinoPin_t pin);

/*!
 * @brief Function to wait for a given time (in milliseconds)
 *
 * @param[in] ms Milliseconds to wait
 * @return None
 */
extern void delay(const uint64_t ms);

/*!
 * @brief Function to get the number of milliseconds elapsed since system start
 *
 * @param None
 * @return ms Milliseconds elapsed since system start
 */
extern uint64_t millis(void);

/*!
 * @brief Function to print a string on the serial line
 *
 * @param[in] format printf-like format string
 * @param[in] va_args Other printf-like parameters
 * @return None
 */
extern void serialPrint(const char *format, ...);

#endif /* STNUCLEOLIB_H_ */
