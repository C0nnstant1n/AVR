/*
 * dht11.h
 *
 * Created: 06.10.2024 15:33:24
 *  Author: Konstantin
 */ 


#ifndef DHT11_H_
#define DHT11_H_

#include "main.h"

#define DHT_DDR		DDRB
#define DHT_PIN		PINB
#define DHT_PORT	PORTB
#define DHT			PB3

uint8_t dht_start(void);
uint8_t dht_byte(void);
uint8_t dht_read(uint8_t *hum, uint8_t* temp);

#endif /* DHT11_H_ */