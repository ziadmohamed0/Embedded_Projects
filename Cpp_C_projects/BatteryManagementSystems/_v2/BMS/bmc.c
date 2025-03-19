/**
 * @file bmc.c
 * @author Ziad Mohammed Fathy
 * @brief 
 * @version 0.2
 * @date 2025-03-19
 */

#include "bmc.h"

static const char *status_return(int copyStatus);

/**
 * @brief initialize the battery cells with user input. 
 * 
 * @param copyCell -> Array of Cell structures and the number of cells.
 */
void initCells(Cell *copyCell) {
    for(int count = 0; count < NUM_CELLS; count++) {
        printf("Enter Data for Cell %d\nVoltage (v) : ", (count+1));
        scanf("%f", &copyCell[count].voltage);
        printf("Temprature (°C) : ");
        scanf("%f", &copyCell[count].temperature);
        printf("Status of charge (%%) : ");
        scanf("%f", &copyCell[count].StatusOfCharge);
        printf("\n\n");
        copyCell[count].status = OK;
    }
    printf("\n\n---------- initialize Cells ----------\n");
    displayCellStatus(copyCell);
}

/**
 * @brief Monitor and update the status of each cell.
 * 
 * @param copyCell -> Array of Cell structures and the number of cells.
 */
void monitorCells(Cell *copyCell) {
    printf("\n\n---------- Monitorings Cells ----------\n");
    for(int count = 0; count < NUM_CELLS; count++) {
        if(copyCell[count].voltage > MAX_VOLTAGE)
            copyCell[count].status = OVER_VOLTAGE;

        else if(copyCell[count].voltage < MIN_VOLTAGE)
            copyCell[count].status = UNDER_VOLTAGE;

        else if(copyCell[count].temperature > MAX_TEMPRATURE)
            copyCell[count].status = OVER_TEMPERATURE;

        else if (copyCell[count].temperature < MIN_TEMPRATURE)
            copyCell[count].status = UNDER_TEMPERATURE;
        
        else 
            copyCell[count].status = OK;
    }
    displayCellStatus(copyCell);
}

/**
 * @brief Balance the cell voltages to ensure uniformity.
 * 
 * @param copyCell -> Array of Cell structures and the number of cells.
 */
void balanceCells(Cell *copyCell) {
    float totalVoltage, avgVoltage;
    int balanced = 0;

    printf("\n\n---------- Balancing Cells ----------\n");

    while (!balanced) {
        totalVoltage = 0.0;

        for (int i = 0; i < NUM_CELLS; i++) {
            totalVoltage += copyCell[i].voltage;
        }
        avgVoltage = totalVoltage / NUM_CELLS;

        balanced = 1;  

        for (int i = 0; i < NUM_CELLS; i++) {
            float diff = copyCell[i].voltage - avgVoltage;

            if (fabs(diff) > BALANCE_THRESHHOLD) {
                balanced = 0; 

                if (diff > 0) {
                    copyCell[i].voltage -= STEP_SIZE;  
                } else {
                    copyCell[i].voltage += STEP_SIZE;  
                }

                if (copyCell[i].voltage > MAX_VOLTAGE) {
                    copyCell[i].voltage = MAX_VOLTAGE;
                } else if (copyCell[i].voltage < MIN_VOLTAGE) {
                    copyCell[i].voltage = MIN_VOLTAGE;
                }
            }
        }
        printf("\n");
        displayCellStatus(copyCell);
    }

    printf("\nCells are balanced and within safe limits\n");
}

/**
 * @brief Check if the cells are balanced within a threshold.
 * 
 * @param copyCell -> Array of Cell structures and the number of cells.
 * @return int 
 */
int isBalanced(Cell *copyCell) {
    float totalVoltage = 0.0, avgVoltage;

    for (int i = 0; i < NUM_CELLS; i++) {
        totalVoltage += copyCell[i].voltage;
    }
    avgVoltage = totalVoltage / NUM_CELLS;

    for (int i = 0; i < NUM_CELLS; i++) {
        if (fabs(copyCell[i].voltage - avgVoltage) > BALANCE_THRESHHOLD) {
            return NOT_BALANCE;
        }
    }
    return BALANCE;
}

/**
 * @brief Display the status of each cell.
 * 
 * @param copyCell_index -> Pointer to a Cell structure and the cell index.
 */
void displayCellStatus(Cell *copyCell_index) {
    for(int count = 0; count < NUM_CELLS; count++) {
        printf("Cell %d - Voltage: %.2fv, Temperature: %.2f°C, SoC: %.2f%%, Status: %s\n",
            (count+1), copyCell_index[count].voltage, copyCell_index[count].temperature, 
            copyCell_index[count].StatusOfCharge, status_return(copyCell_index[count].status));
    }
}


static const char *status_return(int copyStatus) {
    static const char *status_strings[] = {
        "OK",
        "OVER VOLTAGE",
        "UNDER VOLTAGE",
        "OVER TEMPERATURE",
        "UNDER TEMPERATURE"
    };

    if (copyStatus >= 0 && copyStatus <= 4) {
        return status_strings[copyStatus];
    }
    return "INVALID STATUS";
}