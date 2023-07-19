/*
 * gpt.h
 *
 *  Created on: Jul 15, 2023
 *      Author: moata
 */

#ifndef GPT_H_
#define GPT_H_

#include "rd.h"
#include <stdio.h>
#define TIM_NULL	-1
#define timer_UIF_flag_clear(x)   (x->TIMx_SR &= (1<<UIF))

typedef enum
{
	tim_mode_basic, tim_mode_input_capture, tim_mode_output_capture , tim_mode_one_pulse , tim_mode_pwm
}tim_mode_t;

typedef enum
{
	tim_uint_us , tim_uint_ms
}tim_uint_t;

typedef enum
{
	tim_update_int_disable , tim_update_int_enable
}tim_update_int_t;


typedef struct
{
	// General Config
		tim_mode_t 			mode;
		uint8_t			tim_clk_mhz;

	// basic timer
		uint16_t 			event_flag ;
		tim_uint_t			uint;
		tim_update_int_t	update_int;

}tim_config_t;

typedef struct
{
	volatile gpt_registers_t* timer ;
			 tim_config_t 	 config;

}tim_use_t;


tim_use_t timer_basic_new(volatile gpt_registers_t* timx, tim_uint_t uintx,tim_update_int_t update_intx,uint8_t tim_clk_mhzx, uint16_t event_flagx);
void timer_basic_init(tim_use_t* timer);
void timer_start(tim_use_t* timer);
void timer_stop(tim_use_t* timer);
void timer_update_event(tim_use_t* timer);


#endif /* GPT_H_ */
