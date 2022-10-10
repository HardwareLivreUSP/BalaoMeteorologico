/*******************************************************************************
 * DataLogger: logs info, debug, warnings and error messages
 * Include this header in your file
 ******************************************************************************/

#ifndef _DATA_LOGGER_H_
#define _DATA_LOGGER_H_

#define MAX_MODULE_NAME_LEN    23

class DataLogger {
  
  private:
    char name[MAX_MODULE_NAME_LEN + 1];
    
  public:
    DataLogger(char *name);

    size_t datalog_write(void *data, size_t dataSize);
};

#endif /* _DATA_LOGGER_H_ */