/**
 * @file BMS.h
 * @author Ziad mohammed fathy
 * @brief Battery Management System (BMS) header file
 * @version 0.1
 * @date 2025-03-14
 */

 #ifndef BMS_H
 #define BMS_H
 
 /* ----- includes sections ----- */
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 
 /* ----- macros sections ----- */
 #define MIN_VOLTAGE 3.0 /**< Minimum allowable voltage */
 #define MAX_VOLTAGE 4.2 /**< Maximum allowable voltage */
 #define MIN_TEMPERATURE 0.0 /**< Minimum allowable temperature */
 #define MAX_TEMPERATURE 45.0 /**< Maximum allowable temperature */
 #define BALANCE_THRESHOLD 0.05 /**< Voltage threshold for balancing */
 
 /* ----- standard types sections ----- */
 /**
  * @brief Enumeration for cell status
  */
 typedef enum { 
     OK, /**< Cell is operating normally */
     OVERVOLTAGE, /**< Cell voltage exceeds maximum limit */
     UNDERVOLTAGE, /**< Cell voltage falls below minimum limit */
     OVERTEMPERATURE /**< Cell temperature exceeds maximum limit */
 } Status;
 
 /**
  * @brief Structure to represent a battery cell
  */
 typedef struct {
     float voltage; /**< Cell voltage in volts */
     float temperature; /**< Cell temperature in degrees Celsius */
     float soc; /**< State of charge (percentage) */
     Status status; /**< Current status of the cell */
 } Cell;
 
 /* ----- API sections ----- */
 /**
  * @brief Initializes battery cells with user input
  * 
  * @param cells Pointer to array of cells
  * @param numCells Number of cells
  */
 void initCells(Cell *cells, int numCells);
 
 /**
  * @brief Monitors cell parameters and updates status
  * 
  * @param cells Pointer to array of cells
  * @param numCells Number of cells
  */
 void monitorCells(Cell *cells, int numCells);
 
 /**
  * @brief Balances cell voltages to maintain uniformity
  * 
  * @param cells Pointer to array of cells
  * @param numCells Number of cells
  */
 void balanceCells(Cell *cells, int numCells);
 
 /**
  * @brief Checks if all cells are balanced within threshold
  * 
  * @param cells Pointer to array of cells
  * @param numCells Number of cells
  * @return int Returns 1 if balanced, 0 otherwise
  */
 int isBalanced(Cell *cells, int numCells);
 
 /**
  * @brief Displays the status of a specific cell
  * 
  * @param cell Pointer to the cell structure
  * @param index Index of the cell in the array
  */
 void displayCellStatus(Cell *cell, int index);
 
 #endif /* BMS_H */