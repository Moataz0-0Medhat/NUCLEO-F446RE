/*
 * gpt.c
 *
 *  Created on: Jul 15, 2023
 *      Author: moata
 */

#include "gpt.h"


tim_use_t timer_new_basic(volatile gpt_registers_t* timx, tim_uint_t uintx,tim_update_int_t update_intx,uint8_t tim_clk_mhzx, uint16_t event_tickx)
{
	tim_use_t tim ;
	tim.timer = timx;
	tim.config.uint = uintx;
	tim.config.update_int = update_intx ;
	tim.config.event_tickx = event_tickx;
	tim.config.tim_clk_mhz = tim_clk_mhzx ;


	return (tim);
}

tim_use_t timer_new_output_comare(volatile gpt_registers_t* timx, uint32_t frequencyx, tim_compare_int_t compare_intx, uint8_t tim_clk_mhz  )
{
	tim_use_t tim ;
	tim.timer = timx ;
	tim.config.frequency = frequencyx;
	tim.config.compare_int = compare_intx;
	tim.config.tim_clk_mhz = tim_clk_mhz;

	return (tim);
}


void timer_basic_init(tim_use_t* timer)
{
	//Bit 0 CEN: Counter enable == 0: Counter disabled
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
		timer->timer->TIMx_ARR = (2*(timer->config.event_tickx));
	}
	//Set tick time to be 0.5 mS
	else if (timer->config.uint == tim_uint_ms)
	{
		timer->timer->TIMx_PSC = ((timer->config.tim_clk_mhz)*1000/2);
		timer->timer->TIMx_ARR = (2*(timer->config.event_tickx));
	}
	else
	{
		timer->config.uint = TIM_NULL;
	}



}

