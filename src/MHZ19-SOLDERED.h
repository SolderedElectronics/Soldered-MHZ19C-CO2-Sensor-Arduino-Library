/**
 **************************************************
 *
 * @file        MHZ19-SOLDERED.h
 * @brief       Header file for sensor specific code.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Zvonimir Haramustek for soldered.com
 ***************************************************/

#ifndef __MHZ19_SOLDERED__
#define __MHZ19_SOLDERED__

#ifdef __AVR__
#include <SoftwareSerial.h>
#else
#include "libs/espsoftwareserial/src/SoftwareSerial.h"
#endif

#include "libs/MHZ19/MHZ19.h"
#include "libs/MHZ19/MHZ19PWM.h"

#endif
