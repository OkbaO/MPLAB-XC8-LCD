# MPLAB-XC8-LCD
MPLAB XC8 Compiler library for LCD modules based on HD44780U or compatible Controller

# Overview
This library/driver helps interfacing Microchip PIC microcontroller with LCD modules with controller HD44780, using MPLAB XC8 compiler. The main files for the library are: **lcd.h** and **lcd.c**.

This library was tested with MPLAB XC8 version V2.40, three types of PIC microcontrollers are used: PIC16F877A, PIC18F46K22, and PIC18F46K42.

Circuit schematics for the three examples at:

https://simple-circuit.com/interfacing-pic-microcontroller-with-lcd-mplab-xc8/

# User Functions:
* LCD(volatile unsigned char *_p, uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);

**Example:** LCD(&LATD, 0, 1, 2, 3, 4, 5);

* LCD_Begin(uint8_t cols, uint8_t lines);

**Example:** LCD_Begin(20, 4);

* LCD_Clear(void);

**Example:** LCD_Clear();

* LCD_Goto(uint8_t col, uint8_t row);

Example: LCD_Goto(7, 1);

* LCD_Display(bool __display);

**Example:** LCD_Display(true);

* LCD_CursorUnderline(bool __cursor);

**Example:** LCD_CursorUnderline(true);

* LCD_CursorBlink(bool __blink);

**Example:** LCD_CursorBlink(true);

* LCD_ReturnHome(void);

**Example:** LCD_ReturnHome();

* LCD_ShiftLeft(void);

**Example:** LCD_ShiftLeft();

* LCD_ShiftRight(void);

**Example:** LCD_ShiftRight();

* LCD_MoveCursorLeft(void);

**Example:** LCD_MoveCursorLeft();

* LCD_MoveCursorRight(void);

**Example:** LCD_MoveCursorRight();

* LCD_PutC(char c);

**Example:** LCD_PutC('A');

* LCD_PutS(char* _str);

**Example:** LCD_PutS("Hello, world!");
