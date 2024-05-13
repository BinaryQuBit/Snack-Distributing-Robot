//**************************************** main.c ***********************************************
// Project: Keil Labs and Project
// File: main.c
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

// ************************************* Header Files *******************************************
#include "stm32f10x.h"
#include "header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ********************* Interrupt Handler to handle Line Tracking Sensors **********************
void EXTI9_5_IRQHandler(void)
{
	if (EXTI -> PR & (1 << 5)) // Line 5 Checker
	{
		completeStop();
		leftReverse();
		rightForward();
    EXTI -> PR |= (1 << 5); // Line 5 Clear
  }
  if (EXTI -> PR & (1 << 6)) // Line 6 Checker
	{
		completeStop();
		rightReverse();
		leftForward();
    EXTI -> PR |= (1 << 6); // Line 6 Clear
	}
}

// **************************************** Main Starts *****************************************
int main(void)
{
	clockInit(); // Clock Set Up
  portEnable(); // Emable Port Clocks
  pinConfigure(); // Pin Config
	lcdSetup(); // LCD Setup
  char message[20];
	powerScreen();
  while(1)
  {
		float photoResistor = (readPhotoResistor()*(100.00/4095.00));
		float pressure = (readPressure()*(500.00/4095.00));
		brightnessControl(photoResistor);
    float distance = calculateDistance();
		completeGoForward();
		if (distance > 0)
		{
			if (distance < 5)
			{
				completeStop();
				ledTest();
				sprintf(message, " Weight : %.2f", pressure);
				stringToLCD(message);
				delay(1200);
				clear();
			}
			else
			{
				if ((GPIOB->IDR & GPIO_IDR_IDR5) > 0)
				{

					stringToLCD("   Travelling   ");
					stringToLCD(message);
					delay(500);
					clear();
				}
				else if ((GPIOB->IDR & GPIO_IDR_IDR6) > 0)
				{

					stringToLCD("   Travelling   ");
					stringToLCD(message);
					delay(500);
					clear();
				}
				else
				{
					completeStop();
					completeGoForward();
					stopLedTest();
					stringToLCD("   Travelling   ");
					stringToLCD(message);
					delay(500);
					clear();
				}
			}
		}
	}
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
