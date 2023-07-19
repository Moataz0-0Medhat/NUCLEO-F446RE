/*
 * rd.h
 *
 *  Created on: Jul 8, 2023
 *      Author: moata
 */

#ifndef RD_RD_H_
#define RD_RD_H_

#include <stdint.h>
#define RCC_Base  0x40023800

// RCC_CR
#define HSION			0
#define HSIRDY			1
#define HSITRIM0		3
#define HSITRIM1		4
#define HSITRIM2		5
#define HSITRIM3		6
#define HSITRIM4		7
#define HSICAL0			8
#define HSICAL1			9
#define HSICAL2			10
#define HSICAL3			11
#define HSICAL4			12
#define HSICAL5			13
#define HSICAL6			14
#define HSICAL7			15
#define HSEON			16
#define	HSERDY			17
#define HSEBYP			18
#define CSSON			19
#define PLLON			24
#define PLLRDY			25
#define PLLI2SON		26
#define PLLI2SRDY		27
#define PLLSAION		28
#define PLLSAIRDY		29

// RCC_PLLCFGR
#define PLLM0		0
#define PLLM1		1
#define PLLM2		2
#define PLLM3		3
#define PLLM4		4
#define PLLM5		5
#define PLLN0		6
#define PLLN1		7
#define PLLN2		8
#define PLLN3		9
#define PLLN4		10
#define PLLN5		11
#define PLLN6		12
#define PLLN7		13
#define PLLN8		14
#define PLLP0		16
#define	PLLP1		17
#define PLLSRC		22
#define PLLQ0		24
#define PLLQ1		25
#define PLLQ2		26
#define PLLQ3		27
#define PLLR0		28
#define PLLR1		29
#define PLLR2		30

// RCC_CFGR
#define SW0         	0
#define SW1         	1
#define SWS0         	2
#define SWS1         	3
#define HPRE0         	4
#define HPRE1         	5
#define HPRE2         	6
#define HPRE3         	7
#define PPRE10         	10
#define PPRE11         	11
#define PPRE12         	12
#define PPRE20         	13
#define PPRE21         	14
#define PPRE22         	15
#define RTCPRE0     	16
#define RTCPRE1     	17
#define RTCPRE2     	18
#define RTCPRE3     	19
#define RTCPRE4     	20
#define MCO10         	21
#define MCO11         	22
#define MCO1_PRE10     	24
#define MCO1_PRE11     	25
#define MCO1_PRE12     	26
#define MCO2_PRE10     	27
#define MCO2_PRE11     	28
#define MCO2_PRE12     	29
#define MCO20         	30
#define MCO21         	31




typedef struct
{
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_PLLCFGR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_AHB1RSTR;
	volatile uint32_t RCC_AHB2RSTR;
	volatile uint32_t RCC_AHB3RSTR;
	volatile uint32_t Reserved0[1];
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t Reserved1[2];
	volatile uint32_t RCC_AHB1ENR;
	volatile uint32_t RCC_AHB2ENR;
	volatile uint32_t RCC_AHB3ENR;
	volatile uint32_t Reserved2[1];
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t Reserved3[2];
	volatile uint32_t RCC_AHB1LPENR;
	volatile uint32_t RCC_AHB2LPENR;
	volatile uint32_t RCC_AHB3LPENR;
	volatile uint32_t Reserved4[1];
	volatile uint32_t RCC_APB1LPENR;
	volatile uint32_t RCC_APB2LPENR;
	volatile uint32_t Reserved5[2];
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
	volatile uint32_t Reserved6[2];
	volatile uint32_t RCC_SSCGR;
	volatile uint32_t RCC_PLLI2SCFGR;
	volatile uint32_t RCC_PLLSAICFGR;
	volatile uint32_t RCC_DCKCFGR;
	volatile uint32_t RCC_CKGATENR;
	volatile uint32_t RCC_CKGATENR2;

}rcc_t;

#define RCC ((volatile rcc_t*)(RCC_Base))

#define GPIOA_Base  0x40020000
#define GPIOB_Base	0x40020400
#define GPIOC_Base	0x40020800
#define GPIOD_Base	0x40020C00
#define GPIOE_Base	0x40021000
#define GPIOF_Base	0x40021400
#define GPIOG_Base	0x40021800
#define GPIOH_Base	0x40021C00

// GPIOx_MODER

