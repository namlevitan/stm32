/**
*@file: hcsr04_userConf.h
*@brief: * Adjust some HC-SR04 sensor settings here, follow the comments below.
          (Between 'USER DEFINITIONS BEGIN' and 'USER DEFINITIONS END')
*@author: Veysel G�kdemir, � 2020
*@note: These settings are compatible with the projects generated by STM32CubeMX.
        Ensure that; the TIMx for echo pin supports 'Gated Mode',
				the TIMx for delay(10us) uses Clock source: Internal Clock or it is activated.
				For paramater settings, it should be taken into consideration that;
				Which timer uses which APB clock? For example, TIM1 uses APB2 Timer Clocks,
				TIM2 uses APB1 Timer Clocks. However, do not forget to activate related interrupts for the timers.
				For example, TIM1 uses update interrupt, trigger and commutation interrupts and TIM2 uses Global interrupt.
*/

/*Includes-------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "hcsr04_sensor.h"

/*---------------------------------------------------------------*/	

/**
*@brief: TIM_HandleTypeDef and GPIO_TypeDef definitions.
*@val: Default: htim_echo        = htim1;        
                htim_delay       = htim2;	       
	              TIM_Echo         = TIM1;
	              TIM_Delay        = TIM2;
								GPIO_Trigger     = GPIOD;
	              GPIO_Echo        = GPIOD;
	              GPIO_PIN_Trigger = GPIO_PIN_13;
	              GPIO_PIN_Echo    = GPIO_PIN_15;               
*/
TIM_HandleTypeDef htim_echo;
TIM_HandleTypeDef htim_delay;
TIM_TypeDef *TIM_Echo;
TIM_TypeDef *TIM_Delay;
GPIO_TypeDef *GPIO_Trigger;
GPIO_TypeDef *GPIO_Echo;
uint16_t GPIO_PIN_Trigger, GPIO_PIN_Echo;

void user_define(void)
{
	////////////////////////////USER DEFINITIONS BEGIN//////////////////////////////////////////////
	htim_echo        = htim1;         //*!Change "htim1" like htim2, htim3, ... according to which TIMx you use for Echo Pin.
  TIM_Echo         = TIM1;          //*!Change "TIM1" like TIM2, TIM3, ... according to which TIMx you use for Echo Pin.	
	htim_delay       = htim2;	        //*!Change "htim2" like htim3, htim5, ... according to which TIMx you use for the delay.	
	TIM_Delay        = TIM2;          //*!Change "TIM2" like TIM3, TIM5, ... according to which TIMx you use for the delay.
	
	GPIO_Trigger     = GPIOD;         //*!Change "GPIOD" like GPIOA, GPIOB, ... according to which GPIOx you use for Trigger Pin.
	GPIO_PIN_Trigger = GPIO_PIN_13;   //*!Change "GPIO_PIN_13" like GPIO_PIN_1, GPIO_PIN_2, ... according to which GPIO_PIN_x you use for Trigger Pin.
	GPIO_Echo        = GPIOD;         //*!Change "GPIOD" like GPIOC, GPIOE, ... according to which GPIOx you use to follow echo signal status.
	GPIO_PIN_Echo    = GPIO_PIN_15;   //*!Change "GPIO_PIN_15" like GPIO_PIN_3, GPIO_PIN_5, ... according to which GPIO_PIN_x you use to follow echo signal status.
}
                                 
/**
*@brief: HC-SR04 sensor zero point value.
*@val: Default: 2 cm
*/
const float zero_point = 2.00;   //set a value of zero point in cm by measuring the min. value which the sensor can do 
                                 //while an object stands as close to it as possible.
  /////////////////////////////USER DEFINITIONS END////////////////////////////////////////////////


/******************************************************END OF FILE*********************************************************************/
