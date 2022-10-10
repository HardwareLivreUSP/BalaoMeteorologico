/*******************************************************************************
 * DebugLogger: logs data from modules
 * Include this header in your file
 ******************************************************************************/

#ifndef _DEBUG_LOGGER_H_
#define _DEBUG_LOGGER_H_

#define MAX_MODULE_NAME_LEN    23

class DebugLogger {
  
  private:
    char name[MAX_MODULE_NAME_LEN + 1];
    
  public:
    DebugLogger(char *name);

    void info(char *msg);
    void warning(char *msg);
    void error(char *msg);
};

#endif /* _DEBUG_LOGGER_H_ */