#define MODER00      0
#define MODER01      1
#define MODER10      2
#define MODER11      3
#define MODER20      4
#define MODER21      5
#define MODER30      6
#define MODER31      7
#define MODER40      8
#define MODER41      9
#define MODER50      10
#define MODER51      11
#define MODER60      12
#define MODER61      13
#define MODER70      14
#define MODER71      15
#define MODER80      16
#define MODER81	     17
#define MODER90      18
#define MODER91    	 19
#define MODER100     20
#define MODER101     21
#define MODER110     22
#define MODER111     23
#define MODER120     24
#define MODER121     25
#define MODER130     26
#define MODER131     27
#define MODER140     28
#define MODER141     29
#define MODER150     30
#define MODER151     31

// GPIOx_OTYPER

#define OT0      0
#define OT1      1
#define OT2      2
#define OT3      3
#define OT4      4
#define OT5      5
#define OT6      6
#define OT7      7
#define OT8      8
#define OT9      9
#define OT10     10
#define OT11     11
#define OT12     12
#define OT13     13
#define OT14     14
#define OT15     15

// GPIOx_OSPEEDR
#define OSPEEDR00   0
#define OSPEEDR01   1
#define OSPEEDR10   2
#define OSPEEDR11   3
#define OSPEEDR20   4
#define OSPEEDR21   5
#define OSPEEDR30   6
#define OSPEEDR31   7
#define OSPEEDR40   8
#define OSPEEDR41   9
#define OSPEEDR50   10
#define OSPEEDR51   11
#define OSPEEDR60   12
#define OSPEEDR61   13
#define OSPEEDR70   14
#define OSPEEDR71   15
#define OSPEEDR80   16
#define OSPEEDR81   17
#define OSPEEDR90   18
#define OSPEEDR91   19
#define OSPEEDR100  20
#define OSPEEDR101  21
#define OSPEEDR110  22
#define OSPEEDR111  23
#define OSPEEDR120  24
#define OSPEEDR121  25
#define OSPEEDR130  26
#define OSPEEDR131  27
#define OSPEEDR140  28
#define OSPEEDR141  29
#define OSPEEDR150  30
#define OSPEEDR151  31

// GPIOx_PUPDR

#define PUPDR00   0
#define PUPDR01   1
#define PUPDR10   2
#define PUPDR11   3
#define PUPDR20   4
#define PUPDR21   5
#define PUPDR30   6
#define PUPDR31   7
#define PUPDR40   8
#define PUPDR41   9
#define PUPDR50   10
#define PUPDR51   11
#define PUPDR60   12
#define PUPDR61   13
#define PUPDR70   14
#define PUPDR71   15
#define PUPDR80   16
#define PUPDR81   17
#define PUPDR90   18
#define PUPDR91   19
#define PUPDR100  20
#define PUPDR101  21
#define PUPDR110  22
#define PUPDR111  23
#define PUPDR120  24
#define PUPDR121  25
#define PUPDR130  26
#define PUPDR131  27
#define PUPDR140  28
#define PUPDR141  29
#define PUPDR150  30
#define PUPDR151  31


//GPIOx_IDR

#define IDR0    0
#define IDR1    1
#define IDR2    2
#define IDR3    3
#define IDR4    4
#define IDR5    5
#define IDR6    6
#define IDR7    7
#define IDR8    8
#define IDR9    9
#define IDR10   10
#define IDR11   11
#define IDR12   12
#define IDR13   13
#define IDR14   14
#define IDR15   15

//GPIOx_ODR

#define ODR0    0
#define ODR1    1
#define ODR2    2
#define ODR3    3
#define ODR4    4
#define ODR5    5
#define ODR6    6
#define ODR7    7
#define ODR8    8
#define ODR9    9
#define ODR10   10
#define ODR11   11
#define ODR12   12
#define ODR13   13
#define ODR14   14
#define ODR15   15

//GPIOx_BSRR

#define BS0    0
#define BS1    1
#define BS2    2
#define BS3    3
#define BS4    4
#define BS5    5
#define BS6    6
#define BS7    7
#define BS8    8
#define BS9    9
#define BS10   10
#define BS11   11
#define BS12   12
#define BS13   13
#define BS14   14
#define BS15   15
#define B00    16
#define BR1    17
#define BR2    18
#define BR3    19
#define BR4    20
#define BR5    21
#define BR6    22
#define BR7    23
#define BR8    24
#define BR9    25
#define BR10   26
#define BR11   27
#define BR12   28
#define BR13   29
#define BR14   30
#define BR15   31

// GPIOx_AFRL

