#ifndef SYS_INTERFACE_H
#define SYS_INTERFACE_H
#include "SYSTICK_private.h"

void Systick_init(void);  //function to init systick timer
void delay_one_ms(void);  //function to delay one millisecond using systick
void delay_ms(u32 n);       //function to delay n milliseconds using delay_one_ms() function


//
#endif
