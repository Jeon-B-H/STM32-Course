#include "ap.h"
#include "led.h"

// Initialization of app
void apInit() {

}

// New Main Functions
void apMain() {
	while(1) {
		for(uint8_t i=0; i<8; i++) {
			led_toggle(i);
			delay(200);
		}
	}
}

