/*******************************************************************************
 Radio.cpp
    Implementation of the transmitter.
*******************************************************************************/

/**
 * Includes & Macros
 */
#include <Arduino.h>
#include "Radio.h"

/**
 * Data Structures
 */


/**
 * radio_new - initializes
 */
Radio *
radio_new()
{
    Serial.println("// TODO: radio_new");
}

size_t 
radio_write(Radio *r, void *data, size_t dataSize)
{
    Serial.println("// TODO: radio_write");
}

size_t 
radio_read(Radio *r, char *buffer)
{
    Serial.println("// TODO: radio_read");
}

void 
radio_destroy(Radio *r)
{
    Serial.println("// TODO: radio_destroy");
}

void 
radio_test(Radio *r)
{
    Serial.println("// TODO: radio_test");
}