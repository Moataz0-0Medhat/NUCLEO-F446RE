/*
 * bits.h
 *
 *  Created on: Jul 8, 2023
 *      Author: moham
 */

#ifndef BITS_H_
#define BITS_H_

#define set_bit(x,n) (x |= (1<<n))
#define clr_bit(x,n) (x &= ~(1<<n))
#define get_bit(x,n) ((x>>n)&1)
#define tog_bit(x,n) (x ^= (1<<n))

#endif /* BITS_H_ */
