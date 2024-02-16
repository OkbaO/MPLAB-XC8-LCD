/*******************************************************************************
 * MPLAB XC8 compiler LCD driver for LCDs with HD44780 compliant controllers.  *
 * This is a free software with NO WARRANTY.                                   *
 * https://simple-circuit.com/                                                 *
 *                                                                             *
 * LCD Driver header file lcd.h                                                *
 ******************************************************************************/

#ifndef __LCD_h
#define __LCD_h

#include <stdbool.h>
#include <stdint.h>
extern uint32_t _XTAL_FREQ;

// LCD commands
#define LCD_CLEARDISPLAY   0x01
#define LCD_RETURNHOME     0x02
#define LCD_ENTRYMODESET   0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_DISPLAY_CURSORSHIFT    0x10
#define LCD_FUNCTIONSET    0x20
#define LCD_SETCGRAMADDR   0x40
#define LCD_SETDDRAMADDR   0x80

// flags for display entry mode (or'ed with LCD_ENTRYMODESET command)
#define LCD_ENTRYMODE_RIGHT 0x00
#define LCD_ENTRYMODE_LEFT 0x02
#define LCD_ENTRYMODE_SHIFTINCREMENT 0x01
#define LCD_ENTRYMODE_SHIFTDECREMENT 0x00

// display & cursor control (or'ed with LCD_DISPLAYCONTROL command)
#define LCD_DISPLAYON      0x04
#define LCD_UNDERLINEON    0x02
#define LCD_CURSOR_BLINKON 0x01

// cursor or display shift
#define LCD_DISPLAYSHIFT 0x08
#define LCD_CURSORSHIFT  0x00
#define LCD_SHIFTRIGHT   0x04
#define LCD_SHIFTLEFT    0x00

// function set flags
#define LCD_4Bit     0x00
#define LCD_8Bit     0x10
#define LCD_1Line    0x00
#define LCD_2Line    0x08
#define LCD_5x8Dots  0x00
#define LCD_5x10Dots 0x04

void LCD(volatile unsigned char *_p, uint8_t rs, uint8_t en, uint8_t d4,
        uint8_t d5, uint8_t d6, uint8_t d7);
// user functions
void LCD_Begin(uint8_t cols, uint8_t lines);
void LCD_Clear(void);
void LCD_Goto(uint8_t col, uint8_t row);
void LCD_Display(bool __display);
void LCD_CursorUnderline(bool __cursor);
void LCD_CursorBlink(bool __blink);
void LCD_ReturnHome(void);
void LCD_ShiftLeft(void);
void LCD_ShiftRight(void);
void LCD_MoveCursorLeft(void);
void LCD_MoveCursorRight(void);
void LCD_PutC(char c);
void LCD_PutS(char* _str);

// non-user functions
void WriteNibble(uint8_t b);
void WriteByte(uint8_t b);
void EnablePulse(void);
void WritePin(uint8_t _pin, uint8_t val);

#endif

// end of header code