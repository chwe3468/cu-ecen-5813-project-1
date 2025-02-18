/*
 * timer.h
 *
 *  Created on: Feb 11, 2020
 *      Author: chutao
 */

#ifndef TIMER_H_
#define TIMER_H_


/*************** Include *****************/

#include <stdint.h>

/*************** Define *****************/

#define CPU_FREQ_MHZ	(48)
#define NUM_ASSE_FOR	(7)


/*************** Prototype *****************/

/*************************************************
 * @brief
 *   Block delay for msec amount of microsecond
 ************************************************/
void delay_ms(uint32_t msec);
void pc_run(void);
void time_it(double delay);

#endif /* TIMER_H_ */
