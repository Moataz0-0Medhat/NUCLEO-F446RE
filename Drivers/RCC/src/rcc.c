/*
 * rcc.c
 *
 *  Created on: Jul 8, 2023
 *      Author: moham
 */
#include "rcc.h"

static void AHB_PRE_SELECT (rcc_ahb_pre_t AHB_PRE)
{
	switch (AHB_PRE)
	{
	case RCC_AHB_PRE_1:
		clr_bit(RCC->RCC_CFGR,HPRE0);
		clr_bit(RCC->RCC_CFGR,HPRE1);
		clr_bit(RCC->RCC_CFGR,HPRE2);
		clr_bit(RCC->RCC_CFGR,HPRE3);
		break;
	case RCC_AHB_PRE_2:
		clr_bit(RCC->RCC_CFGR,HPRE0);
		clr_bit(RCC->RCC_CFGR,HPRE1);
		clr_bit(RCC->RCC_CFGR,HPRE2);
		set_bit(RCC->RCC_CFGR,HPRE3);
		break;
	case RCC_AHB_PRE_4:
		set_bit(RCC->RCC_CFGR,HPRE0);
		clr_bit(RCC->RCC_CFGR,HPRE1);
		clr_bit(RCC->RCC_CFGR,HPRE2);
		set_bit(RCC->RCC_CFGR,HPRE3);
		break;
	case RCC_AHB_PRE_8:
		clr_bit(RCC->RCC_CFGR,HPRE0);
		set_bit(RCC->RCC_CFGR,HPRE1);
		clr_bit(RCC->RCC_CFGR,HPRE2);
		set_bit(RCC->RCC_CFGR,HPRE3);
		break;
	case RCC_AHB_PRE_16:
		set_bit(RCC->RCC_CFGR,HPRE0);
		set_bit(RCC->RCC_CFGR,HPRE1);
		clr_bit(RCC->RCC_CFGR,HPRE2);
		set_bit(RCC->RCC_CFGR,HPRE3);
		break;
	case RCC_AHB_PRE_64:
		clr_bit(RCC->RCC_CFGR,HPRE0);
		clr_bit(RCC->RCC_CFGR,HPRE1);
		set_bit(RCC->RCC_CFGR,HPRE2);
		set_bit(RCC->RCC_CFGR,HPRE3);
		break;
	case RCC_AHB_PRE_128:
		set_bit(RCC->RCC_CFGR,HPRE0);
		clr_bit(RCC->RCC_CFGR,HPRE1);
		set_bit(RCC->RCC_CFGR,HPRE2);
		set_bit(RCC->RCC_CFGR,HPRE3);
		break;
	case RCC_AHB_PRE_256:
		clr_bit(RCC->RCC_CFGR,HPRE0);
		set_bit(RCC->RCC_CFGR,HPRE1);
		set_bit(RCC->RCC_CFGR,HPRE2);
		set_bit(RCC->RCC_CFGR,HPRE3);
		break;
	case RCC_AHB_PRE_512:
		set_bit(RCC->RCC_CFGR,HPRE0);
		set_bit(RCC->RCC_CFGR,HPRE1);
		set_bit(RCC->RCC_CFGR,HPRE2);
		set_bit(RCC->RCC_CFGR,HPRE3);
		break;
	default:
		clr_bit(RCC->RCC_CFGR,HPRE0);
		clr_bit(RCC->RCC_CFGR,HPRE1);
		clr_bit(RCC->RCC_CFGR,HPRE2);
		clr_bit(RCC->RCC_CFGR,HPRE3);
		break;
	}
}

static void APB1_PRE_SELECT (rcc_ahb_pre_t APB1_PRE)
{
	switch (APB1_PRE)
	{
	case RCC_AHB_PRE_1:
		clr_bit(RCC->RCC_CFGR,PPRE10);
		clr_bit(RCC->RCC_CFGR,PPRE11);
		clr_bit(RCC->RCC_CFGR,PPRE12);
		break;
	case RCC_AHB_PRE_2:
		clr_bit(RCC->RCC_CFGR,PPRE10);
		clr_bit(RCC->RCC_CFGR,PPRE11);
		set_bit(RCC->RCC_CFGR,PPRE12);
		break;
	case RCC_AHB_PRE_4:
		set_bit(RCC->RCC_CFGR,PPRE10);
		clr_bit(RCC->RCC_CFGR,PPRE11);
		set_bit(RCC->RCC_CFGR,PPRE12);
		break;
	case RCC_AHB_PRE_8:
		clr_bit(RCC->RCC_CFGR,PPRE10);
		set_bit(RCC->RCC_CFGR,PPRE11);
		set_bit(RCC->RCC_CFGR,PPRE12);
		break;
	case RCC_AHB_PRE_16:
		set_bit(RCC->RCC_CFGR,PPRE10);
		set_bit(RCC->RCC_CFGR,PPRE11);
		set_bit(RCC->RCC_CFGR,PPRE12);
		break;
	default:
		break;
	}
}

