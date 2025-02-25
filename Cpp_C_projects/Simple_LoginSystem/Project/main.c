/*
===============================================================================================================================
===============================================================================================================================
*       @   File_Name           :   Main.c
*       @   Engineer_Name       :   Ziad_Mohammed_Fathi_Mohammed.
*       @   Date                :   14/1/2024.
*       @   Breif               :	Login system Enter the pass Number by Number Or letter By Letter if The pass is Correct 
									open And print welcome.
									else loop this process Until the password is written correctly.
									He has three times, and if he counts them, he will be removed from the program
===============================================================================================================================
===============================================================================================================================
*/

/* ==================== Includes Section Start =================== */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/* ==================== Includes Section End  ==================== */

/* ============== G-Variable Declaration Section Start =========== */
unsigned char CurrentPass[6]={'z','i','a','d','1','2'};
unsigned char Pass[6];
/* ============== G-Variable Declaration Section End ============= */

/* ================== Main Funcion Section Start ================= */
int main()
{

	unsigned int EnteredPass = 0;
	unsigned int Dot = 0;
	unsigned int Check = 0;
	unsigned int PassFlag = 0;
	unsigned int Flag = 0;


	printf("\t===============Login System Programe ===============\n\n");
	while(Flag<=3)
	{
		printf("# Enter The Password : \n");

		for(EnteredPass = 0 ; EnteredPass < 6 ; EnteredPass++)
		{
			scanf(" %c", &Pass[EnteredPass]);
			fflush(stdin);
		}
		printf("\n");
		printf("Please Wait");


		for(Dot = 0 ; Dot < 6 ; Dot++ )
		{
			printf("..");
			Sleep(200);
		}
		printf("\n");


		for(Check = 0 ; Check < 6 ; Check++)
		{
			if(Pass[Check] != CurrentPass[Check])
			{
				PassFlag = 1;
				break;
			}
		}


		if(PassFlag == 1)
		{
			printf("# Invaled Password!!!!");
			printf("\n# Enter Password Again !!");
			PassFlag = 0;
			Flag++;
		}
		else
		{
			printf("# Welcome..\n\n");
			break;
		}
		printf("\n\n");
    }

	return 0;
}
/* ================== Main Funcion Section End =================== */

/*
=====================================================================================
=====================================================================================
*   $   Revision   $

    Data                By                  Ticket No.          Description
    --------------      --------------      --------------      --------------
    14January2024        ZiadMohammed       First_1
    --------------      --------------      --------------      --------------

=====================================================================================
=====================================================================================
*/
