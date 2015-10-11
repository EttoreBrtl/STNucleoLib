/**
  ******************************************************************************
  * @file    stnucleolib.c
  * @date    10-October-2015
  * @brief   This is the implementation of the STNucleoLib API.
  *          It mostly consists of API function wrappers that call the
  *          specific STNucleoLib modules
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

#include <stdint.h>
#include "stnucleolib.h"

#include "stnucleolib_gpio.h"
#include "stnucleolib_init.h"
#include "stnucleolib_stdio.h"
#include "stnucleolib_time.h"

#if defined(STNUCLEOLIB_PRINT_SEMIHOSTING) && defined(TRACE)

#include <stdio.h>
#include "semihosting/Trace.h"
#include "string.h"

#ifndef OS_INTEGER_TRACE_PRINTF_TMP_ARRAY_SIZE
#define OS_INTEGER_TRACE_PRINTF_TMP_ARRAY_SIZE (128)
#endif

#endif

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
void stnucleoInit(void)
{
    localStnucleoInit();
}

/*!
 * @brief Function to set the pin direction of an Arduino connector pin.
 *
 * @param[in] pin Arduino connector pin to configure
 * @param[in] mode Pin direction
 * @return None
 */
void pinMode(const STNucleoArduinoPin_t pin, const STNucleoPinMode_t mode)
{
    localPinMode(pin, mode);
}

/*!
 * @brief Function to set the logic state of an Arduino connector pin.
 *
 * @param[in] pin Arduino connector pin to write
 * @param[in] state Pin logic state
 * @return None
 */
void digitalWrite(const STNucleoArduinoPin_t pin, const STNucleoPinState_t state)
{
    localDigitalWrite(pin, state);
}

/*!
 * @brief Function to set the logic state of an Arduino connector pin.
 *
 * @param[in] pin Arduino connector pin to read
 * @return state Pin logic state
 */
STNucleoPinState_t digitalRead(const STNucleoArduinoPin_t pin)
{
    const STNucleoPinState_t retval = localDigitalRead(pin);

    return (retval);
}

/*!
 * @brief Function to wait for a given time (in milliseconds)
 *
 * @param[in] ms Milliseconds to wait
 * @return None
 */
void delay(const uint64_t ms)
{
    localDelay(ms);
}

/*!
 * @brief Function to get the number of milliseconds elapsed since system start
 *
 * @param None
 * @return ms Milliseconds elapsed since system start
 */
uint64_t millis(void)
{
    return (localMillis());
}

/*!
 * @brief Function to print a string on the serial line
 *
 * @param[in] format printf-like format string
 * @param[in] va_args Other printf-like parameters
 * @return None
 */
void serialPrint(const char *format, ...)
{
    va_list ap;

    va_start (ap, format);

#if defined(STNUCLEOLIB_PRINT_SEMIHOSTING) && defined(TRACE)
    static char buf[OS_INTEGER_TRACE_PRINTF_TMP_ARRAY_SIZE];
    int ret = 0;
    // Print to the local buffer
    ret = vsnprintf (buf, sizeof(buf), format, ap);
    if (ret > 0)
    {
        // Transfer the buffer to the device
        trace_write (buf, (size_t)ret);
    }
#else
    localSerialPrintf(format, ap);
#endif

    va_end (ap);
}
