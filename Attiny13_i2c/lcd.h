/*
 * lcd.h
 *
 * Created: 03.10.2024 18:52:28
 *  Author: Konstantin
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "main.h"
#include <stdlib.h>

#define RS 0
#define RW 1
#define E 2
#define BACK_LIGHT 3
#define min_time_command _delay_us(50)
#define LCD_ADR 0x4e

void lcd_init(void);
void sendToInterface(uint8_t d);
void sendByte(uint8_t data, uint8_t type);
void sendHiHalfByte(uint8_t d);
void sendLowHalfByte(uint8_t d);
void lcdString(char* str);
void setCursor(uint8_t line, uint8_t pos);
void cls(void);
void numToStr(uint8_t num);

#endif /* LCD_H_ */