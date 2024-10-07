/*
 * flame_sensor.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam Samy
 */
#include "flame_sensor.h"
#include "gpio.h"
/*initialize input pin for the flame sensor
 */
void FlameSensor_init(void){
	GPIO_setupPinDirection(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN, PIN_INPUT);
}
/* Function description:
 * it detects whether there is a flame or not
 * Flame sensor is a digital sensor returns logic high for detecting a flame or logic low if not
 * */
uint8 FlameSensor_getValue(void){
	uint8 FlameSensor_Value=0;
	FlameSensor_Value= GPIO_readPin(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN);
	return FlameSensor_Value;
}

