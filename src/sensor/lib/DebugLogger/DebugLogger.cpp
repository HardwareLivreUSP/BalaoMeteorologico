/*******************************************************************************
 DebugLogger.cpp
    Implementation of the logger.
*******************************************************************************/

#include <Arduino.h>
#include "DebugLogger.h"
#include "../../include/sd.h"

#define INFO_PREFIX            "INFO"
#define WARNING_PREFIX         "WARN"
#define ERROR_PREFIX           "ERROR"

static FileWriter fw;

DebugLogger::DebugLogger(char *name) 
{
    strncpy(this -> name, name, MAX_MODULE_NAME_LEN);
    this -> name[strlen(name)] = '\0';
    snprintf(this -> logPath, MAX_LOG_FILE_LEN, "%s%s", LOG_FOLDER, name);
    fw.create(this -> logPath);
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
DebugLogger::print(const char *prefix, char *msg)
{
    char line[MAX_LINE_LEN];
    time_t rawtime;
    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)) return;
    char timeString[64];
    strftime(timeString, sizeof(timeString), "%A, %B %d %Y %H:%M:%S", &timeinfo);
    snprintf(line, MAX_LINE_LEN, "[%s]\t%s\t%s\t%s\n", timeString, prefix, this -> name, msg);
    Serial.print(line);
    fw.append(this -> logPath, line);
}