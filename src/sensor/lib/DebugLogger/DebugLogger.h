/*******************************************************************************
 * DebugLogger: logs data from modules
 * Include this header in your file
 ******************************************************************************/

#ifndef _DEBUG_LOGGER_H_
#define _DEBUG_LOGGER_H_

#include "FileWriter.h"

#define MAX_MODULE_NAME_LEN    23
#define MAX_LINE_LEN           128
#define MAX_LOG_FILE_LEN       64

class DebugLogger {
  
  private:
    char name[MAX_MODULE_NAME_LEN + 1];
    char logPath[MAX_LOG_FILE_LEN];
    void print(const char *prefix, char *msg);
    
  public:
    DebugLogger(char *name);

    void info(char *msg);
    void warning(char *msg);
    void error(char *msg);
};

#endif /* _DEBUG_LOGGER_H_ */