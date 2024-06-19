/*
 * Std_Types.h
 *
 *  Created on: Feb 17, 2024
 *      Author: Ziad
 */

#ifndef  TYPE_STDS_H_
#define TYPE_STDS_H_

/* ========== INCLUDES ========== */
#include "../LIB/Bit_Math.h"
#include "../LIB/Includes.h"

/* ========== CPU_TUPES ========== */
#define CPU_8_BIT   8
#define CPU_16_BIT  16
#define CPU_32_BIT  32
#define CPU_64_BIT  64

#define CPU_type    CPU_8_BIT

/* ========== Condetions ==========*/
#if     (CPU_type == CPU_64_BIT)

typedef unsigned char       uint_8;
typedef unsigned short      uint_16;
typedef unsigned int        uint_32;
typedef unsigned long long  uint_64;
typedef signed long long    sint_64;
typedef signed int          sint_32;
typedef signed short        sint_16;
typedef signed char         sint_8;
typedef float               float_32;
typedef double              float_64;

#elif   (CPU_type == CPU_32_BIT)

typedef unsigned char       uint_8;
typedef unsigned short      uint_16;
typedef unsigned long       uint_32;
typedef unsigned long long  uint_64;
typedef signed long long    sint_64;
typedef signed long         sint_32;
typedef signed short        sint_16;
typedef signed char         sint_8;
typedef float               float_32;
typedef double              float_64;

#elif   (CPU_type == CPU_16_BIT)

typedef unsigned char       uint_8;
typedef unsigned short      uint_16;
typedef unsigned long       uint_32;
typedef unsigned long long  uint_64;
typedef signed long long    sint_64;
typedef signed long         sint_32;
typedef signed short        sint_16;
typedef signed char         sint_8;
typedef float               float_32;
typedef double              float_64;

#elif   (CPU_type == CPU_8_BIT)

typedef unsigned char       uint_8;
typedef unsigned short      uint_16;
typedef unsigned long       uint_32;
typedef signed long         sint_32;
typedef signed short        sint_16;
typedef signed char         sint_8;
typedef float               float_32;

#endif

/* ========== Std_Return ========== */
typedef	uint_8				Return_Value;

/* ========== Std_Status ========== */
#define On			1
#define Off			0

#define Std_Active	1
#define Std_Idel	0

#define Std_High	1
#define Std_Low		0

#define R_Ok		(Return_Value)1
#define R_Not_Ok	(Return_Value)0

#define Zero_INIT	(uint_8)0

#endif