#define AFRL00	 	0
#define AFRL01	 	1
#define AFRL02 		2
#define AFRL03 		3
#define AFRL10 		4
#define AFRL11 		5
#define AFRL12 		6
#define AFRL13 		7
#define AFRL20 		8
#define AFRL21 		9
#define AFRL22 		10
#define AFRL23 		11
#define AFRL30 		12
#define AFRL31 		13
#define AFRL32 		14
#define AFRL33		15
#define AFRL40	 	16
#define AFRL41	 	17
#define AFRL42	 	18
#define AFRL43 		19
#define AFRL50	 	20
#define AFRL51	 	21
#define AFRL52	 	22
#define AFRL53 		23
#define AFRL60	 	24
#define AFRL61	 	25
#define AFRL62	 	26
#define AFRL63 		27
#define AFRL70	 	28
#define AFRL71	 	29
#define AFRL72	 	30
#define AFRL73 		31


// GPIOx_AFRH


#define AFRH80   0
#define AFRH81   1
#define AFRH82   2
#define AFRH83   3
#define AFRH90   4
#define AFRH91   5
#define AFRH92   6
#define AFRH93   7
#define AFRH100  8
#define AFRH101  9
#define AFRH102  10
#define AFRH103  11
#define AFRH110  12
#define AFRH111  13
#define AFRH112  14
#define AFRH113  15
#define AFRH120  16
#define AFRH121  17
#define AFRH122  18
#define AFRH123  19
#define AFRH130  20
#define AFRH131  21
#define AFRH132  22
#define AFRH133  23
#define AFRH140  24
#define AFRH141  25
#define AFRH142  26
#define AFRH143  27
#define AFRH150  28
#define AFRH151  29
#define AFRH152  30
#define AFRH153  31

typedef struct
{

	volatile uint32_t GPIOx_MODER;
	volatile uint32_t GPIOx_OTYPER;
	volatile uint32_t GPIOx_OSPEEDR;
	volatile uint32_t GPIOx_PUPDR;
	volatile uint32_t GPIOx_IDR;
	volatile uint32_t GPIOx_ODR;
	volatile uint32_t GPIOx_BSRR;
	volatile uint32_t GPIOx_LCKR;
	volatile uint32_t GPIOx_AFRL;
	volatile uint32_t GPIOx_AFRH;
}gpio_t;

#define GPIOA ((volatile gpio_t*)(GPIOA_Base))
#define GPIOB ((volatile gpio_t*)(GPIOB_Base))
#define GPIOC ((volatile gpio_t*)(GPIOC_Base))
#define GPIOD ((volatile gpio_t*)(GPIOD_Base))
#define GPIOE ((volatile gpio_t*)(GPIOE_Base))
#define GPIOF ((volatile gpio_t*)(GPIOE_Base))
#define GPIOG ((volatile gpio_t*)(GPIOE_Base))
#define GPIOH ((volatile gpio_t*)(GPIOH_Base))

#define TIM2_Base  	0x40000000
#define TIM3_Base  	0x40000400
#define TIM4_Base  	0x40000800
#define TIM5_Base  	0x40001000
#define TIM9_Base 	0x40014000
#define TIM10_Base 	0x40014400
#define TIM11_Base 	0x40014800
#define TIM12_Base  	0x40001800
#define TIM13_Base  	0x40001C00
#define TIM14_Base  	0x40002000


// TIMx_CR1 Register

#define CEN 	0
#define UDIS	1
#define URS		2
#define OPM		3
#define DIR		4
#define CMS0	5
#define CMS1	6
#define ARPE	7
#define CKD0	8
#define CKD1	9

// TIMx_CR2 Register

#define CCDS		3
#define MMS0		4
#define MMS1		5
#define MMS2		6
#define TI1S		7

// TIMx_SMCR Register

#define SMS0		0
#define SMS1		1
#define SMS2		2
#define TS0			4
#define TS1			5
#define TS2			6
#define MSM			7
#define ETF0		8
#define ETF1		9
#define ETF2		10
#define ETF3		11
#define ETPS0		12
#define ETPS1		13
#define ECE			14
#define ETP			15

// TIMx_DIER Register

#define UIE			0
#define CC1IE		1
#define CC2IE		2
#define CC3IE		3
#define CC4IE		4
#define TIE			6
#define UDE			8
#define CC1DE		9
#define CC2DE		10
#define CC3DE		11
#define CC4DE		12
#define TDE			14

// TIMx_SR Register

#define UIF			0
#define CC1IF		1
#define CC2IF		2
#define CC3IF		3
#define CC4IF		4
#define TIF			6
#define CC1DE		9
#define CC2DE		10
#define CC3DE		11
#define CC4DE		12

