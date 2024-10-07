/*
 * ap.h
 *
 *  Created on: Sep 13, 2024
 *      Author: OMG
 */

#ifndef AP_H_
#define AP_H_

#include "hw.h"
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"
#include "usart.h"

// Include Header File
#include "hw.h"
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"
#include "usart.h"

// Function Prototype
void control_motor();
void control_IN_Value(uint8_t forward_reverse, uint8_t left_right, uint8_t change_dir_enable);
void enter_IN_values();
void check_duty_of_motor (uint8_t* p_left_duty, uint8_t* p_right_duty);
void apInit();
void apMain();

// Declare Port
#define IN1_PORT GPIOA
#define IN2_PORT GPIOA
#define IN3_PORT GPIOA
#define IN4_PORT GPIOB

#define PWM_LEFT_PORT GPIOA
#define PWM_RIGHT_PORT GPIOC

// Declare Pin
#define IN1_PIN		GPIO_PIN_5
#define IN2_PIN		GPIO_PIN_6
#define IN3_PIN		GPIO_PIN_7
#define IN4_PIN		GPIO_PIN_6


#endif /* AP_H_ */
