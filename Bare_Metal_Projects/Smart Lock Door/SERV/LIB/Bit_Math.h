/*
 * Bit_Math.h
 *
 *  Created on: Feb 17, 2024
 *      Author: Ziad
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

/* ========== Bit Math Macros ========== */
#define CLR_BIT(reg,bit)      reg &= ~ (1 << bit)	//	Clear Bit In Any Register
#define SET_BIT(reg,bit)      reg |=   (1 << bit)	//	Set Bit In Any Register
#define TOGGLE_BIT(reg,bit)   reg ^=   (1 << bit)	//	Toggle Bit In Any Register
#define GET_BIT(reg,bit)      ((reg >> bit) & 1 )	//	Get Bit In Any Register

#endif /* LIB_BIT_MATH_H_ */
