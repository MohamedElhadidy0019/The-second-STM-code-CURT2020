

#include "STD_TYPES.H"
#include "BIT_MATH.H"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "RCC_private.h"
#include "DEFINES.h"



void setup(void);
void loop(void);
u8 bspd_read,bspd_relay_read,imd_read,imd_relay_read,bms_read;
int main(void)
{
    setup();
    while(1)
    {
        loop();
    }
    return 0;
}

void setup(void)
{
    //*Clock Enables*//
    RCC_voidInitSysClock();
    RCC_voidEnableClock(RCC_APB2,2);
    RCC_voidEnableClock(RCC_APB2,3);
    RCC_voidEnableClock(RCC_APB2,4);
    ///////////////////////////////****GPIO Enables****//////////////////////

    //*ANALOG INPUTS*//
    MGPIO_voidSetPinDirection(GPIOA,BRAKES_ANGLE,INPUT_ANALOG);
    MGPIO_voidSetPinDirection(GPIOA,BRAKES_PRESSURE,INPUT_ANALOG);

    //*DIGITAL INPUTS*//
    MGPIO_voidSetPinDirection(GPIOB,BSPD_FB,INPUT);
    MGPIO_voidSetPinDirection(GPIOB,BSPD_RELAY_FB,INPUT);
    MGPIO_voidSetPinDirection(GPIOB,IMD_FB,INPUT);
    MGPIO_voidSetPinDirection(GPIOB,IMD_RELAY_FB,INPUT);
    MGPIO_voidSetPinDirection(GPIOA,BMS_FB,INPUT); //should be interrupt

    //*DIGITAL OUTPUTS*//
    MGPIO_voidSetPinDirection(GPIOA,BRAKE_LIGHT_RELAY,OUTPUT);
    MGPIO_voidSetPinDirection(GPIOA,FAN_RELAY,OUTPUT);
    MGPIO_voidSetPinDirection(GPIOA,PUMP_RELAY,OUTPUT);
    MGPIO_voidSetPinDirection(GPIOA,EVMS_RELAY,OUTPUT);

}



void loop(void)
{

    MGPIO_voidSetPinValue(GPIOA,FAN_RELAY,HIGH);    //enables the accumulator fan
    MGPIO_voidSetPinValue(GPIOA,PUMP_RELAY,HIGH);    //enables the water pump

    bspd_read=MGPIO_u8GetPinValue(GPIOB,BSPD_FB);
    //delay(1);
    bspd_relay_read=MGPIO_u8GetPinValue(GPIOB,BSPD_RELAY_FB);
    if(bspd_relay_read!=bspd_read)     //if the bspd relay didnt open on bspd error
    {
        MGPIO_voidSetPinValue(GPIOA,EVMS_RELAY,0); //open shutdown circuit
    }

    imd_read=MGPIO_u8GetPinValue(GPIOB,IMD_FB);
    //delay(1);
    imd_relay_read=MGPIO_u8GetPinValue(GPIOB,IMD_RELAY_FB);
    if(imd_read!=imd_relay_read)   //if imd detects an error and its realy doesnt open
    {
        MGPIO_voidSetPinValue(GPIOA,EVMS_RELAY,LOW); //open shutdown circuit
    }

    bms_read=MGPIO_u8GetPinValue(GPIOA,BMS_FB);
    if(bms_read)  //bms detects an error
    {
         MGPIO_voidSetPinValue(GPIOA,EVMS_RELAY,0); //open shutdown circuit
    }

    

}







