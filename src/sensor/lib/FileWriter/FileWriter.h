/*******************************************************************************
 * FileWriter: abstraction that makes it easier to write to files on the SD card
 * Include this header in your file
 ******************************************************************************/

#ifndef _FILE_WRITER_H_
#define _FILE_WRITER_H_

class FileWriter {
  
    private:
    public:
        FileWriter();
        int create(char *path);
        int append(char *path, char *msg);
        int append(char *path, void *data, size_t dataSize);
};

#endif /* _FILE_WRITER_H_ */