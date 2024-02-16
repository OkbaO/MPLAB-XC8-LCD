/*******************************************************************************
 * PIC18F46K42 Configuration words header file for MPLAB XC8 compiler          *
 * This is a free software with NO WARRANTY.                                   *
 * https://simple-circuit.com/                                                 *
 *                                                                             *
 * Microcontroller configuration words header file config.h                    *
 ******************************************************************************/

#ifndef _CONFIG_H
#define	_CONFIG_H

// CONFIG1L
#pragma config FEXTOSC = OFF   // External Oscillator Selection (Oscillator not enabled)
#pragma config RSTOSC = HFINTOSC_64MHZ  // Reset Oscillator Selection (HFINTOSC with HFFRQ = 64 MHz and CDIV = 1:1)

// CONFIG1H
#pragma config CLKOUTEN = OFF   // Clock out Enable bit (CLKOUT function is disabled)
#pragma config PR1WAY = OFF     // PRLOCKED One-Way Set Enable bit (PRLOCK bit can be set and cleared repeatedly)
#pragma config CSWEN = ON       // Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)

// CONFIG2L
#pragma config MCLRE = INTMCLR  // MCLR Enable bit (MCLR pin function is port defined function)
#pragma config PWRTS = PWRT_OFF   // Power-up timer selection bits (PWRT is disabled)
#pragma config MVECEN = OFF       // Multi-vector enable bit (Interrupt contoller does not use vector table to prioritze interrupts)
#pragma config IVT1WAY = OFF      // IVTLOCK bit One-way set enable bit (IVTLOCK bit can be cleared and set repeatedly)
#pragma config LPBOREN = OFF      // Low Power BOR Enable bit (ULPBOR disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable bits (Brown-out Reset disabled)

// CONFIG2H
#pragma config BORV = VBOR_2P45 // Brown-out Reset Voltage Selection bits (Brown-out Reset Voltage (VBOR) set to 2.45V)
#pragma config ZCD = OFF        // ZCD Disable bit (ZCD disabled. ZCD can be enabled by setting the ZCDSEN bit of ZCDCON)
#pragma config PPS1WAY = OFF    // PPSLOCK bit One-Way Set Enable bit (PPSLOCK bit can be set and cleared repeatedly (subject to the unlock sequence))
#pragma config STVREN = OFF     // Stack Full/Underflow Reset Enable bit ()
#pragma config DEBUG = OFF      // Debugger Enable bit (Background debugger disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Extended Instruction Set and Indexed Addressing Mode disabled)

// CONFIG3L
#pragma config WDTCPS = WDTCPS_0  // WDT Period selection bits (Divider ratio 1:32)
#pragma config WDTE = OFF         // WDT operating mode (WDT Disabled; SWDTEN is ignored)

// CONFIG3H
#pragma config WDTCWS = WDTCWS_0   // WDT Window Select bits (window delay = 87.5; no software control; keyed access required)
#pragma config WDTCCS = LFINTOSC   // WDT input clock selector (WDT reference clock is the 31.0 kHz LFINTOSC)


// CONFIG4L
#pragma config BBSIZE = BBSIZE_512  // Boot Block Size selection bits (Boot Block size is 512 words)
#pragma config BBEN = OFF           // Boot Block enable bit (Boot block disabled)
#pragma config SAFEN = OFF          // Storage Area Flash enable bit (SAF disabled)
#pragma config WRTAPP = OFF         // Application Block write protection bit (Application Block not write protected)

// CONFIG4H
#pragma config WRTB = OFF     // Boot Block Write Protection bit (Boot Block not write-protected)
#pragma config WRTC = OFF     // Configuration Register Write Protection bit (Configuration registers not write-protected)
#pragma config WRTD = OFF     // Data EEPROM Write Protection bit (Data EEPROM not write-protected)
#pragma config WRTSAF = OFF   // SAF Write protection bit (SAF not Write Protected)
#pragma config LVP = OFF      // Low Voltage Programming Enable bit (HV on MCLR/VPP must be used for programming)

// CONFIG5L
#pragma config CP = OFF        // PFM and Data EEPROM Code Protection bit (PFM and Data EEPROM code protection disabled)

#endif