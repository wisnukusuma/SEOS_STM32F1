/*
 * task.c
 *
 *  Created on: Apr 10, 2016
 *      Author: hendri
 */
#include "counter.h"
#include "task.h"
#include "stm32f4xx.h"
#include "device.h"
unsigned char bouncing=0xFF;
void Task_Init(void){

}
void Task_Run(void){
	if(HAL_GPIO_ReadPin(pbOk_GPIO_Port,pbOk_Pin)== GPIO_PIN_RESET){
		bouncing=(bouncing<<1);
	} else {
		bouncing= (bouncing<<1)|1;
	}
	if (bouncing==0x03)
		CounterUpdate();
	counterShow();
}

