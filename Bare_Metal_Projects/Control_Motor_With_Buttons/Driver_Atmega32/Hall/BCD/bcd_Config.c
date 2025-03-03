/*
 * bcd_Config.c
 *
 *  Created on: Mar 23, 2024
 *      Author: ziad
 */
/********** SECTION : Includes **********/
#include "bcd_Config.h"

/********** SECTION : Variable_Definations **********/
BCD Seg_1 = {
	.Pin_1 = PortA_p0,
	.Pin_2 = PortA_p1,
	.Pin_3 = PortA_p2,
	.Pin_4 = PortA_p3
};

MPX_4_Enables MX_1 = {
	.EN_1 = PortA_p4,
	.EN_2 = PortA_p5,
	.EN_3 = PortA_p6,
	.EN_4 = PortA_p7,
};

