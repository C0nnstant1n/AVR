#ifndef MAIN_H_
#define MAIN_H_

//#define F_CPU 1200000UL //For Proteus
#define F_CPU 9600000UL //For my real tiny13a
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define P_LED PB4
#define SLEEP PB1
#define RESET PB5

#include "i2c.h"
#include "lcd.h"
#include "dht11.h"
#include "sleep.h"
#endif