// TIMx_EGR Register

#define UG			0
#define CC1G		1
#define CC2G		2
#define CC3G		3
#define CC4G		4
#define TG			6

// TIMx_CCMR1 Register

#define CC1S0		0
#define OC1S1		1
#define OC1FE		2
#define OC1PE		3
#define OC1M0		4
#define OC1M1		5
#define OC1M2		6
#define OC1CE		7
#define CC2S0		8
#define CC2S1		9
#define CC2FE		10
#define OC2PE		11
#define OC2M0		12
#define OC2M1		13
#define OC2M2		14
#define OC2CE		15
// TIMx_CCMR1 Register INPUT

#define CC1S0		0
#define OC1S1		1
#define IC1PSC0		2
#define IC1PSC1		3
#define IC1F0		4
#define IC1F1		5
#define IC1F2		6
#define IC1F3		7
#define C2PSC		8
#define CC2S1		9
#define IC2PSC0		10
#define IC2PSC1		11
#define IC2F0		12
#define IC2F1		13
#define IC2F2		14
#define IC2F3		15

// TIMx_CCMR2 Register

#define CC3S0		0
#define OC3S1		1
#define OC3FE		2
#define OC3PE		3
#define OC3M0		4
#define OC3M1		5
#define OC3M2		6
#define OC3CE		7
#define CC4S0		8
#define CC4S1		9
#define CC4FE		10
#define OC4PE		11
#define OC4M0		12
#define OC4M1		13
#define OC4M2		14
#define OC4CE		15

// TIMx_CCMR2 Register INPUT

#define CC3S0		0
#define OC3S1		1
#define IC3PSC0		2
#define IC3PSC1		3
#define IC3F0		4
#define IC3F1		5
#define IC3F2		6
#define IC3F3		7
#define CC4S0		8
#define CC4S1		9
#define IC4PSC0		10
#define IC4PSC1		11
#define IC4F0		12
#define IC4F1		13
#define IC4F2		14
#define IC4F3		15

// TIMx_CCER Register

#define CC1E		0
#define CC1P		1
#define CC1NP		3
#define CC2E		4
#define CC2P		5
#define CC2NP		7
#define CC3E		8
#define CC3P		9
#define CC3NP		11
#define CC4E		12
#define CC4P		13
#define CC4NP		15

// TIMx_DCR Register

#define DBA0		0
#define DBA1		1
#define DBA2		2
#define DBA3		3
#define DBA4		4
#define DBL0		8
#define DBL1		9
#define DBL2		10
#define DBL3		11
#define DBL4		12

// TIMx_OR Register

#define ITR1_RMP0		10
#define ITR1_RMP1		11

#define TI4_RMP0		6
#define TI4_RMP1		7

#define TI1_RMP0		0
#define TI1_RMP1		1


typedef struct
{
	uint32_t TIMx_CR1;
	uint32_t TIMx_CR2;
	uint32_t TIMx_SMCR;
	uint32_t TIMx_DIER;
	uint32_t TIMx_SR;
	uint32_t TIMx_EGR;
	uint32_t TIMx_CCMR11;
	uint32_t TIMx_CCMR21;
	uint32_t TIMx_CCER;
	uint32_t TIMx_CNT;
	uint32_t TIMx_PSC;
	uint32_t TIMx_ARR;
	uint32_t Reserved0;
	uint32_t TIMx_CCR1;
	uint32_t TIMx_CCR2;
	uint32_t TIMx_CCR3;
	uint32_t TIMx_CCR4;
	uint32_t Reserved1;
	uint32_t TIMx_DCR;
	uint32_t TIMx_DMAR;
	uint32_t TIMx_OR;

}gpt_registers_t;

#define TIM2 	((volatile gpt_registers_t*)(TIM2_Base))
#define TIM3 	((volatile gpt_registers_t*)(TIM3_Base))
#define TIM4 	((volatile gpt_registers_t*)(TIM4_Base))
#define TIM5 	((volatile gpt_registers_t*)(TIM5_Base))
#define TIM9 	((volatile gpt_registers_t*)(TIM9_Base))
#define TIM10	((volatile gpt_registers_t*)(TIM10_Base))
#define TIM11	((volatile gpt_registers_t*)(TIM11_Base))
#define TIM12	((volatile gpt_registers_t*)(TIM12_Base))
#define TIM13	((volatile gpt_registers_t*)(TIM13_Base))
#define TIM14	((volatile gpt_registers_t*)(TIM14_Base))


#endif /* RD_RD_H_ */
