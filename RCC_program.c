/********************************/
/* Author	: Abdelrhman Samir	*/
/* Version	: 1					*/
/* Date		: 15 AUG 2020		*/
/********************************/
#include "STD_TYPES.h" 
#include "BIT_MATH.h"

#include "RCC_private.h"
#include "RCC_config.h"


#define	RCC_AHB			0
#define	RCC_APB1		1
#define	RCC_APB2		2


void RCC_voidInitSysClock(void)
{
	#if 	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR = 0X00010000;	/* Enable HSE With no Bypass*/
		
	#elif 	RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR = 0X00050000;	/*Enable HSE With Bypass*/
		
	#elif 	RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR = 0X00000081;	/*Enable HSI + Triming= 0 */
		
	#elif 	RCC_CLOCK_TYPE == RCC_PLL
		
	#else
		#error("YOU CHOSED WRONG CLOCK TYPE ")
	#endif
}


void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	/* Argument Validation*/
	
	if(Copy_u8PerId<=31)
	{
		switch(Copy_u8BusId)
		{
			case  RCC_AHB  : SET_BIT(RCC_AHBENR	,Copy_u8PerId);	break;
			case  RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PerId);	break;
			case  RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PerId);	break;
			//default		   : 	/*reurn error*/				break;
		}
	}
	else
	{
		/* Return Error */
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	/* Argument Validation*/
	
	if(Copy_u8PerId<=31)
	{
		switch(Copy_u8BusId)
		{
			case  RCC_AHB  : CLR_BIT(RCC_AHBENR	,Copy_u8PerId);	break;
			case  RCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PerId);	break;
			case  RCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PerId);	break;
			//default		   : 	/*reurn error*/				break;
		}
	}
	else
	{
		/* Return Error */
	}
}
