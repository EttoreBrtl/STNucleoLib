/**
  ******************************************************************************
  * @file    main.c
  * @date    10-October-2015
  * @brief   Simple STNucleoLib test
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

#include <stdio.h>
#include <stdlib.h>

/* Include semihosting; this is to explicitly test SH */
#include "semihosting/Trace.h"

/* Include STNucleoLib */
#include "stnucleolib.h"

/* Delay time for this test */
#define DELAY_TIME 500U

/**
 * This is a simple test that configures some pins and prints
 * some messages on the Serial and Semihosting lines
 */
void main(void)
{
    /* Seconds elapsed since start */
    uint32_t seconds = 0;

    /* State of pin D10 */
    STNucleoPinState_t d10State;

    /* Initialize System --- This must be the first function called */
    stnucleoInit();

#ifdef TRACE
    /* At this stage the system clock should have already been configured
     * at high speed.
     */
    trace_printf("System clock: %u Hz\n", SystemCoreClock);
#endif

    /* Set pin modes. D10 set to input, all others as output
     * WARNING: pins D0 and D1 are configured for UART, if you call
     * pinMode on D0 and D1, serialPrint will not work.
     * On the STNucleo board pins D0 and D1 are disconnected by default
     */
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
    pinMode(D5, OUTPUT);
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);
    pinMode(D8, OUTPUT);
    pinMode(D9, OUTPUT);
    pinMode(D10, INPUT);
    pinMode(D11, OUTPUT);
    pinMode(D12, OUTPUT);
    pinMode(D13, OUTPUT);
    pinMode(D14, OUTPUT);
    pinMode(D15, OUTPUT);

    /* Main loop */
    while (1)
    {
        /* Set all pins to low and read D10 */
        digitalWrite(D2, LOW);
        digitalWrite(D3, LOW);
        digitalWrite(D4, LOW);
        digitalWrite(D5, LOW);
        digitalWrite(D6, LOW);
        digitalWrite(D7, LOW);
        digitalWrite(D8, LOW);
        digitalWrite(D9, LOW);
        d10State = digitalRead(D10);
        digitalWrite(D11, LOW);
        digitalWrite(D12, LOW);
        digitalWrite(D13, LOW);
        digitalWrite(D14, LOW);
        digitalWrite(D15, LOW);

        /* Print state of D10 on the serial line */
        serialPrint("D10 State: %u\r\n", d10State);

        /* Wait some time */
        delay(DELAY_TIME);

        /* Set all pins to high and read D10 */
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH);
        digitalWrite(D5, HIGH);
        digitalWrite(D6, HIGH);
        digitalWrite(D7, HIGH);
        digitalWrite(D8, HIGH);
        digitalWrite(D9, HIGH);
        d10State = digitalRead(D10);
        digitalWrite(D11, HIGH);
        digitalWrite(D12, HIGH);
        digitalWrite(D13, HIGH);
        digitalWrite(D14, HIGH);
        digitalWrite(D15, HIGH);

        /* Print state of D10 on the serial line */
        serialPrint("D10 State: %u\r\n", d10State);

        /* Wait some time */
        delay(DELAY_TIME);

        /* Get number of seconds since start */
        seconds = millis() / 1000U;

#ifdef TRACE
        /* Print the number of seconds on semihosting channel */
        trace_printf("Second %u\n", seconds);
#endif
    }
    /* I got here! Wait... what?? */
}

