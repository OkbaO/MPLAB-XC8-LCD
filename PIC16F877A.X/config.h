/*******************************************************************************
 * PIC18F46K22 Configuration bits header file for MPLAB XC8 compiler           *
 * This is a free software with NO WARRANTY.                                   *
 * https://simple-circuit.com/                                                 *
 *                                                                             *
 * Microcontroller configuration header file config.h                          *
 ******************************************************************************/

#ifndef _CONFIG_H
#define	_CONFIG_H

#pragma config FOSC = HS   // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF  // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON  // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF   // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF   // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF   // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config DEBUG = OFF // In-Circuit Debugger Mode bit (In-Circuit Debugger disabled, RB6 and RB7 are general purpose I/O pins)
#pragma config CP = OFF    // Flash Program Memory Code Protection bit (Code protection off)

#endif