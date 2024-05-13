// ***************************************** adc.c **********************************************
// Project: Keil Labs and Project
// File: adc.c
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

// ************************** ADC Function to Read Pressure**************************************

int readPressure(void)
{
	ADC1 -> SQR3 = 0x00000000;
	ADC1 -> CR2 |= ADC_CR2_ADON;
	while(!(ADC1->SR & ADC_SR_EOC))
	{}
		return ADC1->DR;
}

// ***************************** ADC Function to Read PhotoResistor ******************************

int readPhotoResistor(void)
{
	ADC2 -> SQR3 = 0x00000001;
	ADC2 -> CR2 |= ADC_CR2_ADON;
	while(!(ADC2 -> SR & ADC_SR_EOC))
	{}
		return ADC2 -> DR;
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