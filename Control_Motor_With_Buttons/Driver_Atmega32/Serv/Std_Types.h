/*
 * Std_Types.h
 *
 *  Created on: Feb 17, 2024
 *      Author: Ziad
 */

#ifndef  TYPE_STDS_H_
#define TYPE_STDS_H_

/* ======,==== Includes ========== */
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
/* ========== CPU_TUPES ========== */
#define CPU_8_BIT   8
#define CPU_16_BIT  16
#define CPU_32_BIT  32
#define CPU_64_BIT  64

#define CPU_type    CPU_8_BIT

/* ========== Condetions ==========*/
#if     (CPU_type == CPU_64_BIT)

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;
typedef signed long long    s64;
typedef signed int          s32;
typedef signed short        s16;
typedef signed char         s8;
typedef float               f32;
typedef double              f64;

#elif   (CPU_type == CPU_32_BIT)

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned long       u32;
typedef unsigned long long  u64;
typedef signed long long    s64;
typedef signed long         s32;
typedef signed short        s16;
typedef signed char         s8;
typedef float               f32;
typedef double              f64;

#elif   (CPU_type == CPU_16_BIT)

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned long       u32;
typedef unsigned long long  u64;
typedef signed long long    s64;
typedef signed long         s32;
typedef signed short        s16;
typedef signed char         s8;
typedef float               f32;
typedef double              f64;

#elif   (CPU_type == CPU_8_BIT)

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned long       u32;
typedef signed long         s32;
typedef signed short        s16;
typedef signed char         s8;
typedef float               f32;

#endif

/* ========== Std_Return ========== */
typedef	u8				Std_Return;

/* ========== Std_Status ========== */
#define On			1
#define Off			0

#define Std_Active	1
#define Std_Idel	0

#define Std_High	1
#define Std_Low		0

#define R_Ok		(Std_Return)1
#define R_Not_Ok	(Std_Return)0

#define Initial_Counter	(u8)0

#endif