static void APB2_PRE_SELECT (rcc_ahb_pre_t APB2_PRE)
{
	switch (APB2_PRE)
	{
	case RCC_AHB_PRE_1:
		clr_bit(RCC->RCC_CFGR,PPRE20);
		clr_bit(RCC->RCC_CFGR,PPRE21);
		clr_bit(RCC->RCC_CFGR,PPRE22);
		break;
	case RCC_AHB_PRE_2:
		clr_bit(RCC->RCC_CFGR,PPRE20);
		clr_bit(RCC->RCC_CFGR,PPRE21);
		set_bit(RCC->RCC_CFGR,PPRE22);
		break;
	case RCC_AHB_PRE_4:
		set_bit(RCC->RCC_CFGR,PPRE20);
		clr_bit(RCC->RCC_CFGR,PPRE21);
		set_bit(RCC->RCC_CFGR,PPRE22);
		break;
	case RCC_AHB_PRE_8:
		clr_bit(RCC->RCC_CFGR,PPRE20);
		set_bit(RCC->RCC_CFGR,PPRE21);
		set_bit(RCC->RCC_CFGR,PPRE22);
		break;
	case RCC_AHB_PRE_16:
		set_bit(RCC->RCC_CFGR,PPRE20);
		set_bit(RCC->RCC_CFGR,PPRE21);
		set_bit(RCC->RCC_CFGR,PPRE22);
		break;
	default:
		break;
	}
}


void rcc_sys_init_hsi (rcc_ahb_pre_t AHB_PRE, rcc_apb1_pre_t APB1_PRE, rcc_apb2_pre_t APB2_PRE)
{
	//enable the HSI clk
	set_bit(RCC->RCC_CR,HSION);

	//wait for HSI to be stable
	while (get_bit(RCC->RCC_CR,HSIRDY) == 0);

	//AHB prescaler select
	AHB_PRE_SELECT(AHB_PRE);

	//APB1 Low speed prescaler
	APB1_PRE_SELECT(APB1_PRE);

	//APB2 high-speed prescaler
	APB2_PRE_SELECT(APB2_PRE);

	//System clock switch >> HSI oscillator selected as system clock
	clr_bit(RCC->RCC_CFGR,SW0);
	clr_bit(RCC->RCC_CFGR,SW1);

	while ( ((get_bit(RCC->RCC_CFGR,SWS1) << 1) | (get_bit(RCC->RCC_CFGR,SWS0))) != 0b00 );
}

void rcc_sys_init_hse (rcc_ahb_pre_t AHB_PRE, rcc_apb1_pre_t APB1_PRE, rcc_apb2_pre_t APB2_PRE)
{
	//enable the HSE clk
	set_bit(RCC->RCC_CR,HSEON);

	//wait for HSE to be stable
	while (get_bit(RCC->RCC_CR,HSERDY) == 0);

	//AHB prescaler select
	AHB_PRE_SELECT(AHB_PRE);

	//APB1 Low speed prescaler
	APB1_PRE_SELECT(APB1_PRE);

	//APB2 high-speed prescaler
	APB2_PRE_SELECT(APB2_PRE);

	//System clock switch >> HSI oscillator selected as system clock
	set_bit(RCC->RCC_CFGR,SW0);
	clr_bit(RCC->RCC_CFGR,SW1);

	while ( ((get_bit(RCC->RCC_CFGR,SWS1) << 1) | (get_bit(RCC->RCC_CFGR,SWS0))) != 0b01 );
}

void rcc_sys_init_pllp_42MHz_all(void)
{



	//• f(VCO clock) = f(PLL clock input) × (PLLN / PLLM) >> 16M × (84 / 8) = 168M
	//• f(PLL general clock output) = f(VCO clock) / PLLP >> 168 / 2 = 84

	//HSI_as_source
	clr_bit(RCC->RCC_PLLCFGR,PLLSRC);

	//Q = 4 >> 0b0100
	clr_bit(RCC->RCC_PLLCFGR,PLLQ0);
	clr_bit(RCC->RCC_PLLCFGR,PLLQ1);
	set_bit(RCC->RCC_PLLCFGR,PLLQ2);
	clr_bit(RCC->RCC_PLLCFGR,PLLQ3);

	//P = 2 >> 0b00
	clr_bit(RCC->RCC_PLLCFGR,PLLP0);
	clr_bit(RCC->RCC_PLLCFGR,PLLP1);

	//N = 84 >> 0b001010100
	clr_bit(RCC->RCC_PLLCFGR,PLLN0);
	clr_bit(RCC->RCC_PLLCFGR,PLLN1);
	set_bit(RCC->RCC_PLLCFGR,PLLN2);
	clr_bit(RCC->RCC_PLLCFGR,PLLN3);
	set_bit(RCC->RCC_PLLCFGR,PLLN4);
	clr_bit(RCC->RCC_PLLCFGR,PLLN5);
	set_bit(RCC->RCC_PLLCFGR,PLLN6);
	clr_bit(RCC->RCC_PLLCFGR,PLLN7);
	clr_bit(RCC->RCC_PLLCFGR,PLLN8);

	//M = 8 >> 0b01000
	clr_bit(RCC->RCC_PLLCFGR,PLLM0);
	clr_bit(RCC->RCC_PLLCFGR,PLLM1);
	clr_bit(RCC->RCC_PLLCFGR,PLLM2);
	set_bit(RCC->RCC_PLLCFGR,PLLM3);
	clr_bit(RCC->RCC_PLLCFGR,PLLM4);
	clr_bit(RCC->RCC_PLLCFGR,PLLM5);

	//AHB prescaler /2 84/2 = 42MHz
	AHB_PRE_SELECT(RCC_AHB_PRE_2);

	//APB1 prescaler /1  42MHz
	APB1_PRE_SELECT(RCC_APB1_PRE_1);

	//APB2 prescaler /1  42MHz
	APB2_PRE_SELECT(RCC_APB1_PRE_1);

	//enable the PLL clk
	set_bit(RCC->RCC_CR,PLLON);

	//wait for PLL to be stable
	while (get_bit(RCC->RCC_CR,PLLRDY) == 0);

	//System clock switch >> HSI oscillator selected as system clock
	clr_bit(RCC->RCC_CFGR,SW0);
	set_bit(RCC->RCC_CFGR,SW1);

	while ( ((get_bit(RCC->RCC_CFGR,SWS1) << 1) | (get_bit(RCC->RCC_CFGR,SWS0))) != 0b10 );
}

