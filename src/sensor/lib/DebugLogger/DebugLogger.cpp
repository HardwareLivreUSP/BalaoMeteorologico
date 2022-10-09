/*******************************************************************************
 DebugLogger.cpp
    Implementation of the logger.
*******************************************************************************/

/**
 * Includes & Macros
 */
#include <Arduino.h>
#include "DebugLogger.h"

#define MAX_MODULE_NAME_LEN    23
#define DBGLOG_NAME            "DebugLogger"

/**
 * Data Structures
 */
struct DebugLogger {
    char name[MAX_MODULE_NAME_LEN + 1];
}

/**
 * dbglog_new - initializes
 */
int
dbglog_new(DebugLogger *dl, char *name)
{
    // TODO: checks if name is too long
    if (strlen(name) > MAX_MODULE_NAME_LEN) {
        // strncpy(dl -> name, name, MAX_MODULE_NAME_LEN);
        // dl -> name[MAX_MODULE_NAME_LEN] = '\0';
        // dbglog_error()
        return -1;
    }
    
    Serial.println("// TODO: dbglog_new");
}
 
int
dbglog_info(DebugLogger *db, char *msg)
{
    Serial.println("// TODO: dbglog_info");
}

int
dbglog_warning(DebugLogger *db, char *msg)
{
    Serial.println("// TODO: dbglog_warning");
}

int
dbglog_error(DebugLogger *db, char *msg)
{
    Serial.println("// TODO: dbglog_error");
}

void 
dbglog_destroy(DebugLogger *dbglog)
{
    Serial.println("// TODO: dbglog_destroy");
}

int 
dbglog_test(DebugLogger *dbglog)
{
    Serial.println("// TODO: dbglog_test");
}