/*
=============================================================================
=============================================================================
*       @   File_Name           :   SDB.c
*       @   Engineer_Name       :   Ziad_Mohammed_Fathi_Mohammed
*       @   Data                :   1/2/2023
*       @   Breif               :   Functions Defintion.
=============================================================================
=============================================================================

*/


/* ==================== Includes Section Start =================== */
#include "SDB.h"
#include <stdio.h>
/* ==================== Includes Section End  ==================== */



/* ==================== Macroes Section Start ==================== */
#define MAX_STUDENTS 10
/* ==================== Macroes Section End  ===================== */



/* ==================== static Section Start ==================== */
static student database[MAX_STUDENTS];
static uint8 usedSize = 0;
/* ==================== static Section End  ===================== */

/* ================ Functions Defintion Section Start ============= */
bool SDB_IsFull() {
    return (usedSize == MAX_STUDENTS);
}

uint8 SDB_GetUsedSize() {
    return usedSize;
}

bool SDB_AddEntry() {
    if (usedSize >= MAX_STUDENTS)
        return false;

    student newStudent;
    printf("Enter Student ID: ");
    scanf("%u", &newStudent.Student_ID);
    printf("Enter Student Year: ");
    scanf("%u", &newStudent.Student_year);
    printf("Enter Course 1 ID: ");
    scanf("%u", &newStudent.Course1_ID);
    printf("Enter Course 1 Grade: ");
    scanf("%u", &newStudent.Course1_grade);
    printf("Enter Course 2 ID: ");
    scanf("%u", &newStudent.Course2_ID);
    printf("Enter Course 2 Grade: ");
    scanf("%u", &newStudent.Course2_grade);
    printf("Enter Course 3 ID: ");
    scanf("%u", &newStudent.Course3_ID);
    printf("Enter Course 3 Grade: ");
    scanf("%u", &newStudent.Course3_grade);

    database[usedSize] = newStudent;
    usedSize++;
    return true;
}

void SDB_DeleteEntry(uint32 id) {
    for (uint8 i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id) {
            for (uint8 j = i; j < usedSize - 1; j++) {
                database[j] = database[j + 1];
            }
            usedSize--;
            break;
        }
    }
}

bool SDB_ReadEntry(uint32 id) {
    for (uint8 i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id) {
            printf("Student ID: %u\n", database[i].Student_ID);
            printf("Student Year: %u\n", database[i].Student_year);
            printf("Course 1 ID: %u\n", database[i].Course1_ID);
            printf("Course 1 Grade: %u\n", database[i].Course1_grade);
            printf("Course 2 ID: %u\n", database[i].Course2_ID);
            printf("Course 2 Grade: %u\n", database[i].Course2_grade);
            printf("Course 3 ID: %u\n", database[i].Course3_ID);
            printf("Course 3 Grade: %u\n", database[i].Course3_grade);
            return true;
        }
    }
    return false;
}

void SDB_GetList(uint8* count, uint32* list) {
    *count = usedSize;
    for (uint8 i = 0; i < usedSize; i++) {
        list[i] = database[i].Student_ID;
    }
}

bool SDB_IsIdExist(uint32 id) {
    for (uint8 i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id)
            return true;
    }
    return false;
}
/* ================ Functions Defintion Section End =============== */


/*
=====================================================================================
=====================================================================================
*   $   Revision   $

    Data                By                  Ticket No.
    --------------      --------------      --------------
    1Feb2024             Ziad_Mohammed       FirstProject_1
    --------------      --------------      --------------

=====================================================================================
=====================================================================================
*/
