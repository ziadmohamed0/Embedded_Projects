/**
 * @file main.c
 * @author Ziad Mohammed Fathy
 * @brief 
 * @version 0.2
 * @date 2025-03-19
 */

#include "bmc.h"

int main (void) {
    Cell cells[NUM_CELLS];

    initCells(cells);

    monitorCells(cells);

    balanceCells(cells);

    isBalanced(cells);

    return 0;
}