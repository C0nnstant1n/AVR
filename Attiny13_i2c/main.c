#include "main.h"

uint8_t _hum, _temp;// ���������� ��� ��������� � �����������

	ISR(INT0_vect){
		//����� �� ���
	}

int main(void)
{
	//��������� ���������� ����������
	sei();
	
	//����������� LCD 1602
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
				
		//���� �� ���1 1, ���������� � ���
		if(PINB&(1<<SLEEP)){
			// ��������� ���, ������������� ���������� �� ������� ������
			MCUCR|=(0<<ISC01)|(0<<ISC00)|(1<<SE);
			
			//��������� ������� ����������
			GIMSK|=(1<<INT0);
			
			//��������� �����
			sendByte(8, 0);
			asm("sleep");
		}
		_delay_ms(2000);
	}
}

