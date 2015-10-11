/**
  ******************************************************************************
  * @file    stnucleof411re_definitions.h
  * @date    10-October-2015
  * @brief   Definitions for the ST-Nucleo-F411RE board
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

#ifndef STNUCLEOF411RE_DEFINITIONS_H_
#define STNUCLEOF411RE_DEFINITIONS_H_


#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

#include "stm32f411xe.h"

#define PIN_D0  { GPIOA, GPIO_PIN_3  }
#define PIN_D1  { GPIOA, GPIO_PIN_2  }
#define PIN_D2  { GPIOA, GPIO_PIN_10 }
#define PIN_D3  { GPIOB, GPIO_PIN_3  }
#define PIN_D4  { GPIOB, GPIO_PIN_5  }
#define PIN_D5  { GPIOB, GPIO_PIN_4  }
#define PIN_D6  { GPIOB, GPIO_PIN_10 }
#define PIN_D7  { GPIOA, GPIO_PIN_8  }
#define PIN_D8  { GPIOA, GPIO_PIN_9  }
#define PIN_D9  { GPIOC, GPIO_PIN_7  }
#define PIN_D10 { GPIOB, GPIO_PIN_6  }
#define PIN_D11 { GPIOA, GPIO_PIN_7  }
#define PIN_D12 { GPIOA, GPIO_PIN_6  }
#define PIN_D13 { GPIOA, GPIO_PIN_5  }
#define PIN_D14 { GPIOB, GPIO_PIN_9  }
#define PIN_D15 { GPIOB, GPIO_PIN_8  }
#define PIN_A0  { GPIOA, GPIO_PIN_0  }
#define PIN_A1  { GPIOA, GPIO_PIN_1  }
#define PIN_A2  { GPIOA, GPIO_PIN_4  }
#define PIN_A3  { GPIOB, GPIO_PIN_0  }
#define PIN_A4  { GPIOC, GPIO_PIN_1  }
#define PIN_A5  { GPIOC, GPIO_PIN_0  }

#define UART_TX_PORT GPIOA
#define UART_TX_PIN  GPIO_PIN_2

#endif /* STNUCLEOF411RE_DEFINITIONS_H_ */
