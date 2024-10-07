/*
 * led.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam Samy
 */

#ifndef LED_H_
#define LED_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define red_led_PORT_num PORTB_ID
#define red_led_PIN_num  PIN5_ID
#define green_led_PORT_num PORTB_ID
#define green_led_PIN_num  PIN6_ID
#define blue_led_PORT_num PORTB_ID
#define blue_led_PIN_num  PIN7_ID
#define LED_Turned_On LOGIC_HIGH
#define LED_Turned_Off LOGIC_LOW
typedef enum
{
	red,green,blue
}LED_ID;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialization for the LEDs
 */
void LEDS_init(void);
/*
 * Description :
 * Function responsible for setting the determined id led on.
 */
void LED_on(LED_ID id);
/*
 * Description :
 * Function responsible for setting the determined id led off.
 */
void LED_off(LED_ID id);
#endif /* LED_H_ */
