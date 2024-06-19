/*
 * UART_Config.h
 *
 *  Created on: Jun 8, 2024
 *      Author: ziad
 */

#ifndef MCAL_UART_UART_CONFIG_H_
#define MCAL_UART_UART_CONFIG_H_

/*********** INCLUDES ***********/
#include "UART_Reg.h"

/*********** SYNCH MODE ***********/
#define ASYNCHRONOUS_MODE	0
#define SYNCHRONOUS_MODE	1

#define SYNCH_MODE	ASYNCHRONOUS_MODE

/*********** PARITY MODE ***********/
#define PARITY_DIS	0
#define PARITY_EVEN	1
#define PARITY_ODD	2

#define PARITY_MODE	PARITY_DIS

/*********** STOP NUMBER BITS ***********/
#define STOP_1_BIT	0
#define STOP_2_BIT	1

#define STOP_NUM_BITS STOP_1_BIT

/*********** DATA NUMBER SIZE ***********/
#define DATA_5_BITS	0
#define DATA_6_BITS	1
#define DATA_7_BITS	2
#define DATA_8_BITS	4
#define DATA_9_BITS	5

#define DATA_SIZE	DATA_8_BITS

/*********** POLARTY MODE ***********/
#define RISING_TxD	0
#define FALLING_TxD	1

/*********** SPEED MODE ***********/
#define SPEED_NORMAL	0
#define SPEED_DOUBLE	1

#define SPEED_MODE	SPEED_NORMAL

/*********** CPU FREQ ***********/
#define FREQ_1_MHZ	0
#define FREQ_2_MHZ  1
#define FREQ_4_MHZ  2
#define FREQ_8_MHZ	3
#define FREQ_16_MHZ	4
#define FREQ_20_MHZ	5

#define CPU_FREQ	FREQ_1_MHZ


