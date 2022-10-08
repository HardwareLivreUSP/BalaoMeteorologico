/*
 * TODO: comment
 * 
 * 
 */

#include <Arduino.h>
#include <freertos/queue.h>
#include <freertos/task.h>
#include "tasks.h"
#include "accelerometer.h"
void 
setup() 
{
    Serial.begin(115200);
    // TODO: Create Radio, DataLogger and DebugLogger
    // TODO: Pass them as arguments to each task
    
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

