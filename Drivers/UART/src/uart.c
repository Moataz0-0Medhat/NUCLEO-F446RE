/*
 * uart.c
 *
 *  Created on: Jul 24, 2023
 *      Author: moata
 */

#include "uart.h"

void usart_init(volatile uart_registers_t* usart,usart_parity_t parity,usart_stop_t stop_bit, uint32_t baud_rate,uint32_t Freq_clk,usart_mode_int_t int_mode )
{
	//Bit 15 OVER8: Oversampling mode == 0: oversampling by 16
	usart->USART_CR1 &= ~(1<<OVER8);

	//Bit 13 UE: USART enable = 1: USART enabled
	usart->USART_CR1 |= (1<<UE);

	// Parity control enable  || Parity control disable

	if (parity == usart_parity_enable)
	{
		//Bit 10 PCE: Parity control enable == 1: Parity control enabled
		usart->USART_CR1 |= (1<<PCE);
	}

	else
	{
		//Bit 10 PCE: Parity control enable == 0: Parity control disabled
		usart->USART_CR1 &= ~(1<<PCE);
	}

	// 	Bit 9 PS: Parity selection == 0: Even parity
	usart->USART_CR1 &= ~(1<<PS);

	//STOP bits These bits are used for programming the stop bits

	if (stop_bit == usart_stop_1)
	{
		//Bits 13:12 STOP: 00: 1 Stop bit
		usart->USART_CR2 &= ~(1<<STOP0);
		usart->USART_CR2 &= ~(1<<STOP1);
	}

	else
	{
		//Bits 13:12 STOP: 10: 2 Stop bits
		usart->USART_CR2 &= ~(1<<STOP0);
		usart->USART_CR2 |= (1<<STOP1);
	}

	//Baud rate Calculation
	// usartdiv float number
	double usartdiv =  ( ( (double) Freq_clk) / ( (double) (16 * baud_rate) ) );

	//1- need to convert to real number to get real number alone
	uint32_t div_mantissa = (uint32_t)usartdiv ;

	//2- we subtract  real number to floating .
	uint32_t div_fraction = ((uint32_t)( (usartdiv-div_mantissa) * 16) );

	// usart->USART_BRR == zero
	usart->USART_BRR = 0 ;
	//3- save float number in bits [3:0]
	usart->USART_BRR |= (div_fraction<< 0);

	//4- save real number in bits [15:4]
	usart->USART_BRR |= (div_mantissa<< 4);





	if (int_mode == usart_mode_no_int )
	{
		//Bit 7 TXEIE: TXE interrupt enable  == 0: Interrupt is inhibited
		usart->USART_CR1 &= ~(1<<TXEIE);

		//Bit 5 RXNEIE: RXNE interrupt enable == 0: Interrupt is inhibited
		usart->USART_CR1 &= ~(1<<RXNEIE);


	}
	else if (int_mode == usart_mode_tx_int)
	{
		//Bit 7 TXEIE: TXE interrupt enable  == 1: An USART interrupt is generated whenever TXE=1 in the USART_SR register
		usart->USART_CR1 |= (1<<TXEIE);
	}
	else if (int_mode == usart_mode_rx_int)
	{
		//Bit 5 RXNEIE: RXNE interrupt enable == 1: An USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR
		usart->USART_CR1 |= (1<<RXNEIE);
	}
	else if (int_mode == usart_mode_txrx_int)
	{
		//Bit 7 TXEIE: TXE interrupt enable  == 1: An USART interrupt is generated whenever TXE=1 in the USART_SR register
		usart->USART_CR1 |= (1<<TXEIE);

		//Bit 5 RXNEIE: RXNE interrupt enable == 1: An USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR
		usart->USART_CR1 |= (1<<RXNEIE);

	}
	else
	{
		//Bit 7 TXEIE: TXE interrupt enable  == 0: Interrupt is inhibited
		usart->USART_CR1 &= ~(1<<TXEIE);

		//Bit 5 RXNEIE: RXNE interrupt enable == 0: Interrupt is inhibited
		usart->USART_CR1 &= ~(1<<RXNEIE);

	}

	//Bit 3 TE: Transmitter enable == 1: Transmitter is enabled
	usart->USART_CR1 |= (1<<TE);

	//Bit 2 RE: Receiver enable == 1: Receiver is enabled and begins searching for a start bit
	usart->USART_CR1 |= (1<<RE);


}

void usart_write(volatile uart_registers_t* usart,uint8_t data)
{


	// wait TXE Flag Set ( Note: This bit is used during single buffer transmission)
	while (((usart->USART_SR>>TXE)&1) !=0);

	// write data in register DR[8:0]: Data value
	usart->USART_DR = data ;

	// now wait until Bit 6 TC: Transmission complete
	//while (((usart->USART_SR>>TC)&1) !=0);

	//Bit 3 TE: Transmitter enable == 0: Transmitter is disabled
	//usart->USART_CR1 &= ~(1<<TE);
}

void usart_write_string(volatile uart_registers_t* usart,char* str)
{
	char* ptr = str;

	while(*ptr != '\0')
	{
		usart_write( usart,*ptr);
		ptr++;
	}
	usart_write( usart,'\0');
}

char usart_read(volatile uart_registers_t* usart)
{


	//wait until the RXEN bit set  Bit 5 RXNE: Read data register not empty
	while(((usart->USART_SR>>RXNE)&1) != 0);


	// return value
	return (usart->USART_DR);
}


char* usart_read_string(volatile uart_registers_t* usart)
{
	char* str ;
	char ptr = usart_read(usart) ;

	while (ptr != '\0')
	{
		*str = ptr ;
		str ++;
		ptr = usart_read(usart);

	}
	*str = '\0';

	return str;
}
