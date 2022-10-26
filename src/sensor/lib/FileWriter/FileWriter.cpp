/*******************************************************************************
 FileWriter.cpp
    Implementation.
*******************************************************************************/

#include <Arduino.h>
#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include "FileWriter.h"
#include "../../include/pins.h"

FileWriter::FileWriter() 
{
    if(!SD.begin(PIN_SPI_CS)) {
        char line[128];
        time_t rawtime;
        struct tm timeinfo;
        if(!getLocalTime(&timeinfo)) return;
        char timeString[64];
        strftime(timeString, sizeof(timeString), "%A, %B %d %Y %H:%M:%S", &timeinfo);
        snprintf(line, 128, "[%s]\t%s\t%s\t%s\n", timeString, "ERROR", "FileWriter", "Cannot initiate SD card!");
        Serial.print(line);
    }
}

int
FileWriter::create(char *path) 
{
    File file = SD.open(path, FILE_WRITE);
    if (!file || !SD.exists(path)) return -1;
    file.close();
    return 0;
}

int
FileWriter::append(char *path, char *msg) 
{
    File file = SD.open(path, FILE_WRITE);
    if (!file || !SD.exists(path)) return -1;
    int bytesWritten = (int) file.print(msg);
    file.close();
    return bytesWritten;

}

int
FileWriter::append(char *path, void *data, size_t dataSize) 
{
    File file = SD.open(path, FILE_WRITE);
    if (!file || !SD.exists(path)) return -1;
    int bytesWritten = (int) file.write((const uint8_t*) data, dataSize);
    file.close();
    return bytesWritten;

}