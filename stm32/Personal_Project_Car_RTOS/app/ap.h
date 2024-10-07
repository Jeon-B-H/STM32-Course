/*
 * ap.h
 *
 *  Created on: Sep 13, 2024
 *      Author: OMG
 */

#ifndef AP_H_
#define AP_H_

// Include Header File
#include "hw.h"
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"
#include "usart.h"
#include "motor.h"

// Function Prototype
void apInit();
void apMain();

#endif /* AP_H_ */
