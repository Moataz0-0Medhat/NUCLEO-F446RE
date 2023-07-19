/*
 * gpt.c
 *
 *  Created on: Jul 15, 2023
 *      Author: moata
 */

#include "gpt.h"


tim_use_t timer_basic_new(volatile gpt_registers_t* timx, tim_uint_t uintx,tim_update_int_t update_intx,uint8_t tim_clk_mhzx, uint16_t event_flagx)
{
	tim_use_t tim ;
	tim.timer = timx;
	tim.config.uint = uintx;
	tim.config.update_int = update_intx ;
	tim.config.event_flag = event_flagx;
	tim.config.tim_clk_mhz = tim_clk_mhzx ;

	return (tim);
}


void timer_basic_init(tim_use_t* timer)
{
	// Bit 0 CEN: Counter enable == 0: Counter disabled
		timer->timer->TIMx_CR1 &= ~(1<<CEN);

	//Bit 1 UDIS: Update disable == 0: UEV enabled
		timer->timer->TIMx_CR1 &= ~(1<<UDIS);

	//Bit 2 URS: Update request source == 1: Only counter overflow/underflow generates an update interrupt
		timer->timer->TIMx_CR1 |= (1<<URS);

	//Bit 3 OPM: One-pulse mode == 0: Counter is not stopped at update event
		timer->timer->TIMx_CR1 &= ~(1<<OPM);

	//Bit 4 DIR: Direction == 1: Counter used as down counter
		timer->timer->TIMx_CR1 |= (1<<DIR);

	//Bits 6:5 CMS: Center-aligned mode selection == 00: Edge-aligned mode.
		timer->timer->TIMx_CR1 &= ~(1<<CMS0);
		timer->timer->TIMx_CR1 &= ~(1<<CMS1);

	//Bit 7 ARPE: Auto-reload preload enable == 1: TIMx_ARR register is buffered
		timer->timer->TIMx_CR1 |= (1<<ARPE);

	// Update interrupt enable  ||  Update interrupt disabled
	if (timer->config.update_int == tim_update_int_enable)
	{
		// Bit 0 UIE: Update interrupt enable == 1: Update interrupt enabled
			timer->timer->TIMx_DIER |= (1<<UIE);
	}
	else if (timer->config.update_int == tim_update_int_disable)
	{
		// Bit 0 UIE: Update interrupt enable == 0: Update interrupt disabled
			timer->timer->TIMx_DIER &= ~(1<<UIE);
	}
	else
	{
		timer->config.update_int = TIM_NULL;
	}
	// Bits 15:0 CNT[15:0]: Counter value
	// TIM3 & TIM4 = 16bit  CNT = 0xFFFF
	if ((timer->timer == TIM3)|| (timer->timer == TIM4))
	{
		timer->timer->TIMx_CNT = 0xFFFF ;
	}
	// TIM2 & TIM5 = 32bit  CNT = 0xFFFFFFFF
	else if ((timer->timer == TIM2)|| (timer->timer == TIM5))
	{
		timer->timer->TIMx_CNT = 0xFFFFFFFF ;
	}
	else
	{
		timer->timer->TIMx_CNT = TIM_NULL;
	}
	// choose uint time used us | ms
	////Set tick time to be 0.5 uS
	if (timer->config.uint == tim_uint_us)
	{
		timer->timer->TIMx_PSC = ((timer->config.tim_clk_mhz)/2);
		timer->timer->TIMx_ARR = (2*(timer->config.event_flag));
	}
	//Set tick time to be 0.5 mS
	else if (timer->config.uint == tim_uint_ms)
	{
		timer->timer->TIMx_PSC = ((timer->config.tim_clk_mhz)*1000/2);
		timer->timer->TIMx_ARR = (2*(timer->config.event_flag));
	}
	else
	{
		timer->config.uint = TIM_NULL;
	}



}

void timer_start(tim_use_t* timer)
{
	//TIMx control register 1 (TIMx_CR1) == 1: Counter enabled
		timer->timer->TIMx_CR1 |= (1<<CEN);

}
void timer_stop(tim_use_t* timer)
{
	//TIMx control register 1 (TIMx_CR1) == 0: Counter disabled
		timer->timer->TIMx_CR1 &= ~(1<<CEN);
}

void timer_update_event(tim_use_t* timer)
{
	//This bit is set by hardware on an update event. It is cleared by software.
		while (!((timer->timer->TIMx_SR>>UIF) & 1));
	//Bit 0 UIF: Update interrupt flag == 0: No update occurred.
		timer->timer->TIMx_SR &= (1<<UIF);

}
