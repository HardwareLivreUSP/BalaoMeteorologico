#include <Arduino.h>
#include <freertos/queue.h>
#include <freertos/task.h>
#include "template.h"

void
templateLoop()
{
    Serial.println("templateLoop");
    vTaskDelay(500 / portTICK_PERIOD_MS);
}

void 
templateSetup(void *pvParameters)  
{
    Serial.println("templateSetup");
    while (true) templateLoop();
}