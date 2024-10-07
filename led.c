/*
 * led.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam Samy
 */
#include "led.h"
#include "gpio.h"
void LEDS_init(void){
 GPIO_setupPinDirection(red_led_PORT_num , red_led_PIN_num ,PIN_OUTPUT);
 GPIO_setupPinDirection(blue_led_PORT_num, blue_led_PIN_num,PIN_OUTPUT);
 GPIO_setupPinDirection(green_led_PORT_num, green_led_PIN_num,PIN_OUTPUT);
 GPIO_writePin(red_led_PORT_num, red_led_PIN_num,LED_Turned_Off);
 GPIO_writePin(blue_led_PORT_num, blue_led_PIN_num,LED_Turned_Off);
 GPIO_writePin(green_led_PORT_num, green_led_PIN_num,LED_Turned_Off);


}
void LED_on(LED_ID id){
	switch(id){
	case 0:
	GPIO_writePin(red_led_PORT_num, red_led_PIN_num,LED_Turned_On);
	break;
	case 1:
	GPIO_writePin(green_led_PORT_num, green_led_PIN_num,LED_Turned_On);
	break;
	case 2:
	 GPIO_writePin(blue_led_PORT_num, blue_led_PIN_num,LED_Turned_On);
	 break;

	}

}

void LED_off(LED_ID id){
	switch(id){
	case 0:
	GPIO_writePin(red_led_PORT_num, red_led_PIN_num,LED_Turned_Off);
	break;
	case 1:
	 GPIO_writePin(green_led_PORT_num, green_led_PIN_num,LED_Turned_Off);
	 break;
	case 2:
	 GPIO_writePin(blue_led_PORT_num, blue_led_PIN_num,LED_Turned_Off);
     break;

}
}
