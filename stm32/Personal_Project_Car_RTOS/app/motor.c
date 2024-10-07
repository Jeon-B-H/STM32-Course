#include "motor.h"

static uint8_t IN1_Value = 0;
static uint8_t IN2_Value = 0;
static uint8_t IN3_Value = 0;
static uint8_t IN4_Value = 0;


// Control Motor Function
void control_motor() {
	uint8_t left_duty = 0, right_duty = 0;

	while(1) {
		switch(receive_data[0]) {
		case 'E':
			left_duty = 0;
			right_duty = 0;
			control_IN_Value(1, 0, 0);
			break;
		case 'B':
			left_duty = 100;
			right_duty = 100;
			control_IN_Value(1, 0, 0);
			break;
		case 'H':
			left_duty = 100;
			right_duty = 100;
			control_IN_Value(0, 0, 0);
			break;
		case 'D':
			left_duty = 100;
			right_duty = 100;
			control_IN_Value(0, 1, 1);
			break;
		case 'F':
			left_duty = 100;
			right_duty = 100;
			control_IN_Value(0, 0, 1);
			break;
		case 'A':
			left_duty = 100;
			right_duty = 10;
			control_IN_Value(1, 0, 0);
			break;
		case 'C':
			left_duty = 10;
			right_duty = 100;
			control_IN_Value(1, 0, 0);
			break;
		case 'G':
			left_duty = 100;
			right_duty = 10;
			control_IN_Value(0, 0, 0);
			break;
		case 'I':
			left_duty = 10;
			right_duty = 100;
			control_IN_Value(0, 0, 0);
			break;
		}

		// Enter values to the input variables.
		enter_IN_values();

		//Drive the motors by sending duty values to each motor.
		TIM1->CCR2 = left_duty;
		TIM3->CCR2 = right_duty;
	}
}


//// Direction Control Function
void control_IN_Value(uint8_t forward_reverse, uint8_t left_right, uint8_t change_dir_enable) {
	if(forward_reverse) {
		// Control Left
		IN1_Value = GPIO_PIN_SET;
		IN2_Value = GPIO_PIN_RESET;
		IN3_Value = GPIO_PIN_SET;
		IN4_Value = GPIO_PIN_RESET;
	}else if(!forward_reverse) {
		IN1_Value = GPIO_PIN_RESET;
		IN2_Value = GPIO_PIN_SET;
		IN3_Value = GPIO_PIN_RESET;
		IN4_Value = GPIO_PIN_SET;
	}

	if(change_dir_enable) {
		if(left_right) {
			IN1_Value = GPIO_PIN_RESET;
			IN2_Value = GPIO_PIN_SET;
			IN3_Value = GPIO_PIN_SET;
			IN4_Value = GPIO_PIN_RESET;
		}else {
			IN1_Value = GPIO_PIN_SET;
			IN2_Value = GPIO_PIN_RESET;
			IN3_Value = GPIO_PIN_RESET;
			IN4_Value = GPIO_PIN_SET;
		}
	}
}


// Enter values to the input variables.
void enter_IN_values() {
	HAL_GPIO_WritePin(IN1_PORT, IN1_PIN, IN1_Value);
	HAL_GPIO_WritePin(IN2_PORT, IN2_PIN, IN2_Value);
	HAL_GPIO_WritePin(IN3_PORT, IN3_PIN, IN3_Value);
	HAL_GPIO_WritePin(IN4_PORT, IN4_PIN, IN4_Value);
}
