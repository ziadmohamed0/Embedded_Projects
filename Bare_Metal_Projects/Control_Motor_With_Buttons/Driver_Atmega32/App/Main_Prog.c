/*
 * Main.c
 *
 *  Created on: Mar 16, 2024
 *      Author: ziad
 */
/********** SECTION : Includes **********/
#include "Main_Init.h"
/********** SECTION : Main Function **********/
int main (void)
{
	App_Init();
	while(1)
	{
		App_Loop();
	}
}
