/*
 * cpu.c
 *
 *  Created on: Jul 10, 2023
 *      Author: moata
 */

#include "cpu.h"

static volatile uint32_t us_counter = 0 ;

void SysTick_Handler (void)
{
	us_counter++;
}

void sys_delay_init(uint32_t sys_clk)
{
	//   1. Program reload value. (1us)
	SYST_RVR = (sys_clk/ 1000000) - 1;

	// 2. Clear current value.
	SYST_CVR = 0;
	// 3. Program Control and Status register.

	// 3.1 clock source: is processor clock
	set_bit(SYST_CSR,2);

	// 3.2 disable SysTick exception request:
	clr_bit(SYST_CSR,1);

	// 3.3 Enable the counter:
	set_bit(SYST_CSR,0);

}

void delay_us(uint32_t us)
{

	// 1. Clear us_counter value.
	us_counter = 0 ;
	while(us_counter < us );

}

void delay_ms(uint32_t ms)
{
	delay_us(ms*1000);
}
