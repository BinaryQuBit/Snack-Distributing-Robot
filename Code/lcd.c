// **************************************** lcd.c ***********************************************
// Project: Keil Labs and Project
// File: lcd.c
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
 
// ************************************** LCD setup *********************************************
void lcdSetup(void)	
{
	commandToLCD(LCD_8B2L);
	commandToLCD(0x0C);
	commandToLCD(0x06);
	commandToLCD(0x01);
}

// ********************************** Push Commands to LCD **************************************
void commandToLCD(uint8_t data)
{
	GPIOB->BSRR = LCD_CM_ENA; //RS low, E high
	GPIOC->ODR &= 0xFF00;
	GPIOC->ODR |= data;
	delay(150);
	GPIOB->BSRR = LCD_CM_DIS; //RS low, E high
	delay(150);
}

// ************************************ Push Data to LCD ****************************************
void dataToLCD(uint8_t data)
{
	GPIOB->BSRR = LCD_DM_ENA; //RS low, E high
	GPIOC->ODR &= 0xFF00;
	GPIOC->ODR |= data;
	delay(150);
	GPIOB->BSRR = LCD_DM_DIS; //RS low, E high
	delay(150);
}

// ************************************* String to LCD ******************************************
void stringToLCD(char *message)
{
	int i = 0;
  uint16_t messageLength = strlen(message);
  for (i = 0; i < messageLength; ++i)
  {
		dataToLCD(message[i]);
	}
}

// ******************************* Clearing the 2nd line ****************************************
void field2(void)
{
	commandToLCD(LCD_FLD2);
	dataToLCD(0x20);
	dataToLCD(0x20);
	dataToLCD(0x20);
	dataToLCD(0x20);	
	commandToLCD(LCD_FLD2);
}

// ******************************* Clearing the 4th line ****************************************
void field4(void)
{
	commandToLCD(LCD_FLD4);
	dataToLCD(0x20);
	dataToLCD(0x20);
	dataToLCD(0x20);
	dataToLCD(0x20);	
	commandToLCD(LCD_FLD4);
}

// *********************************** Clearing LCD *********************************************
void clear()
{
	commandToLCD(LCD_CLR);
}

// ****************************** Initial Setup on LCD ******************************************
void powerScreen()
{
	brightnessControl((readPhotoResistor()*(100.00/4095.00)));
	stringToLCD("     SNACK");
	commandToLCD(LCD_LN2);
	stringToLCD("  DISTRIBUTOR");
	delay(1500);
	commandToLCD(LCD_CLR);
	delay(1500);
	stringToLCD("     SNACK");
	commandToLCD(LCD_LN2);
	stringToLCD("  DISTRIBUTOR");
	delay(1500);
	commandToLCD(LCD_CLR);
	stringToLCD("   Get Ready!");
	delay(1500);
	commandToLCD(LCD_CLR);
	stringToLCD("  Power it On!");
	delay(3000);
	commandToLCD(LCD_CLR);
	completeGoForward();
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
