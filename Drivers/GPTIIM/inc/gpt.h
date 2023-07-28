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
#define timer_UIF_flag_clear(x)   	(x->TIMx_SR &= ~(1<<UIF))
#define timer_CC1IF_flag_clear(x)	(x->TIMx_SR &= ~(1<<CC1IF))
#define timer_CC2IF_flag_clear(x)	(x->TIMx_SR &= ~(1<<CC2IF))
#define timer_CC3IF_flag_clear(x)	(x->TIMx_SR &= ~(1<<CC3IF))
#define timer_CC4IF_flag_clear(x)	(x->TIMx_SR &= ~(1<<CC4IF))

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

typedef enum
{
	tim_compare_int_disable , tim_compare_int_enable
}tim_compare_int_t;

typedef enum
{
	tim_ch_1, tim_ch_2, tim_ch_3, tim_ch_4
}tim_ch_t;

typedef struct
{
	// General Config
		tim_mode_t 			mode;
		uint8_t			tim_clk_mhz;

	// basic timer
		uint16_t 			event_tickx ;
		tim_uint_t			uint;
		tim_update_int_t	update_int;

	//output capture
		uint32_t 			frequency;
		tim_compare_int_t	compare_int;




}tim_config_t;

typedef struct
{
	volatile gpt_registers_t* timer ;
			 tim_config_t 	 config;

}tim_use_t;


tim_use_t timer_new_basic(volatile gpt_registers_t* timx, tim_uint_t uintx,tim_update_int_t update_intx,uint8_t tim_clk_mhzx, uint16_t event_flagx);
tim_use_t timer_new_output_comare(volatile gpt_registers_t* timx, uint32_t frequencyx, tim_compare_int_t compare_intx, uint8_t tim_clk_mhz );
void timer_output_compare_init(tim_use_t* timer,tim_ch_t channal );
void timer_basic_init(tim_use_t* timer);
void timer_start(tim_use_t* timer);
void timer_stop(tim_use_t* timer);
void timer_update_event(tim_use_t* timer);


#endif /* GPT_H_ */
