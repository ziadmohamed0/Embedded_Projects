/**
 * @file bmc.h
 * @author Ziad Mohammed Fathy
 * @brief 
 * @version 0.2
 * @date 2025-03-19
 */

#ifndef _BMC_H_
#define _BMC_H_

/* ------------ includes section ------------ */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ------------ macros section ------------ */
#define NUM_CELLS               2
#define MAX_VOLTAGE             4.2
#define MIN_VOLTAGE             3.0
#define MAX_TEMPRATURE          60.0
#define MIN_TEMPRATURE          0.0
#define BALANCE_THRESHHOLD      0.05
#define NOT_BALANCE             0 
#define BALANCE                 1 
#define STEP_SIZE 0.01

/* ------------ standard types section ------------ */
typedef enum {
    OK,
    OVER_VOLTAGE,
    UNDER_VOLTAGE,
    OVER_TEMPERATURE,
    UNDER_TEMPERATURE,
}CellStatus;

typedef struct {
    float voltage;
    float temperature;
    float StatusOfCharge;
    CellStatus status;
}Cell;

/* ------------ APIs section ------------ */
/**
 * @brief initialize the battery cells with user input. 
 * 
 * @param copyCell -> Array of Cell structures and the number of cells.
 */
void initCells(Cell *copyCell);

/**
 * @brief Monitor and update the status of each cell.
 * 
 * @param copyCell -> Array of Cell structures and the number of cells.
 */
void monitorCells(Cell *copyCell);

/**
 * @brief Balance the cell voltages to ensure uniformity.
 * 
 * @param copyCell -> Array of Cell structures and the number of cells.
 */
void balanceCells(Cell *copyCell);

/**
 * @brief Check if the cells are balanced within a threshold.
 * 
 * @param copyCell -> Array of Cell structures and the number of cells.
 * @return int 
 */
int isBalanced(Cell *copyCell);

/**
 * @brief Display the status of each cell.
 * 
 * @param copyCell_index -> Pointer to a Cell structure and the cell index.
 */
void displayCellStatus(Cell *copyCell_index);

#endif