/*
 * kpd_prog.c
 *
 * Created: 12/5/2023 11:18:07 PM
 *  Author: EECE
 */ 
#include "kpd.h"
#include <util/delay.h>
u8 col,row,kpd_pres_key;
u8 KPD_GRID[4][4]={
	{7,8,9,'/'},
	{4,5,6,'*'},
	{1,2,3,'-'},
	{'C',0,'=','+'}
};
void kpd_initialization()
{
	DIO_voidSetPortDir(kpd_port, 0b00001111);//FIRST 4 ZERO OTHERS ONES 
	 DIO_voidSetPortVal(kpd_port, 0b1111111);//FIRST 4 ONES OTHRES DON'T MATTER FOR NOW
	
}

u8  kpd_get_pressed_key()
{ 
	kpd_pres_key=255;
	for(col=0;col<colums_no;col++)
	{
		DIO_voidSetPinVal(kpd_port, col, DIO_LOW);
		for(row=4;row<rows_no+colums_no;row++)
		{
			if( DIO_u8GetPinVal(kpd_port, row)==DIO_LOW)
			{
				kpd_pres_key=KPD_GRID[row-rows_no][col];
			}
			while(DIO_u8GetPinVal(kpd_port,row) ==DIO_LOW)
			_delay_ms(10);
			
		}
		DIO_voidSetPinVal(kpd_port, col, DIO_HIGH);
	}
	return kpd_pres_key;
}