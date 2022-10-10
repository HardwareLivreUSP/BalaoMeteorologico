/*******************************************************************************
 DataLogger.cpp
    Implementation of the logger.
*******************************************************************************/

#include <Arduino.h>
#include "DataLogger.h"

DataLogger::DataLogger(char *name) 
{
    strncpy(this -> name, name, MAX_MODULE_NAME_LEN);
    this -> name[MAX_MODULE_NAME_LEN] = '\0';
}

size_t
DataLogger::write(void *data, size_t dataSize)
{
    Serial.println("// TODO: DataLogger::write");
}