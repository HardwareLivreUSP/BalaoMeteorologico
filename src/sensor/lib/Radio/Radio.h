/*******************************************************************************
 * Radio: abstraction for LoRa or GPRS modules
 * Include this header in your file
 ******************************************************************************/

#ifndef _RADIO_H_
#define _RADIO_H_

class Radio {
  
  private:
    
  public:
    Radio();

    size_t write(void *data, size_t dataSize);
    size_t read(char *buffer);
};
#endif /* _RADIO_H_ */