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

void sys_delay_init(uint32_t sys_clk);
void delay_ms (uint32_t ms);
void delay_us(uint32_t us);

#endif /* CPU_H_ */
