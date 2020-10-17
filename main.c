

#include "STD_TYPES.H"
#include "BIT_MATH.H"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "RCC_private.h"
#include "DEFINES.h"

u8 bspd_read,bspd_relay_read,imd_read,imd_relay_read,bms_read;

void setup(void);
void loop(void);
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
    MGPIO_voidSetPinDirection(GPIOA,EVMS_RELAY,OUTPUT);

}

void loop(void)
{

    

}







