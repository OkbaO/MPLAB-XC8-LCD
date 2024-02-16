/*****************************************************************
 * Interfacing PIC16F877A microcontroller with 1602 LCD screen.
 * External crystal oscillator used @ 8MHz.
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

void main(void)
{
    PORTD = 0;
    TRISD  = 0;   // configure all port D pins as outputs
    
    // set the connection between the MCU and the LCD (&PORTx, RS, E, D4, D5, D6, D7)
    LCD(&PORTD, 0, 1, 2, 3, 4, 5);

    // initialize the LCD module with 16 rows and 2 columns (1602 LCD)
    LCD_Begin(16, 2);
    
    // print texts on the display
    LCD_Goto(1, 1);  // move cursor to position (1, 1) --> column = 1 and row = 1
    LCD_PutS("PIC16F877A + LCD");
    LCD_Goto(1, 2);  // move cursor to position (1, 2) --> column = 1 and row = 2
    LCD_PutS("MPLAB XC8");
    
    while (1) ; // stay here
}

// end of code.