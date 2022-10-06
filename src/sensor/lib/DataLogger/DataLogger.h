/*******************************************************************************
 * DataLogger: logs info, debug, warnings and error messages
 * Include this header in your file
 ******************************************************************************/

#ifndef _DATA_LOGGER_H_
#define _DATA_LOGGER_H_

typedef struct DataLogger DataLogger;

/**
 * Available operations
 */
DataLogger *datalog_new();                                   
size_t datalog_write(DataLogger *dl, void *data, size_t dataSize);
void datalog_destroy(DataLogger *dl);                         
int datalog_test(DataLogger *dl);                                    

#endif /* _DATA_LOGGER_H_ */