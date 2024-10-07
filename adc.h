 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
/* for more configurable ADC driver
 * typedef enum{
	DV0_2,DV1_2,DV_4,DV_8,DV_16,DV_32,DV_64,DV_128
}ADC_Prescaler;
typedef enum{
	AREF,AVCC,Reversed,Internal
}ADC_RefVolt;
typedef struct{
	ADC_Prescaler Division_Factor;
	ADC_RefVolt ref_volt;
}ADC_ConfigType;
#define ADC_REF_VOLT_Current_VALUE   Internal
#define ADC_PRESCALER_VALUE  DV_128 */

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void); /*
function argument in case of dynamic configuration : const ADC_ConfigType*Config_ptr
*/
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
