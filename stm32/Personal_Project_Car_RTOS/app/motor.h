/*
 * motor.h
 *
 *  Created on: Sep 27, 2024
 *      Author: OMG
 */

#ifndef MOTOR_H_
#define MOTOR_H_

// Include Header File
#include "hw.h"
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"
#include "usart.h"

// Global Variables
extern uint8_t receive_data[1];

// Declare Function prototype
void control_motor();
void control_IN_Value(uint8_t forward_reverse, uint8_t left_right, uint8_t change_dir_enable);
void enter_IN_values();

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

#endif /* MOTOR_H_ */
