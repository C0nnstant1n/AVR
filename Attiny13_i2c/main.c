#include "main.h"

uint8_t _hum, _temp;// переменные для влажности и температуры

	ISR(INT0_vect){
		//выход из сна
	}

int main(void)
{
	//Разрешаем глобальные прерывания
	sei();
	
	//Настраиваем LCD 1602
	lcd_init();	
	sendByte('T', 1);
	sendByte('e', 1);
	sendByte('m', 1);
	sendByte('p', 1);
	while (1)
	{
		sendByte(12, 0);
		dhtRead(&_hum, &_temp);
		setCursor(0, 12);
		numToStr(_temp);
		sendByte('C', 1);
		sendByte(0xdf, 1);
		setCursor(1, 7);
		numToStr(CLKPR);	
		sendByte('%', 1);
				
		//Если на пин1 1, отправляем в сон
		if(PINB&(1<<SLEEP)){
			// Разрешаем сон, конфигурируем прерывания по низкому уровню
			MCUCR|=(0<<ISC01)|(0<<ISC00)|(1<<SE);
			
			//Разрешаем внешние прерывания
			GIMSK|=(1<<INT0);
			
			//Выключаем экран
			sendByte(8, 0);
			asm("sleep");
		}
		_delay_ms(2000);
	}
}

