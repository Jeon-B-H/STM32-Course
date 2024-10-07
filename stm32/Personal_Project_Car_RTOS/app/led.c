#include "led.h"

void control_led() {
	if(receive_data[0] == 'D' || receive_data[0] == 'A' || receive_data[0] == 'G') {
		HAL_GPIO_WritePin(RIGHT_LED_PORT, RIGHT_LED_PIN, 0);
		HAL_GPIO_TogglePin(LEFT_LED_PORT, LEFT_LED_PIN);
		HAL_Delay(200);
	}else if(receive_data[0] == 'F' || receive_data[0] == 'C' || receive_data[0] == 'I') {
		HAL_GPIO_WritePin(LEFT_LED_PORT, LEFT_LED_PIN, 0);
		HAL_GPIO_TogglePin(RIGHT_LED_PORT, RIGHT_LED_PIN);
		HAL_Delay(200);
	} else {
		HAL_GPIO_WritePin(LEFT_LED_PORT, LEFT_LED_PIN, 0);
		HAL_GPIO_WritePin(RIGHT_LED_PORT, RIGHT_LED_PIN, 0);
	}
}
