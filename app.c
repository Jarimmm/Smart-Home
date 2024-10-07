/*
 * app.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam Samy
 */
#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "led.h"
#include "dc_motor.h"
#include "std_types.h"
#include <util/delay.h> //for delays
#include "gpio.h"

void main(void){
	//ADC_ConfigType ADC_Configurations={ADC_PRESCALER_VALUE,ADC_REF_VOLT_Current_VALUE};
	LCD_init();
	LEDS_init();
	ADC_init();// function argument in case of dynamic configuration :&ADC_Configurations
	Buzzer_init();
	FlameSensor_init();
	DcMotor_Init();
	uint8 intensity=0;
	uint8 temperature=0;
	LCD_moveCursor(1,0); //move the cursor of the LCD to the desired location
	LCD_displayString("Temp=   LDR=   %");
	while(1){
		intensity =LDR_getLightIntensity();
		temperature=LM35_getTemperature();
		/*Intensity < 15%: All 3 LEDs (Red, Green, and Blue) turn ON.
          Intensity 16–50%: Red and Green LEDs turn ON.
          Intensity 51–70%: Only the Red LED turns ON.
          Intensity > 70%: All LEDs are turned OFF.
		 *
		 */
		if(intensity<15){
			LED_on(red);
			LED_on(green);
			LED_on(blue);
			LCD_moveCursor(1,12);
						if(intensity>=10){
						LCD_intgerToString(intensity);
						}
						else{
							LCD_intgerToString(intensity);
							LCD_displayCharacter(' ');
						}

		}
		else if(intensity<50){
			LED_on(red);
		    LED_on(green);
		    LED_off(blue);
		    LCD_moveCursor(1,12);
		    LCD_intgerToString(intensity);
		}
		else if(intensity<70){
			LED_on(red);
			LED_off(green);
		    LED_off(blue);
		    LCD_moveCursor(1,12);
		    LCD_intgerToString(intensity);
		}
		else{
			LED_off(red);
			LED_off(green);
			LED_off(blue);
			LCD_moveCursor(1,12);
						if(intensity>=100){
							LCD_intgerToString(intensity);
						}
						else{
						LCD_intgerToString(intensity);
						LCD_displayCharacter(' ');
						}
		}
     /*
     * Temperature ≥ 40°C: Fan ON at 100% speed.
     Temperature ≥ 35°C and < 40°C: Fan ON at 75% speed.
     Temperature ≥ 30°C and < 35°C: Fan ON at 50% speed.
     Temperature ≥ 25°C and < 30°C: Fan ON at 25% speed.
     Temperature < 25°C: Fan OFF
     */
		if(temperature>=40){
			DcMotor_Rotate(CW, 100);
			LCD_displayStringRowColumn(0,3,"FAN IS ON ");
			LCD_moveCursor(1,5);
			if(temperature>=100){
				LCD_intgerToString(temperature);
				}
				else{
				LCD_intgerToString(temperature);
				LCD_displayCharacter(' ');
				}
		}
		else if(temperature>=35){
			DcMotor_Rotate(CW, 75);
			LCD_displayStringRowColumn(0,3,"FAN IS ON ");
			LCD_moveCursor(1,5);
			LCD_intgerToString(temperature);
		}
		else if(temperature>=30){
			DcMotor_Rotate(CW, 50);
			LCD_displayStringRowColumn(0,3,"FAN IS ON ");
			LCD_moveCursor(1,5);
			LCD_intgerToString(temperature);
				}
		else if(temperature>=25){
			DcMotor_Rotate(CW, 25);
			LCD_displayStringRowColumn(0,3,"FAN IS ON ");
			LCD_moveCursor(1,5);
			LCD_intgerToString(temperature);

				}
		else {
			DcMotor_Rotate(Stop,0);
			LCD_displayStringRowColumn(0,3,"FAN IS OFF");
			LCD_moveCursor(1,5);
			if(temperature>=10){
				LCD_intgerToString(temperature);
					}
				else{
				LCD_intgerToString(temperature);
				LCD_displayCharacter(' ');
				}


		}
		/*in case of detecting a flame the buzzer will turn on
		 * and display "critical alert"
		 */
		FlameSensor_getValue();
		if(FlameSensor_getValue()){
		    Buzzer_on();
			LCD_clearScreen();
			LCD_displayString("Critical alert!");
			while(FlameSensor_getValue()){}
			Buzzer_off();
			LCD_clearScreen();
			LCD_moveCursor(1,0);
			LCD_displayString("Temp=   IDR=   %");
		}
		else{
			Buzzer_off();
		}
	}
}
