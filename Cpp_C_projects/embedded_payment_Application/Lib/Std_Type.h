/*
 * Std_Type.h
 *
 *  Created on: Apr 29, 2024
 *      Author: ziad
 */

#ifndef LIB_STD_TYPE_H_
#define LIB_STD_TYPE_H_


/* ========== CPU_TUPES ========== */
#define CPU_8_BIT   8
#define CPU_16_BIT  16
#define CPU_32_BIT  32
#define CPU_64_BIT  64

#define CPU_type    CPU_8_BIT

/* ========== Condetions ==========*/
#if     (CPU_type == CPU_64_BIT)

typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned long long  uint64_t;
typedef signed long long    sint64_t;
typedef signed int          sint32_t;
typedef signed short        sint16_t;
typedef signed char         sint8_t;
typedef float               float32_t;
typedef double              float64_t;

#elif   (CPU_type == CPU_32_BIT)

typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned long       uint32_t;
typedef unsigned long long  uint64_t;
typedef signed long long    sint64_t;
typedef signed long         sint32_t;
typedef signed short        sint16_t;
typedef signed char         sint8_t;
typedef float               float32_t;
typedef double              float64_t;

#elif   (CPU_type == CPU_16_BIT)

typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned long       uint32_t;
typedef unsigned long long  uint64_t;
typedef signed long long    sint64_t;
typedef signed long         sint32_t;
typedef signed short        sint16_t;
typedef signed char         sint8_t;
typedef float               float32_t;
typedef double              float64_t;

#elif   (CPU_type == CPU_8_BIT)

typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned long       uint32_t;
typedef signed long         sint32_t;
typedef signed short        sint16_t;
typedef signed char         sint8_t;
typedef float               float32_t;

#endif

/* ========== Std_Return ========== */
typedef	uint8_t				Std_Return;

/* ========== Std_Status ========== */
#define On		1
#define Off		0

#define Std_Active	1
#define Std_Idel	0

#define Std_High	1
#define Std_Low		0

#define R_Ok		(Std_Return)1
#define R_Not_Ok	(Std_Return)0

#define Zero_Init	0

#endif /* LIB_STD_TYPE_H_ */