void timer_output_compare_init(tim_use_t* timer,tim_ch_t channal )
{

	//Bit 0 CEN: Counter enable == 0: Counter disabled
	timer->timer->TIMx_CR1 &= ~(1<<CEN);

	//Bit 2 URS: Update request source == 1: Only counter overflow/underflow generates an update interrupt
	timer->timer->TIMx_CR1 |= (1<<URS);

	//Bit 4 DIR: Direction == 1: Counter used as down counter
	timer->timer->TIMx_CR1 |= (1<<DIR);

	////Set tick time to be 0.1 us
			timer->timer->TIMx_PSC = ((timer->config.tim_clk_mhz)/10000000);

	if (channal == tim_ch_1)
	{

		//Bit 0 CC1E: Capture/Compare 1 output enable. == 0: Off - OC1 is not active
			//CC1S bits are writable only when the channel is OFF (CC1E = 0 in TIMx_CCER).
				timer->timer->TIMx_CCER &= ~(1<<CC1E);

		//Bits 1:0 CC1S: Capture/Compare 1 selection == 00: CC1 channel is configured as output.
		timer->timer->TIMx_CCMR11 &= ~(1<<CC1S0);
		timer->timer->TIMx_CCMR11 &= ~(1<<CC1S1);

		//Bit 3 OC1PE: Output compare 1 preload disable
		timer->timer->TIMx_CCMR11 &= ~(1<<OC1PE);

		//Bits 6:4 OC1M: Output compare 1 mode == 011: Toggle - OC1REF toggles when TIMx_CNT=TIMx_CCR1.
		timer->timer->TIMx_CCMR11 &= ~(1<<OC1M0);
		timer->timer->TIMx_CCMR11 |= (1<<OC1M1);
		timer->timer->TIMx_CCMR11 |= (1<<OC1M2);

		//Bit 3 CC1NP: Capture/Compare 1 output Polarity. == CC1 channel configured as output:
		//CC1 channel configured as output:
		//CC1NP must be kept cleared in this case.
		timer->timer->TIMx_CCER &= ~(1<<CC1NP);

		//Bit 1 CC1P: Capture/Compare 1 output Polarity. == 1: OC1 active low
		timer->timer->TIMx_CCER |= (1<<CC1P);




		//Bits 15:0 CCR1[15:0]: Low Capture/Compare 1 value
		timer->timer->TIMx_CCR1 = (5000000/timer->config.frequency) ;

		// Capture/Compare 1 interrupt enable  ||  Capture/Compare 1 interrupt disabled
		if (timer->config.compare_int == tim_compare_int_enable)
		{
			//Bit 1 CC1IE: Capture/Compare 1 interrupt enable == 1: CC1 interrupt enabled
			timer->timer->TIMx_DIER |= (1<<CC1IE);
		}
		else if (timer->config.compare_int == tim_compare_int_disable)
		{
			// Bit 1 CC1IE: Capture/Compare 1 interrupt enable == 0: CC1 interrupt disabled
			timer->timer->TIMx_DIER &= ~(1<<CC1IE);
		}
		else
		{
			timer->config.update_int = TIM_NULL;
		}

		//Bit 0 CC1E: Capture/Compare 1 output enable. == 1: On - OC1 signal is output on the corresponding output pin
		timer->timer->TIMx_CCER |= (1<<CC1E);

	}
	else if (channal == tim_ch_2)
	{

		//Bit 0 CC2E: Capture/Compare 2 output enable. == 0: Off - OC2 is not active
			//CC2S bits are writable only when the channel is OFF (CC2E = 0 in TIMx_CCER).
				timer->timer->TIMx_CCER &= ~(1<<CC2E);

		//Bits 1:0 CC2S: Capture/Compare 2 selection == 00: CC2 channel is configured as output.
		timer->timer->TIMx_CCMR11 &= ~(1<<CC2S0);
		timer->timer->TIMx_CCMR11 &= ~(1<<CC2S1);

		//Bit 3 OC2PE: Output compare 2 preload disable
		timer->timer->TIMx_CCMR11 &= ~(1<<OC2PE);

		//Bits 6:4 OC2M: Output compare 2 mode == 011: Toggle - OC1REF toggles when TIMx_CNT=TIMx_CCR2.
		timer->timer->TIMx_CCMR11 &= ~(1<<OC2M0);
		timer->timer->TIMx_CCMR11 |= (1<<OC2M1);
		timer->timer->TIMx_CCMR11 |= (1<<OC2M2);

		//Bit 3 CC2NP: Capture/Compare 2 output Polarity. == CC2 channel configured as output:
		//CC2 channel configured as output:
		//CC2NP must be kept cleared in this case.
		timer->timer->TIMx_CCER &= ~(1<<CC2NP);

		//Bit 5 CC2P: Capture/Compare 2 output Polarity. == 1: OC2 active low
		timer->timer->TIMx_CCER |= (1<<CC2P);




		//Bits 15:0 CCR2[15:0]: Low Capture/Compare 2 value
		timer->timer->TIMx_CCR2 = (5000000/timer->config.frequency) ;

		// Capture/Compare 2 interrupt enable  ||  Capture/Compare 2 interrupt disabled
		if (timer->config.compare_int == tim_compare_int_enable)
		{
			//Bit 2 CC1IE: Capture/Compare 2 interrupt enable == 1: CC2 interrupt enabled
			timer->timer->TIMx_DIER |= (1<<CC2IE);
		}
		else if (timer->config.compare_int == tim_compare_int_disable)
		{
			// Bit 2 CC1IE: Capture/Compare 2 interrupt enable == 0: CC2 interrupt disabled
			timer->timer->TIMx_DIER &= ~(1<<CC2IE);
		}
		else
		{
			timer->config.update_int = TIM_NULL;
		}

		//Bit 4 CC2E: Capture/Compare 2 output enable. == 1: On - OC2 signal is output on the corresponding output pin
		timer->timer->TIMx_CCER |= (1<<CC2E);

	}
	else if (channal == tim_ch_3)
	{

		//Bit 8 CC3E: Capture/Compare 3 output enable. == 0: Off - OC3 is not active
			//CC3S bits are writable only when the channel is OFF (CC3E = 0 in TIMx_CCER).
				timer->timer->TIMx_CCER &= ~(1<<CC3E);

		//Bits 1:0 CC3S: Capture/Compare 3 selection == 00: CC3 channel is configured as output.
		timer->timer->TIMx_CCMR21 &= ~(1<<CC3S0);
		timer->timer->TIMx_CCMR21 &= ~(1<<CC3S1);

		//Bit 3 OC3PE: Output compare 3 preload disable
		timer->timer->TIMx_CCMR21 &= ~(1<<OC3PE);

		//Bits 6:4 OC2M: Output compare 3 mode == 011: Toggle - OC1REF toggles when TIMx_CNT=TIMx_CCR3.
		timer->timer->TIMx_CCMR21 &= ~(1<<OC3M0);
		timer->timer->TIMx_CCMR21 |= (1<<OC3M1);
		timer->timer->TIMx_CCMR21 |= (1<<OC3M2);

		//Bit 9 CC3NP: Capture/Compare 3 output Polarity. == CC3 channel configured as output:
		//CC3 channel configured as output:
		//CC3NP must be kept cleared in this case.
		timer->timer->TIMx_CCER &= ~(1<<CC3NP);

		//Bit 9 CC3P: Capture/Compare 3 output Polarity. == 1: OC3 active low
		timer->timer->TIMx_CCER |= (1<<CC3P);




		//Bits 15:0 CCR3[15:0]: Low Capture/Compare 3 value
		timer->timer->TIMx_CCR3 = (5000000/timer->config.frequency) ;

		// Capture/Compare 3 interrupt enable  ||  Capture/Compare 3 interrupt disabled
		if (timer->config.compare_int == tim_compare_int_enable)
		{
			//Bit 3 CC1IE: Capture/Compare 3 interrupt enable == 1: CC3 interrupt enabled
			timer->timer->TIMx_DIER |= (1<<CC3IE);
		}
		else if (timer->config.compare_int == tim_compare_int_disable)
		{
			// Bit 3 CC1IE: Capture/Compare 3 interrupt enable == 0: CC3 interrupt disabled
			timer->timer->TIMx_DIER &= ~(1<<CC3IE);
		}
		else
		{
			timer->config.update_int = TIM_NULL;
		}

		//Bit 8 CC3E: Capture/Compare 3 output enable. == 1: On - OC3 signal is output on the corresponding output pin
		timer->timer->TIMx_CCER |= (1<<CC3E);

	}
	else if (channal == tim_ch_4)
		{

			//Bit 12 CC4E: Capture/Compare 4 output enable. == 0: Off - OC4 is not active
				//CC4S bits are writable only when the channel is OFF (CC4E = 0 in TIMx_CCER).
					timer->timer->TIMx_CCER &= ~(1<<CC4E);

			//Bits 9:8 CC3S: Capture/Compare 4 selection == 00: CC4 channel is configured as output.
			timer->timer->TIMx_CCMR21 &= ~(1<<CC4S0);
			timer->timer->TIMx_CCMR21 &= ~(1<<CC4S1);

			//Bit 11 OC4PE: Output compare 4 preload disable
			timer->timer->TIMx_CCMR21 &= ~(1<<OC4PE);

			//Bits 14:12 OC4M: Output compare 4 mode == 011: Toggle - OC1REF toggles when TIMx_CNT=TIMx_CCR4.
			timer->timer->TIMx_CCMR21 &= ~(1<<OC4M0);
			timer->timer->TIMx_CCMR21 |= (1<<OC4M1);
			timer->timer->TIMx_CCMR21 |= (1<<OC4M2);

			//Bit 15 CC4NP: Capture/Compare 4 output Polarity. == CC4 channel configured as output:
			//CC4 channel configured as output:
			//CC4NP must be kept cleared in this case.
			timer->timer->TIMx_CCER &= ~(1<<CC4NP);

			//Bit 13 CC4P: Capture/Compare 4 output Polarity. == 1: OC4 active low
			timer->timer->TIMx_CCER |= (1<<CC4P);




			//Bits 15:0 CCR4[15:0]: Low Capture/Compare 4 value
			timer->timer->TIMx_CCR4 = (5000000/timer->config.frequency) ;

			// Capture/Compare 4 interrupt enable  ||  Capture/Compare 4 interrupt disabled
			if (timer->config.compare_int == tim_compare_int_enable)
			{
				//Bit 4 CC4IE: Capture/Compare 4 interrupt enable == 1: CC4 interrupt enabled
				timer->timer->TIMx_DIER |= (1<<CC4IE);
			}
			else if (timer->config.compare_int == tim_compare_int_disable)
			{
				// Bit 4 CC4IE: Capture/Compare 4 interrupt enable == 0: CC4 interrupt disabled
				timer->timer->TIMx_DIER &= ~(1<<CC4IE);
			}
			else
			{
				timer->config.update_int = TIM_NULL;
			}

			//Bit 12 CC4E: Capture/Compare 4output enable. == 1: On - OC4 signal is output on the corresponding output pin
			timer->timer->TIMx_CCER |= (1<<CC4E);

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
