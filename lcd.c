/*******************************************************************************
 * MPLAB XC8 compiler LCD driver for LCDs with HD44780 compliant controllers.  *
 * This is a free software with NO WARRANTY.                                   *
 * https://simple-circuit.com/                                                 *
 *                                                                             *
 * LCD Driver source file lcd.c                                                *
 ******************************************************************************/


#include "lcd.h"
#include <xc.h>
#include <stdio.h>

volatile unsigned char *_port;
uint8_t LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7;
uint8_t _displaycontrol;

// initialize the connection between the microcontroller and the LCD
void LCD(volatile unsigned char *_p, uint8_t rs, uint8_t en, uint8_t d4,
        uint8_t d5, uint8_t d6, uint8_t d7)
{
    _port = _p;
    LCD_RS = rs;
    LCD_EN = en;
    LCD_D4 = d4;
    LCD_D5 = d5;
    LCD_D6 = d6;
    LCD_D7 = d7;
}
 
 // initialize the LCD by sending initialization commands in 4-bit mode
void LCD_Begin(uint8_t cols, uint8_t lines)
{
    uint8_t _function_set = LCD_FUNCTIONSET;
    // set initial state of connection pins to 0
    WritePin(LCD_RS, 0);
    WritePin(LCD_EN, 0);
    WritePin(LCD_D4, 0);
    WritePin(LCD_D5, 0);
    WritePin(LCD_D6, 0);
    WritePin(LCD_D7, 0);
    
    __delay_ms(2000);  // wait 2 seconds for the display to settle (voltage rise above 2.7V)
    
    if (lines > 1) {
        _function_set |= LCD_2Line;
    }
    
    // for 5x10 font size replace LCD_5x8Dots by LCD_5x10Dots
    _function_set |= LCD_5x8Dots;
    
    WriteNibble(0x03);
    __delay_ms(5);
    WriteNibble(0x03);
    __delay_us(200);
    WriteNibble(0x03);
    __delay_us(100);
    WriteNibble(0x02);
    __delay_us(100);
    
    WriteByte( _function_set );
    
    // turn the display ON with no cursor & no blink
    WriteByte( LCD_DISPLAYCONTROL | LCD_DISPLAYON );
    
    // clear LCD
    LCD_Clear();
    
    WriteByte( LCD_ENTRYMODESET | LCD_ENTRYMODE_LEFT );
    __delay_ms(2);
    _displaycontrol = LCD_DISPLAYCONTROL | LCD_DISPLAYON;
}

// move LCD cursor to position (col, row)
void LCD_Goto(uint8_t col, uint8_t row)
{
    WritePin(LCD_RS, 0);
    switch (row)
    {
        case 1: WriteByte(0x80 + col - 1); break;
        case 2: WriteByte(0xC0 + col - 1); break;
        case 3: WriteByte(0x94 + col - 1); break;
        case 4: WriteByte(0xD4 + col - 1); break;
    }
}

// clear the LCD
void LCD_Clear(void)
{
    WritePin(LCD_RS, 0);
    WriteByte( LCD_CLEARDISPLAY );
    __delay_ms(2);   // wait 2 ms for the function to execute
}

// print character 'c' on the LCD
void LCD_PutC(char c)
{
    WritePin(LCD_RS, 1);
    WriteByte(c);
}

void LCD_PutS(char* _str)
{
  WritePin(LCD_RS, 1);
  uint8_t i = 0;
  while(_str[i] != '\0')
      WriteByte( _str[i++] );
}

// turn the display ON or OFF according to the variable __display
// __display = true ==> display ON
// __display = false ==> display OFF
void LCD_Display(bool __display)
{
    WritePin(LCD_RS, 0);
    if (__display)
        _displaycontrol |= LCD_DISPLAYON;
    else
        _displaycontrol &= ~LCD_DISPLAYON;
    
    WriteByte( _displaycontrol );
}

// turn LCD cursor ON or OFF
// __cursor = true ==> Cursor ON
// __cursor = false ==> Cursor OFF
void LCD_CursorUnderline(bool __cursor)
{
   WritePin(LCD_RS, 0);
    if (__cursor)
        _displaycontrol |= LCD_UNDERLINEON;
    else
        _displaycontrol &= ~LCD_UNDERLINEON;
    
    WriteByte( _displaycontrol );
}

// make LCD cursor blinks
// __blink = true ==> Cursor blink ON
// __blink = false ==> Cursor blink OFF
void LCD_CursorBlink(bool __blink)
{
    WritePin(LCD_RS, 0);
    if (__blink)
        _displaycontrol |= LCD_CURSOR_BLINKON;
    else
        _displaycontrol &= ~LCD_CURSOR_BLINKON;
    
    WriteByte( _displaycontrol );
}

// shift the display to the left
void LCD_ShiftLeft(void)
{
    WritePin(LCD_RS, 0);
    WriteByte(LCD_DISPLAY_CURSORSHIFT | LCD_DISPLAYSHIFT | LCD_SHIFTLEFT);
}

// shift the display to the right
void LCD_ShiftRight(void)
{
    WritePin(LCD_RS, 0);
    WriteByte(LCD_DISPLAY_CURSORSHIFT | LCD_DISPLAYSHIFT | LCD_SHIFTRIGHT);
}

// move cursor to the left
void LCD_MoveCursorLeft(void)
{
    WritePin(LCD_RS, 0);
    WriteByte(LCD_DISPLAY_CURSORSHIFT | LCD_CURSORSHIFT | LCD_SHIFTLEFT);
}

// move cursor to the right
void LCD_MoveCursorRight(void)
{
    WritePin(LCD_RS, 0);
    WriteByte(LCD_DISPLAY_CURSORSHIFT | LCD_CURSORSHIFT | LCD_SHIFTRIGHT);
}


// move LCD cursor to the very first position (upper left position)
void LCD_ReturnHome(void)
{
    WritePin(LCD_RS, 0);
    WriteByte(LCD_RETURNHOME);
    __delay_ms(2);        // wait 2 ms for the function to execute
}

// write nibble (4 bits) to the LCD
void WriteNibble(uint8_t b)
{
    WritePin( LCD_D4, (b & 0x01) );
    WritePin( LCD_D5, (b & 0x02) );
    WritePin( LCD_D6, (b & 0x04) );
    WritePin( LCD_D7, (b & 0x08) );
    
    // send enable pulse
    EnablePulse();
}

// write 1 byte (8 bits) to the LCD
void WriteByte(uint8_t b)
{
    WriteNibble( b >> 4);
    WriteNibble(b);
}

// send enable pulse to the LCD with EN pin
void EnablePulse(void)
{
    WritePin(LCD_EN, 0);
    __delay_us(1);
    WritePin(LCD_EN, 1);
    __delay_us(1);
    WritePin(LCD_EN, 0);
    __delay_us(100);   // most commands requires more than 37us to execute
}

// digital write to a desired pin
void WritePin(uint8_t _pin, uint8_t val)
{
    if (val)
        *_port |= (1 << _pin);
    else
        *_port &= ~(1 << _pin);
}

// end of source code.