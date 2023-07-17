/*
 * gpt.c
 *
 *  Created on: Jul 15, 2023
 *      Author: moata
 */

#include "gpt.h"


static void clock_division (timer_t* TIM)
{
	if ((TIM->clk_division) == gpt_clock_division_0 )
	{
		// CKD = 00: tDTS = tCK_INT
		TIM->timer->TIMx_CR1 &= ~(1<<CKD0);
		TIM->timer->TIMx_CR1 &= ~(1<<CKD1);
	}
	else if ((TIM->clk_division) == gpt_clock_division_2 )
	{
		// CKD = 01: tDTS = 2 × tCK_INT
		TIM->timer->TIMx_CR1 |= (1<<CKD0);
		TIM->timer->TIMx_CR1 &= ~(1<<CKD1);
	}
	else if ((TIM->clk_division) == gpt_clock_division_4 )
	{
		// CKD = 01: tDTS = 2 × tCK_INT
		TIM->timer->TIMx_CR1 &= ~(1<<CKD0);
		TIM->timer->TIMx_CR1 |= (1<<CKD1);
	}
	else
	{
		;
	}
}
static void reload_preload (timer_t* TIM)
{
	//Auto-reload preload enable
	if (TIM->reload_pre == gpt_reload_preload_enable )
	{
		TIM->timer->TIMx_CR1 |= (1<<ARPE);
	}
	else if (TIM->reload_pre == gpt_reload_preload_disable )
	{
		TIM->timer->TIMx_CR1 &= ~(1<<ARPE);
	}
	else
	{
		;
	}
}
static void counter_dreaction (timer_t* TIM)
{
		//choose counter Direction  = counter up
	if (TIM->direction == gpt_direction_upcounter )
	{
		// 0: Counter used as up counter
		TIM->timer->TIMx_CR1 &= ~(1<<ARPE);

		//+ mode   10  : Center-aligned mode 2.when the counter is counting up.
		//TIM->timer->TIMx_CR1 &= ~(1<<CMS0);
		//TIM->timer->TIMx_CR1 |= (1<<CMS1);
	}
	else if (TIM->direction == gpt_direction_downcounter )
	{
		// 1: Counter used as down counter
		TIM->timer->TIMx_CR1 |= (1<<ARPE);

		//+ mode   01  : Center-aligned mode 2.when the counter is counting down..
		//TIM->timer->TIMx_CR1 |= (1<<CMS0);
		//TIM->timer->TIMx_CR1 &= ~(1<<CMS1);
	}
	else
	{
		;
	}

	//+ mode   11  : Center-aligned mode 3.when the counter is counting up or counting down..
	TIM->timer->TIMx_CR1 |= (1<<CMS0);
	TIM->timer->TIMx_CR1 |= (1<<CMS1);
}
static void timer_enable (timer_t* TIM)
{
	TIM->timer->TIMx_CR1 |= (1<<CEN);
}
static void timer_prescaler (timer_t* TIM)
{
	TIM->timer->TIMx_PSC = TIM->prescaler ;
}


timer_t timer_init(volatile gpt_registers_t* timerx, gpt_prescaler_t prescaler, gpt_clock_division_t clk_division,
		gpt_direction_t direction, gpt_reload_preload_t	reload_pre )
{

	timer_t TIM ;

	TIM.timer = timerx ;

	TIM.clk_division = clk_division;
	TIM.reload_pre = reload_pre;
	TIM.direction = direction;
	TIM.prescaler = prescaler;


	clock_division(&TIM);
	reload_preload(&TIM);
	counter_dreaction(&TIM);
	timer_prescaler(&TIM);


	timer_enable(&TIM);
}

void timer_pulse(timer_t* TIM , gpt_pulse_mode_t mode, uint32_t ms)
{

	if (mode == gpt_pulse_mode_stopped )
	{
		//0: Counter is not stopped at update event
		TIM->timer->TIMx_CR1 &= ~(1<<OPM);
	}
	else if (mode == gpt_pulse_mode_counting )
	{
		//1: Counter stops counting at the next update event
		TIM->timer->TIMx_CR1 |= (1<<OPM);
	}
	else
	{
		;
	}
	TIM->timer->TIMx_ARR = ms;
}

void timer_auto_reload(timer_t* TIM, uint32_t value)
{
	TIM->timer->TIMx_ARR = value ;
}
