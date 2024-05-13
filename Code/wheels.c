// ************************************ wheels.c ************************************************
// Project: Keil Labs and Project
// File: wheels.c
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

// ****************** Function Defination to move left set of tires forward *********************
void leftForward()
{
	GPIOA->ODR |= GPIO_ODR_ODR8;
}

// ***************** Function Defination to move left set of tires backward *********************
void leftReverse()
{
	GPIOA->ODR |= GPIO_ODR_ODR9;
}

// ********************** Function Defination to stop left set of tires *************************
void leftStop()
{
	GPIOA->ODR &= ~GPIO_ODR_ODR8;
	GPIOA->ODR &= ~GPIO_ODR_ODR9;
}

// ***************** Function Defination to move right set of tires forward *********************
void rightForward()
{
	GPIOA->ODR |= GPIO_ODR_ODR10;
}

// ***************** Function Defination to move right set of tires backward ********************
void rightReverse()
{
	GPIOA->ODR |= GPIO_ODR_ODR11;
}

// ********************* Function Defination to stop right set of tires *************************
void rightStop()
{
	GPIOA->ODR &= ~GPIO_ODR_ODR10;
	GPIOA->ODR &= ~GPIO_ODR_ODR11;
}

// ********************** Function Defination to move forward (4 by 4) **************************
void completeGoForward()
{
	leftForward();
	rightForward();
}

// ********************** Function Defination to move reverse (4 by 4) **************************
void completeStop()
{
	leftStop();
	rightStop();
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
