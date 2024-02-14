/*****************************************************************
 * Interfacing PIC18F46K22 microcontroller with 1602 LCD screen.
 * Internal oscillator used @ 8MHz.
 * Tested with MPLAB XC8 compiler version v2.40 (C99) with
 *   free optimization level 1.
 * 
 * This is a free software with NO WARRANTY.
 * https://simple-circuit.com/

******************************************************************/

// disable warning 520 (function is never called)!
// to enable it just remove or comment the line below
#pragma warning disable 520

#include "config.h"  // include microcontroller configuration header file
#include <xc.h>      // include main compiler header file
#include <stdio.h>   // include stdio header file, required for 'printf' function
#include "../lcd.h"  // include LCD library header file
uint32_t _XTAL_FREQ = 8000000;  // set clock frequency to 8 MHz

// 'putch' function is required for the 'printf' function to work
// here it is used to print a character on the LCD using the function 'LCD_PutC'
void putch(char c)
{
    LCD_PutC(c);
}

// main function
void main(void)
{
    OSCCON = 0x6C;  // use internal oscillator @ 8MHz
    
    TRISD  = 0;   // configure all port D pins as outputs
    ANSELD = 0;   // configure all port D pins as digital pins
    
    // set the connection between the MCU and the LCD
    LCD(&PORTD, 0, 1, 2, 3, 4, 5);

    // initialize the LCD module with 16 rows and 2 columns (1602 LCD)
    LCD_Begin(16, 2);
    
    // print a list of characters on the display
    LCD_Goto(1, 1);  // move cursor to position (1, 1) --> column = 1 and row = 1
    LCD_PutC('L');
    LCD_PutC('C');
    LCD_PutC('D');
    
    __delay_ms(5000);
    LCD_Clear();       // clear the display
    
    // print a text (string) on the display)
    LCD_Goto(1, 1);  // move cursor to position (1, 1) --> column = 1 and row = 1
    LCD_PutS("Hello, world!");
    
    __delay_ms(5000);
    
    // print an incremented number using 'printf' function
    uint8_t i = 0;
    while (1)
    {   // stay here forever!
        LCD_Goto(1, 2);  // move cursor to position (1, 2) --> column = 1 and row = 2
        printf("i = %03u", i);
        i = i + 1;  // increment 'i' by 1
        __delay_ms(1000);
    }
}

// end of code.