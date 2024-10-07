/*
 * ldr_sensor.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam Samy
 */

#ifndef LDR_SENSOR_H_
#define LDR_SENSOR_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LDR_SENSOR_CHANNEL_ID 0
#define LDR_SENSOR_MAX_VOLT_VALUE 2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY 100
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for reading the intensity and gives it to the ADC
 * ADC converts the analog signals read by the sensor to digital signal
 * the function returns the intensity percentage after calculating
 */
uint16 LDR_getLightIntensity(void);


#endif /* LDR_SENSOR_H_ */
