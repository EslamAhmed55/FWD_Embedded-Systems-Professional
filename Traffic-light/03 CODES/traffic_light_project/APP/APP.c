#include "APP.h"

volatile u8 INT_COUNTER = 0 ;
u8 car_IS_red_flag = 0 ;
u8 car_IS_green_flag = 0 ;
u8 car_IS_yellow_flag = 0 ;

void app_init()
{

	LED_INIT(CAR_LEDS_PORT,CAR_LED_G_PIN);
		LED_INIT(CAR_LEDS_PORT,CAR_LED_Y_PIN);
		LED_INIT(CAR_LEDS_PORT,CAR_LED_R_PIN);
		LED_INIT(WALKER_LEDS_PORT,WALKER_LED_G_PIN);
		LED_INIT(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
		LED_INIT(WALKER_LEDS_PORT,WALKER_LED_R_PIN);
		P_B_INIT();
		EXT_INT_0_INIT();
		TIMER_1_INIT();

}

void app_start()
{


	//** turn off all leds
				LED_OFF(CAR_LEDS_PORT,CAR_LED_G_PIN);
				LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
				LED_OFF(CAR_LEDS_PORT,CAR_LED_R_PIN);
				LED_OFF(WALKER_LEDS_PORT,WALKER_LED_G_PIN);
				LED_OFF(WALKER_LEDS_PORT,WALKER_LED_Y_PIN);
				LED_OFF(WALKER_LEDS_PORT,WALKER_LED_R_PIN);
				/************************************************************************/
				/******************** Normal mode start *********************************/
				/************************************************************************/
				/////////////////////////////////////
				LED_ON(CAR_LEDS_PORT,CAR_LED_G_PIN);
				car_IS_green_flag = 1 ;
				delayINmilliSec(5000);
				car_IS_yellow_flag = 1 ;
				for (u8 i=0 ; i <= 4 ; i++)
				{
					LED_ON(CAR_LEDS_PORT,CAR_LED_Y_PIN);
					delayINmilliSec(500);
					LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
					delayINmilliSec(500);
				}
				car_IS_yellow_flag = 0 ;
				car_IS_green_flag = 0 ;
				LED_OFF(CAR_LEDS_PORT,CAR_LED_G_PIN);
				///////////////////////////////////////
				LED_ON(CAR_LEDS_PORT,CAR_LED_R_PIN);
				car_IS_red_flag = 1 ;
				delayINmilliSec(5000);
				car_IS_yellow_flag = 1 ;
				for (u8 i=0 ; i <= 4 ; i++)
				{
					LED_ON(CAR_LEDS_PORT,CAR_LED_Y_PIN);
					delayINmilliSec(500);
					LED_OFF(CAR_LEDS_PORT,CAR_LED_Y_PIN);
					delayINmilliSec(500);
				}
				car_IS_yellow_flag = 0 ;
				car_IS_red_flag = 0 ;
				LED_OFF(CAR_LEDS_PORT,CAR_LED_R_PIN);
				///////////////////////////////////////


}

