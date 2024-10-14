/*
 * lcd.c
 *
 * Created: 03.10.2024 18:45:40
 *  Author: Konstantin
 */ 
#include "lcd.h"


//����������� LCD 1602 �� ������ � 4�� ������
void lcd_init(){
	_delay_ms(100); // ���� 40 �� ������������ �������
	//init1
		sendToInterface(3<<4);
	_delay_ms(5);
	//init2
		sendToInterface(3<<4);
	_delay_us(150);
	//init3
		sendToInterface(3<<4);
	min_time_command; // ����������� ����� ���������� �������
	//command
		sendToInterface(2<<4);
	min_time_command;
	// ������� Function Set 001_DL_N_F_X_X
		sendByte(40, 0);
	min_time_command;
	// ������� DISPLAY SWITCH 00001_D_C_B
		sendByte(12, 0);
	min_time_command;
	//Clear Display
		sendByte(1, 0);
	min_time_command;
	// ������� INPUT SET 000001_ID_S
		sendByte(6, 0);
	min_time_command;
	
}

//���������� ���� � I2C
void sendToInterface(uint8_t d){
		i2c_start();
		i2c_send(LCD_ADR);
		i2c_send(d|=(1<<2));
		i2c_stop();
		i2c_start();
		i2c_send(LCD_ADR);
		i2c_send(d&=~(1<<2));
		i2c_stop();
}

//��������� ������� ��������
void sendHiHalfByte(uint8_t d){
	d<<=4;
	sendToInterface(d);
}

//��������� ������� ��������
void sendLowHalfByte(uint8_t d){
	sendToInterface(d);
}

//�������� ����� �� �����
void sendByte(uint8_t data, uint8_t type){
	
	if (type){
		//���������� ������
		sendToInterface((data&0xf4)|1<<RS|1<<BACK_LIGHT);
		sendLowHalfByte(data<<4|1<<RS|1<<BACK_LIGHT);		
	}
	else{
		//���������� �������
		sendHiHalfByte(data>>4);
		sendLowHalfByte(data<<4);
		 }
}

//����� ������ �� ��������
void lcdString(char* str){
	uint8_t n=0;
	while(str[n]){
		sendByte(str[n], 1);
		n++;
	}
}
//������������� ������ � ������ �������
void setCursor(uint8_t line, uint8_t pos){
	uint8_t adress = (line *0x40 + pos)|0x80;
	sendByte(adress, 0);
	min_time_command;
}

//������� ������
void cls(){
	sendByte(1, 0);
	min_time_command;
}

//����� ���� �� �����(�������������� int � char)
void n_to_str(uint8_t num){
	char buf[4];
	utoa(num, buf, 10);
	lcdString(buf);
}
