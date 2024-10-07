#include "ap.h"
#include "led.h"

// Global variables
uint8_t receive_data[1];

// Initialization of app
void apInit() {
	// Start PWM
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
}

// New Main Functions
void apMain() {
	HAL_UART_Receive_DMA(&huart1, receive_data, sizeof(receive_data));

	osKernelStart();
}
