/*
 * pmw.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam Samy
 */

#include "gpio.h"
#include <avr/io.h>

#include "pwm.h"
void PWM_Timer0_Start(uint8 duty_cycle){
	/*TCCR0 register description:
	 * WGM0:1 for Fast PMW
	 * COM01 for non-inverting mode,set OC0 to bottom
	 * CS00,CS02 for clk/1024 16MHz/1024= 15625 T(timer)=0.64usec
	 *
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<CS00) | (1<<CS02)|(1<<COM01);
	OCR0= duty_cycle;

	GPIO_setupPinDirection(Compare_Pin_PORT,Compare_Pin_PIN,PIN_OUTPUT);
	GPIO_writePin(Compare_Pin_PORT,Compare_Pin_PIN,LOGIC_LOW);
}
