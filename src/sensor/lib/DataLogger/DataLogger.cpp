/*******************************************************************************
 DataLogger.cpp
    Implementation of the logger.
*******************************************************************************/

/**
 * Includes & Macros
 */
#include <Arduino.h>
#include "DataLogger.h"

/**
 * Data Structures
 */

/**
 * datalog_new - initializes
 */
DataLogger *
datalog_new()
{
    Serial.println("// TODO: datalog_new");
}

size_t
datalog_write(DataLogger *dl, void *data, size_t dataSize)
{
    Serial.println("// TODO: datalog_write");
}

void 
datalog_destroy(DataLogger *datalog)
{
    Serial.println("// TODO: datalog_destroy");
}

int 
datalog_test(DataLogger *datalog)
{
    Serial.println("// TODO: datalog_test");
}