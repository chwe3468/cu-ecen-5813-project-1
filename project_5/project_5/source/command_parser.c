/*
 * command_parser.c
 *
 *  Created on: Mar 9, 2020
 *      Author: Curry
 */

/********************** Include ***********************/

#include "command_parser.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "led.h"
#include "logger.h"
/********************** Define ***********************/
#define MAX_USER_BUF 64
#define MAX_USER_ARG 4



/********************** Function ***********************/
void command_parser(void)
{
	// Initialize char array
	uint8_t str[MAX_USER_BUF];

	uint8_t i = 0;
    turn_LED_blue(on);
	//takes all the characters until enter is pressed
	while((str[i]=getchar())!='\n'){
		//increment the index of the character array
		i++;
		// protect against long input
		if(i == MAX_USER_BUF-1)
		{
		    str[MAX_USER_BUF-1] = '\n';
		    LOG_ERROR("user input too long, the rest of the string will be counted next time \n");
		    break;
		}
	}
	turn_LED_blue(off);

	i = 0;
	uint8_t char_count[255];
	memset(char_count,0,255);
	// go through the string
	while(str[i]!='\n')
	{
		// count which character is incremented
		char_count[str[i]]++;
		i++;
	}
	turn_LED_green(on);

	// print them out
	i = 'A';
	while(i<='Z')
	{
		if(char_count[i]!=0)
		{
			printf("%c - %u; ",i,char_count[i]);
		}
		i++;
	}
	i = 'a';
	while(i<='z')
	{
		if(char_count[i]!=0)
		{
			printf("%c - %u; ",i,char_count[i]);
		}
		i++;
	}
	printf("\n");
	printf("\n");
	turn_LED_green(off);
}