void rcc_sys_init_pllr_32MHz_all(void)
{



	//• f(VCO clock) = f(PLL clock input) × (PLLN / PLLM) >> 16M × (84 / 8) = 168M
	//• f(PLL general clock output) = f(VCO clock) / PLLP >> 64 / 2 = 84

	//HSI_as_source
	clr_bit(RCC->RCC_PLLCFGR,PLLSRC);

	//Q = 2 >> 0b0010
	clr_bit(RCC->RCC_PLLCFGR,PLLQ0);
	set_bit(RCC->RCC_PLLCFGR,PLLQ1);
	clr_bit(RCC->RCC_PLLCFGR,PLLQ2);
	clr_bit(RCC->RCC_PLLCFGR,PLLQ3);

	//R = 2 >> 0b0010
	clr_bit(RCC->RCC_PLLCFGR,PLLR0);
	set_bit(RCC->RCC_PLLCFGR,PLLR1);
	clr_bit(RCC->RCC_PLLCFGR,PLLR2);

	//N = 64 >> 0b00100 0000
	clr_bit(RCC->RCC_PLLCFGR,PLLN0);
	clr_bit(RCC->RCC_PLLCFGR,PLLN1);
	clr_bit(RCC->RCC_PLLCFGR,PLLN2);
	clr_bit(RCC->RCC_PLLCFGR,PLLN3);
	clr_bit(RCC->RCC_PLLCFGR,PLLN4);
	clr_bit(RCC->RCC_PLLCFGR,PLLN5);
	set_bit(RCC->RCC_PLLCFGR,PLLN6);
	clr_bit(RCC->RCC_PLLCFGR,PLLN7);
	clr_bit(RCC->RCC_PLLCFGR,PLLN8);

	//M = 8 >> 0b01000
	clr_bit(RCC->RCC_PLLCFGR,PLLM0);
	clr_bit(RCC->RCC_PLLCFGR,PLLM1);
	clr_bit(RCC->RCC_PLLCFGR,PLLM2);
	set_bit(RCC->RCC_PLLCFGR,PLLM3);
	clr_bit(RCC->RCC_PLLCFGR,PLLM4);
	clr_bit(RCC->RCC_PLLCFGR,PLLM5);

	//AHB prescaler /2 84/2 = 32MHz
	AHB_PRE_SELECT(RCC_AHB_PRE_2);

	//APB1 prescaler /1  32MHz
	APB1_PRE_SELECT(RCC_APB1_PRE_1);

	//APB2 prescaler /1  32MHz
	APB2_PRE_SELECT(RCC_APB1_PRE_1);

	//enable the PLL clk
	set_bit(RCC->RCC_CR,PLLON);

	//wait for PLL to be stable
	while (get_bit(RCC->RCC_CR,PLLRDY) == 0);

	//System clock switch >> HSI oscillator selected as system clock
	set_bit(RCC->RCC_CFGR,SW0);
	set_bit(RCC->RCC_CFGR,SW1);

	while ( ((get_bit(RCC->RCC_CFGR,SWS1) << 1) | (get_bit(RCC->RCC_CFGR,SWS0))) != 0b11 );
}

void rcc_ahb1_clk_enable(rcc_ahb1_peripherals peripheral)
{
	set_bit(RCC->RCC_AHB1ENR, peripheral);
}
void rcc_ahb2_clk_enable(rcc_ahb2_peripherals peripheral)
{
	set_bit(RCC->RCC_AHB2ENR, peripheral);
}
void rcc_ahb3_clk_enable(rcc_ahb3_peripherals peripheral)
{
	set_bit(RCC->RCC_AHB3ENR, peripheral);
}
