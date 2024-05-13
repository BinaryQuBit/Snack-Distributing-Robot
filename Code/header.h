// *************************************** header.h *********************************************
// Project: Keil Labs and Project
// File: header.h
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
#include <stdint.h>

// ********************************* LCD Port Addresses *****************************************
#define LCD_8B2L 	0x38		//		; Enable 8 bit data, 2 display lines
#define LCD_DCB		0x0F		//		; Enable Display, Cursor, Blink
#define LCD_MCR		0x06		//		; Set Move Cursor Right
#define LCD_CLR		0X01		//		; Home and clear LCD
#define LCD_LN1		0X80		//		;	Set DDRAM to start of line 1
#define LCD_LN2		0XC0		//		; Set DDRAM to start of line 2
#define LCD_FLD2	0X8C		//		; Set DDRAM to 13th position on line 1
#define LCD_FLD4	0XCC		//		; Set DDRAM to 13th position on line 2

// ****** Control signal manipulation for LCDs on 352/384/387 board PB0:RS PB1:ENA PB5:R/W ******
#define LCD_CM_ENA	0X00210002
#define LCD_CM_DIS	0x00230000
#define LCD_DM_ENA	0x00200003
#define LCD_DM_DIS	0x00220001

// ************* A delay function used for delaying the processor to a certain speed ************
void delay(int);

// ******************************** Configuration of clocks *************************************
void clockInit(void);

// ********************** Enabling certain ports like IO / AFIO / ADC ***************************
void portEnable(void);

// ************************* Configuring certain pins on the ports ******************************
void pinConfigure(void);

// ********************************** Read Pressure Sensor **************************************
int readPressure(void);

// ****************************** Read Photo Resistor Sensor ************************************
int readPhotoResistor(void);

// ******************************* Instructions to run it all ***********************************
void led_sequence_all(void);

// ************************** Instructions to run 1st LED Sequence ******************************
void led_sequence1(void);

// ************************** Instructions to run 2nd LED Sequence ******************************
void led_sequence2(void);

// ************************** Instructions to run 3rd LED Sequence ******************************
void led_sequence3(void);

// ************************** Instructions to run 4th LED Sequence ******************************
void led_sequence4(void);

// ****************************** Instructions to run USER LED **********************************
void ledTest(void);

// ***************************** Instructions to stop USER LED **********************************
void stopLedTest(void);

// *************************** Instructions to move left forward ********************************
void leftForward();

// ************************** Instructions to move left backward ********************************
void leftReverse(void);

// ******************************* Instructions to stop left ************************************
void leftStop(void);

// ************************** Instructions to move right forward ********************************
void rightForward(void);

// ************************* Instructions to move right backward ********************************
void rightReverse(void);

// ****************************** Instructions to stop right ************************************
void rightStop(void);

// ************************ Instructions to run all wheels forward ******************************
void completeGoForward();

// **************************** Instructions to stop all wheels *********************************
void completeStop(void);

// ******************************* Instructions to clear LCD ************************************
void lcdClear(void);

// *************************** Instructions to control Brightness *******************************
void brightnessControl(int);

// ****************************** Instructions to setup LCD *************************************
void lcdSetup(void);

// ************************* Instructions to send commands to LCD *******************************
void commandToLCD(uint8_t);

// ************************** Instructions to send string to LCD ********************************
void stringToLCD(char *);

// *************************** Instructions to send data to LCD *********************************
void dataToLCD(uint8_t);

// ************************** Instructions to clear second line *********************************
void field2(void);

// ************************** Instructions to clear fourth line *********************************
void field4(void);

// ************************* Instructions to clear the whole LCD ********************************
void clear(void);

// ************************** Initial Instructions to run on LCD ********************************
void powerScreen(void);

// ***************** Instructions to Calculate Distance using Ultra Sonic Sensor ****************
float calculateDistance();

// ******************* Timer for Ultra Sonic Sensor to help calculate distance ******************
void timerDelay(uint32_t);

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
