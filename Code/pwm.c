// ************************************** pwm.c *************************************************
// Project: Keil Labs and Project
// File: pwm.c
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

// ********************* Function Defination to control brightness of LCD ***********************
void brightnessControl(int photoSensorValue)
{
	TIM3 -> CR1 |= TIM_CR1_CEN; // Enable Timer 3
	TIM3 -> EGR |= TIM_EGR_UG; // Setting counter and Reloading Prescaler
	TIM3 -> CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1; // Capture
	TIM3 -> CCMR1 |= TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE; // Preload Enable, Fast Enable
	TIM3 -> CCER |= TIM_CCER_CC1E; // Enable Channel One
	TIM3 -> PSC = 0x1C1F; // (72 * 100) - 1 = 7199 or 0x1C1F; for 100 kHz
	TIM3 -> ARR = 100.00; // 100 kHz
	TIM3 -> CCR1 = photoSensorValue; // Duty cycle depended on photo Resistor Value
	TIM3 -> CR1 |= TIM_CR1_ARPE; // ARPE = Auto Reload Preload Enable
	TIM3 -> CR1 |= TIM_CR1_CEN; // Enable Timer3
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
