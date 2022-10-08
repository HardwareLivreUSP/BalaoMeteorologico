/*******************************************************************************
 DebugLogger.cpp
    Implementation of the logger.
*******************************************************************************/

/**
 * Includes & Macros
 */
#include <Arduino.h>
#include "DebugLogger.h"

/**
 * Data Structures
 */

/**
 * dbglog_new - initializes
 */
DebugLogger *
dbglog_new()
{
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