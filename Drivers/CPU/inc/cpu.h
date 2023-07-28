/*
 * cpu.h
 *
 *  Created on: Jul 10, 2023
 *      Author: moata
 */

#ifndef CPU_H_
#define CPU_H_

#include <stdint.h>
#include "bits.h"

// systick Register

#define SYST_CSR  (*(volatile uint32_t*) 0xE000E010)
#define SYST_RVR  (*(volatile uint32_t*) 0xE000E014)
#define SYST_CVR  (*(volatile uint32_t*) 0xE000E018)
#define SYST_CALIB (*(volatile uint32_t*) 0xE000E01C)
#define NVIC_ISER (*(volatile uint32_t*)0xE000E100)
#define NVIC_ICER (*(volatile uint32_t*)0XE000E180)

void sys_delay_init(uint32_t sys_clk);
void delay_ms (uint32_t ms);
void delay_us(uint32_t us);
void interrupt_enable(void);
void interrupt_disable(void);


#endif /* CPU_H_ */
