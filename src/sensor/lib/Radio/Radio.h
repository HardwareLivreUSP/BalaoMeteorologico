/*******************************************************************************
 * Radio: abstraction for LoRa or GPRS modules
 * Include this header in your file
 ******************************************************************************/

#ifndef _RADIO_H_
#define _RADIO_H_

typedef struct Radio Radio;

/**
 * Available operations
 */
Radio *radio_new();                                   
size_t radio_write(Radio *r, void *data, size_t dataSize);
size_t radio_read(Radio *r, char *buffer);
void radio_destroy(Radio *r);                         
void radio_test(Radio *r);                                    

#endif /* _RADIO_H_ */