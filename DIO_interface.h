/********************************/
/* Author	: Abdelrhman Samir	*/
/* Version	: 1					*/
/* Date		: 22 AUG 2020		*/
/********************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


/* Port Defines */
#define GPIOA    0
#define GPIOB    1
#define GPIOC    2


/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7
#define PIN8   8
#define PIN9   9
#define PIN10  10
#define PIN11  11
#define PIN12  12
#define PIN13  13
#define PIN14  14
#define PIN15  15


//For Inputs
#define INPUT_ANALOG               0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000

//For Output Speed 10
#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101

//For Output Speed 2
#define OUTPUT_SPEED_2MHZ_PP      0b0010
#define OUTPUT_SPEED_2MHZ_OD      0b0110
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110

//For Output Speed 50
#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111


/* Value Defines */
#define LOW 	0
#define HIGH 	1


/* Mode Defines */
#define INPUT 	0
#define OUTPUT	1


/* Functions Prototypes */
void MGPIO_voidSetPinValue(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Vlaue);

void MGPIO_voidSetPinDirection(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Mode);

u8 	 MGPIO_u8GetPinValue(u8 copy_u8PORT , u8 copy_u8PIN);

#endif
