/*
 * uart.h
 *
 *  Created on: Jul 24, 2023
 *      Author: moata
 */

#ifndef UART_H_
#define UART_H_

#include "rd.h"
#include <stdio.h>

typedef enum
{
	usart_parity_disable, usart_parity_enable
}usart_parity_t;

typedef enum
{
	usart_stop_1, usart_stop_2
}usart_stop_t;

typedef enum
{
	usart_mode_no_int, usart_mode_tx_int, usart_mode_rx_int,
	usart_mode_txrx_int
}usart_mode_int_t;

void usart_init(volatile uart_registers_t* usart,usart_parity_t parity,usart_stop_t stop_bit, uint32_t baud_rate,uint32_t Freq_clk,usart_mode_int_t int_mode );

void usart_write(volatile uart_registers_t* usart,uint8_t data);
void usart_write_string(volatile uart_registers_t* usart,char* str);

char usart_read(volatile uart_registers_t* usart);
char* usart_read_string(volatile uart_registers_t* usart);
#endif /* UART_H_ */
