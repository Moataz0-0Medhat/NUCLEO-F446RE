/*
 * gpio.h
 *
 *  Created on: Jul 9, 2023
 *      Author: moata
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "rd.h"
#include <stdint.h>

#define gpio_null -1

typedef enum {
    gpio_pin0, gpio_pin1, gpio_pin2, gpio_pin3, gpio_pin4, gpio_pin5,
    gpio_pin6, gpio_pin7, gpio_pin8, gpio_pin9, gpio_pin10, gpio_pin11,
    gpio_pin12, gpio_pin13, gpio_pin14, gpio_pin15
} gpio_pin_t;

typedef enum {
    AF0, AF1, AF2, AF3, AF4, AF5, AF6, AF7, AF8, AF9, AF10, AF11,
    AF12, AF13, AF14, AF15
} pin_alternate_t;


typedef enum
{
	pin_mode_input, pin_mode_output, pin_mode_alternate_fun, pin_mode_analog

}pin_mode_t;

typedef enum
{
	no_pull, pull_up, pull_down

}pin_pull_t;

typedef enum
{
	 pin_low , pin_high

}pin_level_t;

typedef enum
{
	pin_speed_low, pin_speed_medium, high, pin_speed_very_high

}pin_speed_t;


typedef enum
{
	pin_push_pull, pin_open_drain

}pin_output_type_t;


typedef struct
{
	volatile gpio_t* port; 					 // GPIO PORT
	gpio_pin_t pin;    		        // GPIO PIN number
	pin_alternate_t af;
	pin_mode_t mode;  			   // GPIO PIN MODE
	pin_pull_t pupd;			 	// pull up or pull down
	uint8_t ospeed;  			 // output speed
	pin_output_type_t otype;  			  // Output type


}pin_t;

pin_t pin_init( volatile gpio_t* port, gpio_pin_t pin, pin_mode_t mode, pin_output_type_t otype, pin_pull_t pupd );
void pin_level(pin_t *ret , uint8_t level);
uint8_t pin_read(pin_t* ret);
void pin_af(pin_t* ret, pin_alternate_t af);
#endif /* GPIO_H_ */
