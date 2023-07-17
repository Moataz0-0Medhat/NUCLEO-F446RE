/*
 * gpt.h
 *
 *  Created on: Jul 15, 2023
 *      Author: moata
 */

#ifndef GPT_H_
#define GPT_H_

#include "rd.h"
#define TIM_NULL	-1

/*typedef enum
{
	gpt_time_tim2, gpt_time_tim3, gpt_time_tim4, gpt_time_tim5, gpt_time_tim9, gpt_time_tim10,
	gpt_time_tim11, gpt_time_tim12, gpt_time_tim13, gpt_time_tim14, gpt_time_tim15
}gpt_time_t;*/

typedef enum
{
	gpt_prescaler_0, gpt_prescaler_2, gpt_prescaler_4, gpt_prescaler_8, gpt_prescaler_16
}gpt_prescaler_t;

typedef enum
{
	gpt_clock_division_0, gpt_clock_division_2, gpt_clock_division_4
}gpt_clock_division_t;

typedef enum
{
	gpt_direction_upcounter, gpt_direction_downcounter
}gpt_direction_t;

typedef enum
{
	gpt_reload_preload_enable, gpt_reload_preload_disable
}gpt_reload_preload_t;

typedef enum
{
	gpt_pulse_mode_stopped, gpt_pulse_mode_counting
}gpt_pulse_mode_t;


typedef struct
{
	volatile gpt_registers_t* 		timer ;
			 gpt_prescaler_t  		prescaler ;
			 gpt_clock_division_t	clk_division ;
			 gpt_direction_t		direction ;
			 gpt_reload_preload_t	reload_pre;
			 uint
}timer_t;


timer_t timer_init(volatile gpt_registers_t* timerx, gpt_prescaler_t prescaler, gpt_clock_division_t clk_division,
		gpt_direction_t direction, gpt_reload_preload_t	reload_pre );

void timer_pulse(timer_t* TIM , gpt_pulse_mode_t mode, uint32_t ms);
void timer_auto_reload(timer_t* TIM, uint32_t value);
#endif /* GPT_H_ */
