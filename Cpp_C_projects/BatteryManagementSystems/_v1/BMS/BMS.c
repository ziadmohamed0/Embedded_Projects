/**
 * @file BMS.c
 * @author Ziad mohammed fathy
 * @brief 
 * @version 0.1
 * @date 2025-03-14
 */

#include "BMS.h"

void initCells(Cell *cells, int numCells) {
    for (int i = 0; i < numCells; i++) {
        printf("Enter voltage, temperature, and SoC for cell %d: ", i + 1);
        scanf("%f %f %f", &cells[i].voltage, &cells[i].temperature, &cells[i].soc);
        cells[i].status = OK;
    }
}

void monitorCells(Cell *cells, int numCells) {
    for (int i = 0; i < numCells; i++) {
        if (cells[i].voltage > MAX_VOLTAGE) cells[i].status = OVERVOLTAGE;
        else if (cells[i].voltage < MIN_VOLTAGE) cells[i].status = UNDERVOLTAGE;
        else if (cells[i].temperature > MAX_TEMPERATURE) cells[i].status = OVERTEMPERATURE;
        else cells[i].status = OK;
    }
}

void balanceCells(Cell *cells, int numCells) {
    float avgVoltage = 0;
    for (int i = 0; i < numCells; i++) {
        avgVoltage += cells[i].voltage;
    }
    avgVoltage /= numCells;
    
    for (int i = 0; i < numCells; i++) {
        if (cells[i].voltage > avgVoltage) cells[i].voltage -= BALANCE_THRESHOLD;
        else if (cells[i].voltage < avgVoltage) cells[i].voltage += BALANCE_THRESHOLD;
    }
}

int isBalanced(Cell *cells, int numCells) {
    float avgVoltage = 0;
    for (int i = 0; i < numCells; i++) {
        avgVoltage += cells[i].voltage;
    }
    avgVoltage /= numCells;
    
    for (int i = 0; i < numCells; i++) {
        if (fabs(cells[i].voltage - avgVoltage) > BALANCE_THRESHOLD) return 0;
    }
    return 1;
}

void displayCellStatus(Cell *cell, int index) {
    printf("Cell %d -> Voltage: %.2fV, Temperature: %.2fC, SoC: %.2f%%, Status: %d\n",
           index + 1, cell->voltage, cell->temperature, cell->soc, cell->status);
}