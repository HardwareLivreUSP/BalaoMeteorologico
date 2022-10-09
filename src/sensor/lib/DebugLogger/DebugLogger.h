/*******************************************************************************
 * DebugLogger: logs info, debug, warnings and error messages
 * Include this header in your file
 ******************************************************************************/

#ifndef _DEBUG_LOGGER_H_
#define _DEBUG_LOGGER_H_

typedef struct DebugLogger DebugLogger;

/**
 * Available operations
 */
DebugLogger *dbglog_new(char *name);                                   
int dbglog_info(DebugLogger *db, char *msg);
int dbglog_warning(DebugLogger *db, char *msg);
int dbglog_error(DebugLogger *db, char *msg);
void dbglog_destroy(DebugLogger *db);                         
int dbglog_test(DebugLogger *db);                                    

#endif /* _DEBUG_LOGGER_H_ */