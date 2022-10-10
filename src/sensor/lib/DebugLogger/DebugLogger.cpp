/*******************************************************************************
 DebugLogger.cpp
    Implementation of the logger.
*******************************************************************************/

#include <Arduino.h>
#include "DebugLogger.h"

#define INFO_PREFIX            "INFO"
#define WARNING_PREFIX         "WARN"
#define ERROR_PREFIX           "ERROR"

// TODO: get current time somewhere

DebugLogger::DebugLogger(char *name) 
{
    strncpy(this -> name, name, MAX_MODULE_NAME_LEN);
    this -> name[MAX_MODULE_NAME_LEN] = '\0';
}

void
DebugLogger::info(char *msg) 
{
    print(INFO_PREFIX, msg);
}

void
DebugLogger::warning(char *msg) 
{
    print(WARNING_PREFIX, msg);
}

void
DebugLogger::error(char *msg) 
{
    print(ERROR_PREFIX, msg);
}

void 
DebugLogger::print(char *prefix, char *msg)
{
    char buffer[MAX_LINE_LEN];
    snprintf(buffer, MAX_LINE_LEN, "%s\t%s\t%s\n", prefix, this -> name, msg);
    Serial.print(buffer);
}