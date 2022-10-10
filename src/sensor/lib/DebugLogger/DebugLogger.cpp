/*******************************************************************************
 DebugLogger.cpp
    Implementation of the logger.
*******************************************************************************/

#include <Arduino.h>
#include "DebugLogger.h"

DebugLogger::DebugLogger(char *name) 
{
    strncpy(this -> name, name, MAX_MODULE_NAME_LEN);
    this -> name[MAX_MODULE_NAME_LEN] = '\0';
}

void
DebugLogger::info(char *msg) 
{
    Serial.println("// TODO: DebugLogger::info");
}

void
DebugLogger::warning(char *msg) 
{
    Serial.println("// TODO: DebugLogger::warning");
}

void
DebugLogger::error(char *msg) 
{
    Serial.println("// TODO: DebugLogger::error");
}

void 
print(char *msg)
{
    ;
}