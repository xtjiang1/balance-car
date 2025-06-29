/*
 * Data_to_Matlab.c
 *
 *  Created on: 2023年1月12日
 *      Author: jxt
 */


#include "main.h"
#include "usart.h"

int Dec_Data;
int i=1,j,Temp;
extern float Jy61_X_Angle;
uint32_t Out_Hex_Temp[99]={};

void Dec_To_Hex(float Input)
{
	Dec_Data=(int)Input;

	while(Dec_Data!=0)
	{
		Temp=Dec_Data%16;
		if(Temp<10)
			Temp=Temp+48;
		else
			Temp=Temp+55;
		Out_Hex_Temp[i++]=Temp;
		Dec_Data=Dec_Data/16;
	}
	i=0;
	//HAL_UART_Transmit_IT(&huart1, Out_Hex_Temp, sizeof(Out_Hex_Temp));
}
