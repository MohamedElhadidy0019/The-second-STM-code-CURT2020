/********************************/
/* Author	: Abdelrhman Samir	*/
/* Version	: 1					*/
/* Date		: 22 AUG 2020		*/
/********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"


void MGPIO_voidSetPinDirection(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Mode)
{
		switch(copy_u8PORT)
		{
			case GPIOA 	:
						if(copy_u8PIN <= 7)
						{
							GPIOA_CRL &= ~((0b1111)<<(copy_u8PIN * 4));
							GPIOA_CRL |= ((copy_u8Mode)<<(copy_u8PIN * 4));
						}
						else if(copy_u8PIN <= 15)
						{
							GPIOA_CRH &= ~((0b1111)<<(copy_u8PIN * 4));
							GPIOA_CRH |= ((copy_u8Mode)<<(copy_u8PIN * 4));
						}
						break;
			case GPIOB 	:
						if(copy_u8PIN <= 7)
						{
							GPIOB_CRL &= ~((0b1111)<<(copy_u8PIN * 4));
							GPIOB_CRL |= ((copy_u8Mode)<<(copy_u8PIN * 4));
						}
						else if(copy_u8PIN <= 15)
						{
							GPIOB_CRH &= ~((0b1111)<<(copy_u8PIN * 4));
							GPIOB_CRH |= ((copy_u8Mode)<<(copy_u8PIN * 4));
						}
						break;
			case GPIOC 	:
						if(copy_u8PIN <= 7)
						{
							GPIOC_CRL &= ~((0b1111)<<(copy_u8PIN * 4));
							GPIOC_CRL |= ((copy_u8Mode)<<(copy_u8PIN * 4));
						}
						else if(copy_u8PIN <= 15)
						{
							GPIOC_CRH &= ~((0b1111)<<(copy_u8PIN * 4));
							GPIOC_CRH |= ((copy_u8Mode)<<(copy_u8PIN * 4));
						}
						break;
			default		:	break;
		}
}

void MGPIO_voidSetPinValue(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Value)
{
	switch(copy_u8PORT)
		{
			case GPIOA 	:
						GPIOA_ODR &= ~((1)<<(copy_u8PIN));
						GPIOA_ODR |= ((copy_u8Value)<<(copy_u8PIN));
						break;
			case GPIOB 	:
						GPIOB_ODR &= ~((1)<<(copy_u8PIN));
						GPIOB_ODR |= ((copy_u8Value)<<(copy_u8PIN));
						break;;
			case GPIOC 	:
						GPIOC_ODR &= ~((1)<<(copy_u8PIN));
						GPIOC_ODR |= ((copy_u8Value)<<(copy_u8PIN));
						break;
			default		:	break;
		}
}

u8 	 MGPIO_voidGetPinValue(u8 copy_u8PORT , u8 copy_u8PIN)
{

	u8 LOC_u8Result = 0 ;

	switch(copy_u8PORT)
	{
			case GPIOA:
						LOC_u8Result = GET_BIT( GPIOA_IDR , copy_u8PIN );
						break;
		
			case GPIOB:
		
						LOC_u8Result = GET_BIT( GPIOB_IDR , copy_u8PIN );
						break;
				
			case GPIOC:
		
						LOC_u8Result = GET_BIT( GPIOC_IDR , copy_u8PIN );
						break;
					
			default:
						break;
			}
		return LOC_u8Result;	
}
