/********************************/
/* Author	: Abdelrhman Samir	*/
/* Version	: 1					*/
/* Date		: 15 AUG 2020		*/
/********************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H



/* Clock Options:			RCC_HSE_CRYSTAL
							RCC_HSE_RC 
							RCC_HSI
							RCC_PLL				*/						
#define RCC_CLOCK_TYPE	RCC_HSE_CRYSTAL


/*PLL Input Options:		RCC_PLL_IN_HSI_DIV_BY_2
							RCC_PLL_IN_HSE_DIV_BY_2
							RCC_PLL_IN_HSE				*/				
/* Note: Select Value Only If You Have PLL Source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT	RCC_PLL_IN_HSI_DIV_BY_2
#endif

	
#endif 