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

static DebugLogger dl;

/**
 * dbglog_new - initializes
 */
DebugLogger *
dbglog_new(char *name)
{
    DebugLogger *dl = 
    if (strlen(name) > MAX_MODULE_NAME_LEN) {
        strncpy(module_name, name, MAX_MODULE_NAME_LEN);
        module_name[MAX_MODULE_NAME_LEN] = '\0';
        dbglog_error()
        return NULL;
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