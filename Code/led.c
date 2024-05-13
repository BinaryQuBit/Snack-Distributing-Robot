// ***************************************** led.c **********************************************
// Project: Keil Labs and Project
// File: led.c
// Class: ENEL 351 Lab Works
// Programmer: Amandip Padda
// SID: 200455829
// Description: The project is based on the STM32F103RB that is being used in ENEL 351 Labs.
// It will also be used in the Project related to input and output of various sensors.

// ==============================================================================================
// **************************************IMPORTANT***********************************************
//                         Copyright (c) 2023. All rights reserved. 
//                    See the bottom of this file for the license terms.
// ==============================================================================================

// ************************************ Header Files ********************************************
#include "stm32f10x.h"
#include "header.h" 

// ********************** Function defination to run all LED Sequences **************************
void led_sequence_all(void)
{
	while(1)
	{
		if((GPIOC -> IDR & GPIO_IDR_IDR0) == 0x1)
		{
			led_sequence1();
		}
		if((GPIOC -> IDR & GPIO_IDR_IDR1) == 0x2)
		{
			led_sequence2();
		}
		if((GPIOC -> IDR & GPIO_IDR_IDR2) == 0x4)
		{
			led_sequence3();
		}
		if((GPIOC -> IDR & GPIO_IDR_IDR3) == 0x8)
		{
			led_sequence4();
		}
	}
}

// ************************** Function defination to run 1st Sequence ***************************
void led_sequence1(void)
{
	GPIOA->ODR |= GPIO_ODR_ODR7;
	delay(80000);
	GPIOA->ODR &= ~GPIO_ODR_ODR7;
	delay(80000);
	GPIOA->ODR |= GPIO_ODR_ODR8;
	delay(80000);
	GPIOA->ODR &= ~GPIO_ODR_ODR8;
	delay(80000);
	GPIOA->ODR |= GPIO_ODR_ODR9;
	delay(80000);
	GPIOA->ODR &= ~GPIO_ODR_ODR9;
	delay(80000);
	GPIOA->ODR |= GPIO_ODR_ODR10;
	delay(80000);
	GPIOA->ODR &= ~GPIO_ODR_ODR10;
	delay(80000);
}

// *************************** Function defination to run 2nd Sequence **************************
void led_sequence2(void)
{
	delay(80000);
	GPIOA->ODR &= ~GPIO_ODR_ODR10;
	delay(80000);
	GPIOA->ODR |= GPIO_ODR_ODR9;
	delay(80000);
	GPIOA->ODR &= ~GPIO_ODR_ODR9;
	delay(80000);
	GPIOA->ODR |= GPIO_ODR_ODR8;
	delay(80000);
	GPIOA->ODR &= ~GPIO_ODR_ODR8;
	delay(80000);
	GPIOA->ODR |= GPIO_ODR_ODR7;
	delay(80000);
	GPIOA->ODR &= ~GPIO_ODR_ODR7;
	delay(80000);
}

// **************************** Function defination to run 3rd Sequence ************************
void led_sequence3(void)
{
	GPIOA->ODR |= GPIO_ODR_ODR7;
	delay(80000);
	GPIOA->ODR &= ~GPIO_ODR_ODR7;
	delay(80000);
	GPIOA->ODR |= GPIO_ODR_ODR9;
	delay(80000);
	GPIOA->ODR &= ~GPIO_ODR_ODR9;
	delay(80000);
}

// **************************** Function defination to run 4th Sequence ***********************
void led_sequence4(void)
{
	GPIOA->ODR |= GPIO_ODR_ODR10;
	delay(80000);
	GPIOA->ODR &= ~GPIO_ODR_ODR10;
	delay(80000);
	GPIOA->ODR |= GPIO_ODR_ODR8;
	delay(80000);
	GPIOA->ODR &= ~GPIO_ODR_ODR8;
	delay(80000);
}

// ****************************** Function defination to run USER LED ************************
void ledTest(void)
{
	GPIOA->ODR |= GPIO_ODR_ODR5;
	delay(1000);
	GPIOA->ODR &= ~GPIO_ODR_ODR5;
	delay(1000);
}

// ***************************** Function defination to stop USER LED ************************
void stopLedTest(void)
{
	GPIOA->ODR &= ~GPIO_ODR_ODR5;
}

// ==============================================================================================
// **************************************IMPORTANT***********************************************
//                           Copyright (c) 2016. All rights reserved.
// This library is free software; you can redistribute it and/or modify it under the terms of the
// GNU Lesser General Public License as published by the Free Software Foundation; either version 
// 2.1 of the License, or (at your option) any later version. This library is distributed in the 
// hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
// for more details. You should have received a copy of the GNU Lesser General Public License along
// with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, 
// Fifth Floor, Boston, MA  02110-1301  USA
// ==============================================================================================
