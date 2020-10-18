
#include "SYSTICK_interface.h"


void Systick_init(void)
{
    STK_CTRL=0;              //disabling systick to start configuring it
    STK_CTRL|=1<<2;          //making it use whole AHB clock

    STK_LOAD=0x00FFFFFF;     //intitalising the reload register with max value
    STK_VAL=0;               //clearing the current value register 
    STK_CTRL|=0x01;          //enabling the SYSTICK timer
}



void delay_one_ms(void)
{

STK_LOAD=72000-1;// assuming that the clock is 72mhz and this value will make the reload register overflows every 1 milli second
STK_VAL=0;   //restarting the counter

while ((STK_CTRL&(1<<16))==0);  //wait for the Flag to be set indicating that the counter register has returned back to 0 and restarted counting



}




void delay_ms(u32 n)
{
    while(n--)
    {
        delay_one_ms();
    }
}





