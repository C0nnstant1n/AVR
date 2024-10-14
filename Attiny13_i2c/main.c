#include "main.h"


uint8_t _hum, _temp;// переменные для влажности и температуры

	/*ISR(INT0_vect){
		//выход из сна
		PORTB|=(1<<P_LED);
		sendByte(12, 0);
	}*/

int main(void)
{
	// Разрешаем сон, конфигурируем прерывания по низкому уровню
	MCUCR|=(0<<ISC01)|(0<<ISC00)|(1<<SE)|(1<<SM1);
	
	/*//Разрешаем внешние прерывания
	GIMSK|=(1<<INT0);
	//Разрешаем глобальные прерывания
	sei();*/
	
	//Настраиваем LCD 1602
	lcd_init();	
	lcdString("Temp");
	while (1)
	{
		dhtRead(&_hum, &_temp);
		setCursor(0, 12);
		numToStr(_temp);
		sendByte('C', 1);
		sendByte(0xdf, 1);
		setCursor(1, 7);
		numToStr(_hum);	
		sendByte('%', 1);
		_delay_ms(2000);
		
		
		/*//Если на пин1 1, отправляем в сон
		if(PINB&(1<<SLEEP)){
			sendByte(8, 0);
			PORTB&=~(1<<P_LED);
			asm("sleep");
		}*/
	}
}

