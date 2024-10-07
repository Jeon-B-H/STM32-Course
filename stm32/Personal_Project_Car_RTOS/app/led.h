/*
 * led.h
 *
 *  Created on: Sep 28, 2024
 *      Author: OMG
 */

#ifndef LED_H_
#define LED_H_

// Include header file
#include "hw.h"
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"
#include "usart.h"

// Global variables
extern uint8_t receive_data[1];

// Define Constants
#define LEFT_LED_PORT 	GPIOB
#define RIGHT_LED_PORT 	GPIOB

#define LEFT_LED_PIN    GPIO_PIN_3
#define RIGHT_LED_PIN	GPIO_PIN_13

// Define Function prototype
void control_led();

#endif /* LED_H_ */
