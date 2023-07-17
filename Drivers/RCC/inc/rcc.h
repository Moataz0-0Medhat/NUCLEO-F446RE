/*
 * rcc.h
 *
 *  Created on: Jul 8, 2023
 *      Author: moham
 */

#ifndef RCC_H_
#define RCC_H_

#include "rd.h"
#include "bits.h"

typedef enum
{

	RCC_AHB_PRE_1,		RCC_AHB_PRE_2,		RCC_AHB_PRE_4,
	RCC_AHB_PRE_8,		RCC_AHB_PRE_16,		RCC_AHB_PRE_64,
	RCC_AHB_PRE_128,	RCC_AHB_PRE_256,	RCC_AHB_PRE_512

}rcc_ahb_pre_t;

typedef enum
{

	RCC_APB1_PRE_1,		RCC_APB1_PRE_2,		RCC_APB1_PRE_4,
	RCC_APB1_PRE_8,		RCC_APB1_PRE_16

}rcc_apb1_pre_t;

typedef enum
{

	RCC_APB2_PRE_1,		RCC_APB2_PRE_2,		RCC_APB2_PRE_4,
	RCC_APB2_PRE_8,		RCC_APB2_PRE_16

}rcc_apb2_pre_t;

typedef enum
{

	RCC_GPIOA,		RCC_GPIOB,			RCC_GPIOC,
	RCC_GPIOD,		RCC_GPIOE,		 	RCC_GPIOF,
	RCC_GPIOG,		RCC_GPIOH,			RCC_CRC = 12,
	BKPSRAMEN = 19,	RCC_DMA1 = 21,	RCC_DMA2 ,
	OTGHSEN = 29, OTGHSULPIEN

}rcc_ahb1_peripherals;

typedef enum
{

	RCC_DCMIEN,		RCC_OTGFSEN = 7

}rcc_ahb2_peripherals;

typedef enum
{

	RCC_FMCEN,		RCC_QSPIEN

}rcc_ahb3_peripherals;



void rcc_sys_init_hsi (rcc_ahb_pre_t AHB_PRE, rcc_apb1_pre_t APB1_PRE, rcc_apb2_pre_t APB2_PRE);
void rcc_sys_init_hse (rcc_ahb_pre_t AHB_PRE, rcc_apb1_pre_t APB1_PRE, rcc_apb2_pre_t APB2_PRE);
void rcc_sys_init_pllp_42MHz_all(void);
void rcc_sys_init_pllr_32MHz_all(void);
void rcc_ahb1_clk_enable(rcc_ahb1_peripherals peripheral);
void rcc_ahb2_clk_enable(rcc_ahb2_peripherals peripheral);
void rcc_ahb3_clk_enable(rcc_ahb3_peripherals peripheral);
#endif /* RCC_H_ */
