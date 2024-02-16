/*****************************************************************
 * Interfacing PIC18F46K42 microcontroller with 2004 LCD screen.
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
    OSCCON1 = 0x60;   // Clock source configuration, HFINTOSC, CDIV = 1:1
    OSCFRQ  = 0x03;   // Set internal clock frequency to 8 MHz
    
    TRISD  = 0;  // Initial state of PORTD pins
    ANSELD = 0;  // Configure all PORTD pins as digital
    
    // set the connection between the MCU and the LCD (&PORT, RS, E, D4, D5, D6, D7)
    LCD(&LATD, 0, 1, 2, 3, 4, 5);

    // initialize the LCD module with 20 rows and 4 columns (20x4 LCD)
    LCD_Begin(20, 4);
    
    LCD_CursorBlink(true);  // turn on blinking cursor
    
    // print texts on the display
    LCD_Goto(1, 1);  // move cursor to position (1, 1) --> column = 1 and row = 1
    LCD_PutS("PIC18F46K42 MCU +");
    __delay_ms(2000);
    LCD_Goto(1, 2);  // move cursor to position (1, 2) --> column = 1 and row = 2
    LCD_PutS("20x4 LCD Example");
    __delay_ms(2000);
    LCD_Goto(1, 3);  // move cursor to position (1, 4) --> column = 1 and row = 3
    LCD_PutS("Microchip MPLAB");
    __delay_ms(2000);
    LCD_Goto(1, 4);  // move cursor to position (1, 4) --> column = 1 and row = 4
    LCD_PutS("XC8 Compiler");
    
    __delay_ms(5000);
    LCD_Clear();   // clear the display
    
    LCD_Goto(7, 1);  // move cursor to position (7, 1) --> column = 7 and row = 1
    LCD_PutS("LINE 1");
    __delay_ms(2000);
    LCD_Goto(7, 2);  // move cursor to position (, 2) --> column = 7 and row = 2
    LCD_PutS("LINE 2");
    __delay_ms(2000);
    LCD_Goto(7, 3);  // move cursor to position (7, 4) --> column = 7 and row = 3
    LCD_PutS("LINE 3");
    __delay_ms(2000);
    LCD_Goto(7, 4);  // move cursor to position (7, 4) --> column = 7 and row = 4
    LCD_PutS("LINE 4");
    
    __delay_ms(5000);
    LCD_CursorBlink(false);  // turn off blinking cursor
    LCD_Clear();   // clear the display
    
    // ADC Module configuration
    ADCON0bits.FM = 1;  // Right justify of ADC result
    ADCON0bits.CS = 1;  // ADC module uses internal fixed-frequency clock source
    ADCON0bits.ON = 1;  // Turn the ADC module on
    
    uint16_t pot1, pot2;
    LCD_Goto(1, 1);  // move cursor to position (1, 1) --> column = 1 and row = 1
    LCD_PutS("Potentiometer 1:");
    LCD_Goto(1, 3);  // move cursor to position (1, 3) --> column = 1 and row = 3
    LCD_PutS("Potentiometer 2:");
    
    while (1)
    {
        // Get ADC result from POT1 (analog channel ANA0)
        ADPCH = 0x00;           // Select analog channel ANA0
        __delay_us(10);         // A delay is required between changing channel and start conversion
        ADCON0bits.GO = 1;      // Start conversion
        while (ADCON0bits.GO);  // Wait for the conversion to complete
        // Store conversion result in the variable 'pot1' where,
        // ADRESH is result high byte (highest 4 bits), and ADRESL is result low byte (lowest 8 bits)
        pot1 = ((uint16_t)ADRESH << 8) | ADRESL;
        
        // Get ADC result from POT2 (analog channel ANA1)
        ADPCH = 0x01;           // Select analog channel ANA1
        __delay_us(10);         // A delay is required between changing channel and start conversion
        ADCON0bits.GO = 1;      // Start conversion
        while (ADCON0bits.GO);  // Wait for the conversion to complete
        // Store conversion result in the variable 'pot1' where,
        // ADRESH is result high byte (highest 4 bits), and ADRESL is result low byte (lowest 8 bits)
        pot2 = ((uint16_t)ADRESH << 8) | ADRESL;
        
        // Print POT1 and POT2 digital values on the 20x4 LCD
        LCD_Goto(1, 2);  // move cursor to position (1, 1) --> column = 1 and row = 1
        printf("%u   ", pot1);
        LCD_Goto(1, 4);  // move cursor to position (1, 1) --> column = 1 and row = 1
        printf("%u   ", pot2);
        
        __delay_ms(400);
    }
    
}

// End of code.