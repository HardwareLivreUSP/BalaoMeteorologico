/*
 * TODO: comment
 * 
 * 
 */

#include <Arduino.h>
#include <freertos/queue.h>
#include <freertos/task.h>
#include <Radio.h>
#include <DataLogger.h>
#include <DebugLogger.h>
#include "tasks.h"
#include "accelerometer.h"
#include "temppressure.h"
void 
setup() 
{
    Serial.begin(115200);
    // TODO: Create Radio and DataLogger mutex
    // TODO: Pass them as arguments to each task
    Radio *r = radio_new();
    
    uint8_t numberOfTasks = sizeof(tasks) / sizeof(Task);
    for (int i = 0; i < numberOfTasks; i++)
        xTaskCreate(
            tasks[i].setup, 
            tasks[i].name, 
            tasks[i].stackSize, 
            NULL, 
            tasks[i].priority, 
            NULL
        );
}

void 
loop()
{
    // TODO: manage tasks
    ;
}

