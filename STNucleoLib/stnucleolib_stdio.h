/**
  ******************************************************************************
  * @file    stnucleolib_stdio.h
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

#ifndef STNUCLEOLIB_STNUCLEOLIB_STDIO_H_
#define STNUCLEOLIB_STNUCLEOLIB_STDIO_H_

#include <stdarg.h>

/**
 * @brief Function to initialize the UART peripheral.
 *        Called by the init module at startup
 * @param None
 * @return None
 */
extern void localStnucleoStdioInit(void);

/*!
 * @brief Function to print a string on the serial line
 *
 * @param[in] format printf-like format string
 * @param[in] va_args Other printf-like parameters
 * @return None
 */
extern void localSerialPrintf(const char *format, va_list ap);

#endif /* STNUCLEOLIB_STNUCLEOLIB_STDIO_H_ */
