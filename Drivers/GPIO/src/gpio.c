/*
 * gpio.c
 *
 *  Created on: Jul 9, 2023
 *      Author: moata
 */
#include "gpio.h"

static void pin_mode(pin_t* ret)
{
	if ( ret->mode == pin_mode_input )
	{

		ret->port->GPIOx_MODER &= ~(1<<((ret->pin)*2));
		ret->port->GPIOx_MODER &= ~(1<<(((ret->pin)*2)+1));
	}
	else if ( ret->mode == pin_mode_output )
	{
		ret->port->GPIOx_MODER |= (1<<((ret->pin)*2));
		ret->port->GPIOx_MODER &= ~(1<<(((ret->pin)*2)+1));;
	}
	else if ( ret->mode == pin_mode_alternate_fun )
	{
		ret->port->GPIOx_MODER &= ~(1<<((ret->pin)*2));
		ret->port->GPIOx_MODER |= (1<<(((ret->pin)*2)+1));
	}
	else if ( ret->mode == pin_mode_analog )
	{
		ret->port->GPIOx_MODER |= (1<<((ret->pin)*2));
		ret->port->GPIOx_MODER |= (1<<(((ret->pin)*2)+1));
	}
	else
	{
		;
	}


}

static void pin_outut_type(pin_t* ret)
{
	if ( ret->otype == pin_push_pull )
	{

		ret->port->GPIOx_OTYPER &= ~(1<<(ret->pin));

	}
	else if ( ret->otype == pin_open_drain )
	{
		ret->port->GPIOx_OTYPER |= (1<<(ret->pin));
	}

	else
	{
		;
	}


}

static void pin_pull_type(pin_t* ret)
{
	if ( ret->pupd == no_pull )
	{

		ret->port->GPIOx_PUPDR &= ~(1<<((ret->pin)*2));
		ret->port->GPIOx_PUPDR &= ~(1<<(((ret->pin)*2)+1));
	}
	else if ( ret->pupd == pull_up )
	{
		ret->port->GPIOx_PUPDR |= (1<<((ret->pin)*2));
		ret->port->GPIOx_PUPDR &= ~(1<<(((ret->pin)*2)+1));
	}
	else if ( ret->pupd == pull_down )
	{
		ret->port->GPIOx_PUPDR &= ~(1<<((ret->pin)*2));
		ret->port->GPIOx_PUPDR |= (1<<(((ret->pin)*2)+1));
	}
	else
	{
		;
	}


}

pin_t pin_init(volatile gpio_t* port, gpio_pin_t pin, pin_mode_t mode, pin_output_type_t otype, pin_pull_t pupd )
{
	pin_t ret ;
	ret.port = port;
	ret.mode = mode;
	ret.pupd = pupd ;
	ret.otype = otype;
	ret.pin = pin;


	pin_mode(&ret);
	pin_pull_type(&ret);
	pin_outut_type(&ret);



	return ret ;
}


void pin_level(pin_t *ret , uint8_t level)
{

	if ( level == pin_high)
	{
		ret->port->GPIOx_BSRR = (1<<ret->pin);

	}
	else if (level == pin_low)
	{
		ret->port->GPIOx_BSRR = (1<<((ret->pin)+16));
	}
	else
	{
		;
	}
}

uint8_t pin_read(pin_t* ret)
{

	return (((ret->port->GPIOx_IDR)>>ret->pin) & 1) ;
}

void pin_af(pin_t* ret, pin_alternate_t af)
{
	if (ret->pin < 8)
	{
		if (af == AF0)
		{
			ret->port->GPIOx_AFRL &= ~(1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+3));
		}
		else if (af == AF1)
		{
			ret->port->GPIOx_AFRL |= (1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+3));
		}
		else if (af == AF2)
		{
			ret->port->GPIOx_AFRL &= ~(1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+3));
		}
		else if (af == AF3)
		{
			ret->port->GPIOx_AFRL |= (1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+3));
		}
		else if (af == AF4)
		{
			ret->port->GPIOx_AFRL &= ~(1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+3));
		}
		else if (af == AF5)
		{
			ret->port->GPIOx_AFRL |= (1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+3));
		}
		else if (af == AF6)
		{
			ret->port->GPIOx_AFRL &= ~(1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+3));
		}
		else if (af == AF7)
		{
			ret->port->GPIOx_AFRL |= (1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+3));
		}
		else if (af == AF8)
		{
			ret->port->GPIOx_AFRL &= ~(1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+3));
		}
		else if (af == AF9)
		{
			ret->port->GPIOx_AFRL |= (1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+3));
		}
		else if (af == AF10)
		{
			ret->port->GPIOx_AFRL &= ~(1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+3));
		}
		else if (af == AF11)
		{
			ret->port->GPIOx_AFRL |= (1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+3));
		}
		else if (af == AF12)
		{
			ret->port->GPIOx_AFRL &= ~(1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+3));
		}
		else if (af == AF13)
		{
			ret->port->GPIOx_AFRL |= (1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL &= ~(1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+3));
		}
		else if (af == AF14)
		{
			ret->port->GPIOx_AFRL &= ~(1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+3));
		}
		else if (af == AF15)
		{
			ret->port->GPIOx_AFRL |= (1<<((ret->pin)*4));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+1));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+2));
			ret->port->GPIOx_AFRL |= (1<<(((ret->pin)*4)+3));
		}

	}
	else
	{
		if (af == AF0)
		{
			ret->port->GPIOx_AFRH &= ~(1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF1)
		{
			ret->port->GPIOx_AFRH |= (1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF2)
		{
			ret->port->GPIOx_AFRH &= ~(1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF3)
		{
			ret->port->GPIOx_AFRH |= (1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF4)
		{
			ret->port->GPIOx_AFRH &= ~(1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF5)
		{
			ret->port->GPIOx_AFRH |= (1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF6)
		{
			ret->port->GPIOx_AFRH &= ~(1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF7)
		{
			ret->port->GPIOx_AFRH |= (1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF8)
		{
			ret->port->GPIOx_AFRH &= ~(1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF9)
		{
			ret->port->GPIOx_AFRH |= (1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF10)
		{
			ret->port->GPIOx_AFRH &= ~(1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF11)
		{
			ret->port->GPIOx_AFRH |= (1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF12)
		{
			ret->port->GPIOx_AFRH &= ~(1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF13)
		{
			ret->port->GPIOx_AFRH |= (1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH &= ~(1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF14)
		{
			ret->port->GPIOx_AFRH &= ~(1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+3));
		}
		else if (af == AF15)
		{
			ret->port->GPIOx_AFRH |= (1<<(((ret->pin)-8)*4));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+1));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+2));
			ret->port->GPIOx_AFRH |= (1<<((((ret->pin)-8)*4)+3));
		}

	}
}
