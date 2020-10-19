#include "STD_TYPES.h"

#ifndef SYS_PRIV_H
#define SYS_PRIV_H

#define SYSTICK_BASE_ADDRESS         0xE000E010


#define   STK_CTRL                   *((u32*)(SYSTICK_BASE_ADDRESS + 0x00))
#define   STK_LOAD                   *((u32*)(SYSTICK_BASE_ADDRESS + 0x04))
#define   STK_VAL                    *((u32*)(SYSTICK_BASE_ADDRESS + 0x08))



#endif

