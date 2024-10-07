#include "ap.h"
#include "led.h"

// Global variables
uint8_t receive_data[8];

uint8_t IN1_Value = 0;
uint8_t IN2_Value = 0;
uint8_t IN3_Value = 0;
uint8_t IN4_Value = 0;


// Initialization of app
void apInit() {
	// Start PWM
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
}

// New Main Functions
void apMain() {
	// Initialization of UART
	HAL_UART_Receive_DMA(&huart1, receive_data, sizeof(receive_data));

	// Control Motor
	control_motor();
}

// Control Motor Function
void control_motor() {
	uint8_t left_duty = 40, right_duty = 40;
	uint8_t saving_left = 40, saving_right = 40;
	uint8_t duty_list[] = {40, 60, 80, 100, 0};
	char duty_index = 0;
	uint8_t light_enable = 0;

	// Receive data
	uint8_t receive_data_5, receive_data_6, prev_receive_data_5;

	while(1) {
		receive_data_5 = receive_data[5];
		receive_data_6 = receive_data[6];

		if(!receive_data_5) {
			if(!receive_data_6) {
				left_duty = 0;
				right_duty = 0;
			} else if(receive_data_6==1) {
				check_duty_of_motor(&saving_left, &saving_right);
				control_IN_Value(1, 0, 0);
				prev_receive_data_5 = 0;

				left_duty = saving_left;
				right_duty = saving_right;
			} else if(receive_data_6==2) {
				check_duty_of_motor(&saving_left, &saving_right);
				control_IN_Value(0, 0, 0);
				prev_receive_data_5 = 0;

				left_duty = saving_left;
				right_duty = saving_right;
			} else if(receive_data_6 == 4) {
				check_duty_of_motor(&saving_left, &saving_right);
				control_IN_Value(0, 1, 1);
				prev_receive_data_5 = 0;

				left_duty = saving_left;
				right_duty = saving_right;
			} else if(receive_data_6 == 8) {
				check_duty_of_motor(&saving_left, &saving_right);
				control_IN_Value(0, 0, 1);

				left_duty = saving_left;
				right_duty = saving_right;
			}
		} else {
			if(receive_data_5==4) {
				saving_left = 100;
				saving_right = 100;
				duty_index = 3;
				prev_receive_data_5 = 4;
			} else if(receive_data_5==32) {
				if(prev_receive_data_5 != 32) {
					if(duty_index==0) duty_index = 4;
					else duty_index--;
				}

				saving_left = duty_list[duty_index];
				saving_right = duty_list[duty_index];
				prev_receive_data_5 = 32;
			} else if(receive_data_5 == 8) {
				if(prev_receive_data_5 != 8) {
					if(duty_index==4) duty_index = 0;
					else duty_index ++;
				}

				saving_left = duty_list[duty_index];
				saving_right = duty_list[duty_index];
				prev_receive_data_5 = 8;
			}
		}

		// Enter values to the input variables.
		enter_IN_values();

		//Drive the motors by sending duty values to each motor.
		if(!prev_receive_data_5) {
			TIM1->CCR2 = left_duty;
			TIM3->CCR2 = right_duty;
		}

		// Control LED
//		if(light_enable) {
//			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
//			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
//			HAL_Delay(200);
//		}
	}
}

// Check the duty of Motor
void check_duty_of_motor (uint8_t* p_left_duty, uint8_t* p_right_duty) {
	if(!(*p_left_duty) && !(*p_right_duty)) {
		*p_left_duty = 40;
		*p_right_duty = 40;
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
