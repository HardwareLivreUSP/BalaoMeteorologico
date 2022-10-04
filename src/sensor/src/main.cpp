/*
 * TODO: comment
 * 
 * 
 */

#include <Arduino.h>
#include <freertos/queue.h>
#include <freertos/task.h>
#include <template.h>

void 
setup() 
{
    Serial.begin(9600);
    // TODO: Create Radio, DataLogger and DebugLogger
    // TODO: Pass them as arguments to each task
    // TODO: Create and initialize array of tasks
    xTaskCreate(templateTask, "templateTask", 128, NULL, 1, NULL);
    vTaskStartScheduler();
}

void 
loop()
{
    ;
}

