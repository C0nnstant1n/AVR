#include "sleep.h"
void sleep(void){
	sendByte(8, 0);
	asm("sleep");
}

 