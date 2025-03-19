/**
 * @file main.c
 * @author Ziad mohammed fathy
 * @brief 
 * @version 0.1
 * @date 2025-03-14
 */

#include "BMS.h"

#define NUM_CELLS 4

int main(void) {
    Cell cells[NUM_CELLS];
    
    initCells(cells, NUM_CELLS);
    monitorCells(cells, NUM_CELLS);
    balanceCells(cells, NUM_CELLS);
    
    for (int i = 0; i < NUM_CELLS; i++) {
        displayCellStatus(&cells[i], i);
    }
    
    if (isBalanced(cells, NUM_CELLS)) {
        printf("All cells are balanced.\n");
    } else {
        printf("Cells are not balanced.\n");
    }
    
    return 0;
}
 