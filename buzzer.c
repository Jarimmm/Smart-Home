/*
 * buzzer.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam Samy
 */
#include "buzzer.h"
#include "gpio.h"


void Buzzer_init(void){
	GPIO_setupPinDirection(BUZZER_PORT_num, BUZZER_PIN_num, PIN_OUTPUT);
}
void Buzzer_on(void){
	GPIO_writePin(BUZZER_PORT_num,BUZZER_PIN_num , LOGIC_HIGH);
}
void Buzzer_off(void){
	GPIO_writePin(BUZZER_PORT_num,BUZZER_PIN_num , LOGIC_LOW);
}