/*********** BAUD RATE ***********/
#if ((CPU_FREQ == FREQ_1_MHZ) && (SPEED_MODE == SPEED_NORMAL))
typedef enum
{
	BAUD_2400  = 25,
	BAUD_4800  = 12,
	BAUD_9600  = 6,
	BAUD_14_4k = 3,
	BAUD_19_2k = 2,
	BAUD_28_8k = 1,
	BAUD_38_4k = 1,
	BAUD_57_6k = 0
}BAUD_RATE;
#elif ((CPU_FREQ == FREQ_1_MHZ) && (SPEED_MODE == SPEED_DOUBLE))
typedef enum
{
	BAUD_2400   = 51,
	BAUD_4800   = 25,
	BAUD_9600   = 12,
	BAUD_14_4k  = 8,
	BAUD_19_2k  = 6,
	BAUD_28_8k  = 3,
	BAUD_38_4k  = 2,
	BAUD_57_6k  = 1,
	BAUD_76_8k  = 0,
	BAUD_115_2k = 0
}BAUD_RATE;
#elif ((CPU_FREQ == FREQ_2_MHZ) && (SPEED_MODE == SPEED_NORMAL))
typedef enum
{
	BAUD_2400   = 51,
	BAUD_4800   = 25,
	BAUD_9600   = 12,
	BAUD_14_4k  = 8,
	BAUD_19_2k  = 6,
	BAUD_28_8k  = 3,
	BAUD_38_4k  = 2,
	BAUD_57_6k  = 1,
	BAUD_76_8k  = 1,
	BAUD_115_2k = 0
}BAUD_RATE;
#elif ((CPU_FREQ == FREQ_2_MHZ) && (SPEED_MODE == SPEED_DOUBLE))
typedef enum
{
	BAUD_2400   = 103,
	BAUD_4800   = 51,
	BAUD_9600   = 25,
	BAUD_14_4k  = 16,
	BAUD_19_2k  = 12,
	BAUD_28_8k  = 8,
	BAUD_38_4k  = 6,
	BAUD_57_6k  = 3,
	BAUD_76_8k  = 2,
	BAUD_115_2k = 1,
	BAUD_250k   = 0
}BAUD_RATE;
#elif ((CPU_FREQ == FREQ_4_MHZ) && (SPEED_MODE == SPEED_NORMAL))
typedef enum
{
	BAUD_2400   = 103,
	BAUD_4800   = 51,
	BAUD_9600   = 25,
	BAUD_14_4k  = 16,
	BAUD_19_2k  = 12,
	BAUD_28_8k  = 8,
	BAUD_38_4k  = 6,
	BAUD_57_6k  = 3,
	BAUD_76_8k  = 2,
	BAUD_115_2k = 1,
	BAUD_230_4k = 0,
	BAUD_250k   = 0
}BAUD_RATE;
#elif ((CPU_FREQ == FREQ_4_MHZ) && (SPEED_MODE == SPEED_DOUBLE))
typedef enum
{
	BAUD_2400   = 207,
	BAUD_4800   = 103,
	BAUD_9600   = 51,
	BAUD_14_4k  = 34,
	BAUD_19_2k  = 25,
	BAUD_28_8k  = 16,
	BAUD_38_4k  = 12,
	BAUD_57_6k  = 8,
	BAUD_76_8k  = 6,
	BAUD_115_2k = 3,
	BAUD_230_4k = 1,
	BAUD_250k   = 1,
	BAUD_0_5M   = 0
}BAUD_RATE;
#elif ((CPU_FREQ == FREQ_8_MHZ) && (SPEED_MODE == SPEED_NORMAL))
typedef enum
{
	BAUD_2400   = 207,
	BAUD_4800   = 103,
	BAUD_9600   = 51,
	BAUD_14_4k  = 34,
	BAUD_19_2k  = 25,
	BAUD_28_8k  = 16,
	BAUD_38_4k  = 12,
	BAUD_57_6k  = 8,
	BAUD_76_8k  = 6,
	BAUD_115_2k = 3,
	BAUD_230_4k = 1,
	BAUD_250k   = 1,
	BAUD_0_5M   = 0,
}BAUD_RATE;
#elif ((CPU_FREQ == FREQ_8_MHZ) && (SPEED_MODE == SPEED_DOUBLE))
typedef enum
{
	BAUD_2400   = 416,
	BAUD_4800   = 207,
	BAUD_9600   = 103,
	BAUD_14_4k  = 68,
	BAUD_19_2k  = 51,
	BAUD_28_8k  = 34,
	BAUD_38_4k  = 25,
	BAUD_57_6k  = 16,
	BAUD_76_8k  = 12,
	BAUD_115_2k = 8,
	BAUD_230_4k = 3,
	BAUD_250k   = 3,
	BAUD_0_5M   = 1,
	BAUD_1M     = 0
}BAUD_RATE;
#elif ((CPU_FREQ == FREQ_16_MHZ) && (SPEED_MODE == SPEED_NORMAL))
typedef enum
{
	BAUD_2400   = 416,
	BAUD_4800   = 207,
	BAUD_9600   = 103,
	BAUD_14_4k  = 68,
	BAUD_19_2k  = 51,
	BAUD_28_8k  = 34,
	BAUD_38_4k  = 25,
	BAUD_57_6k  = 16,
	BAUD_76_8k  = 12,
	BAUD_115_2k = 8,
	BAUD_230_4k = 3,
	BAUD_250k   = 3,
	BAUD_0_5M   = 1,
	BAUD_1M     = 0
}BAUD_RATE;
#elif ((CPU_FREQ == FREQ_16_MHZ) && (SPEED_MODE == SPEED_DOUBLE))
typedef enum
{
	BAUD_2400   = 832,
	BAUD_4800   = 416,
	BAUD_9600   = 207,
	BAUD_14_4k  = 138,
	BAUD_19_2k  = 103,
	BAUD_28_8k  = 68,
	BAUD_38_4k  = 51,
	BAUD_57_6k  = 34,
	BAUD_76_8k  = 25,
	BAUD_115_2k = 16,
	BAUD_230_4k = 8,
	BAUD_250k   = 7,
	BAUD_0_5M   = 3,
	BAUD_1M     = 1
}BAUD_RATE;
#elif ((CPU_FREQ == FREQ_20_MHZ) && (SPEED_MODE == SPEED_NORMAL))
typedef enum
{
	BAUD_2400   = 520,
	BAUD_4800   = 259,
	BAUD_9600   = 129,
	BAUD_14_4k  = 86,
	BAUD_19_2k  = 64,
	BAUD_28_8k  = 42,
	BAUD_38_4k  = 32,
	BAUD_57_6k  = 21,
	BAUD_76_8k  = 15,
	BAUD_115_2k = 10,
	BAUD_230_4k = 4,
	BAUD_250k   = 4
}BAUD_RATE;
#elif ((CPU_FREQ == FREQ_20_MHZ) && (SPEED_MODE == SPEED_DOUBLE))
typedef enum
{
	BAUD_2400   = 1041,
	BAUD_4800   = 520,
	BAUD_9600   = 259,
	BAUD_14_4k  = 173,
	BAUD_19_2k  = 129,
	BAUD_28_8k  = 86,
	BAUD_38_4k  = 64,
	BAUD_57_6k  = 42,
	BAUD_76_8k  = 32,
	BAUD_115_2k = 21,
	BAUD_230_4k = 10,
	BAUD_250k   = 9,
	BAUD_0_5M   = 4
}BAUD_RATE;
#endif

#endif /* MCAL_UART_UART_CONFIG_H_ */
