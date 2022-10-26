/*******************************************************************************
 DebugLogger.cpp
    Implementation of the logger.
*******************************************************************************/

#include <Arduino.h>
#include "DebugLogger.h"
#include "../../include/sd.h"

#define INFO_PREFIX            "I"
#define DEBUG_PREFIX           "D"
#define WARNING_PREFIX         "W"
#define ERROR_PREFIX           "E"

// TODO: reactivate SD-related functions
// static FileWriter fw;

DebugLogger::DebugLogger(char *name) 
{
    strncpy(this -> name, name, MAX_MODULE_NAME_LEN);
    this -> name[strlen(name)] = '\0';
    snprintf(this -> logPath, MAX_LOG_FILE_LEN, "%s%s", LOG_FOLDER, name);
    // TODO: reactivate SD-related functions
    // fw.create(this -> logPath);
}

void
DebugLogger::info(char *msg) 
{
    print(INFO_PREFIX, msg);
}

void
DebugLogger::debug(char *msg) 
{
    print(DEBUG_PREFIX, msg);
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
DebugLogger::print(const char *prefix, char *msg)
{
    char line[MAX_LINE_LEN];
    time_t rawtime;
    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)) return;
    char timeString[64];
    strftime(timeString, sizeof(timeString), "%A, %B %d %Y %H:%M:%S", &timeinfo);
    snprintf(line, MAX_LINE_LEN, "[%s] %s %s %s\n", timeString, prefix, this -> name, msg);
    Serial.print(line);
    // TODO: reactivate SD-related functions
    // fw.append(this -> logPath, line);
}