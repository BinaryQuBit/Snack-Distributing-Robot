// **************************************** sonic.c *********************************************
// Project: Keil Labs and Project
// File: sonic.c
// Class: ENEL 351 Lab Works
// Programmer: Amandip Padda
// Advicer/Helper: Ramanpreet Singh
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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ************************ Timer Delay (Helper for Ultra Sonic)*********************************************
void timerDelay(uint32_t delay)
{
	TIM2 -> ARR = (SystemCoreClock / 1000000) * delay - 1; // Timer in ms
	TIM2 -> CNT = 0; // Counter to zero
	TIM2 -> CR1 |= TIM_CR1_CEN; // Start
	while(!(TIM2->SR & TIM_SR_UIF)) // Wait
	{}
	TIM2 -> SR &= ~(TIM_SR_UIF); // Clear UIF flag (Update Interrupt Flag)
}


float calculateDistance()
{
	GPIOB -> BSRR |= GPIO_BSRR_BR8; // PB8 = Low
	timerDelay(2); // Delay 2 microsenconds
	GPIOB -> BSRR |= GPIO_BSRR_BS8; // PB8 = High
	timerDelay(10); // Delay 10 microsenconds
	GPIOB -> BSRR |= GPIO_BSRR_BR8; // Set PB8 = Low
	uint32_t counter = 0;
	while(GPIOB -> IDR & GPIO_IDR_IDR9) // Input Read
	{
		counter++;
  }
  float timeSeconds = counter * (0.0625 / 1000000); // Time in Seconds
  float distanceCM = (timeSeconds * 343 / 2) * 100; // Distance in Centimeter
  return distanceCM;
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
