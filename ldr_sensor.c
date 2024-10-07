/*
 * ldr_sensor.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam Samy
 */

#include "ldr_sensor.h"
#include "adc.h"
uint16 LDR_getLightIntensity(void){
	uint8 Light_Intensity=0;
	uint16 adc_value=0;
	adc_value=ADC_readChannel(LDR_SENSOR_CHANNEL_ID);
	Light_Intensity=(uint8)(((uint32)adc_value*ADC_REF_VOLT_VALUE*LDR_SENSOR_MAX_LIGHT_INTENSITY)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));
	return Light_Intensity;
}
