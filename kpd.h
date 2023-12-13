/*
 * kpd.h
 *
 * Created: 12/5/2023 11:17:40 PM
 *  Author: EECE
 */ 


#ifndef KPD_H_
#define KPD_H_
#include "../../Library/BIT_MATH.h"
#include "../../Library/TYPES.h"
#include "../../MCAL/DIO_int.h"

#define rows_no 4
#define colums_no 4
#define  kpd_port DIO_PORTA
void kpd_initialization();
u8  kpd_get_pressed_key();




#endif /* KPD_H_ */