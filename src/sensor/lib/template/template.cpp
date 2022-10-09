#include <Arduino.h>
#include <freertos/queue.h>
#include <freertos/task.h>
#include <DebugLogger.h>
#include "template.h"

#define MODULE_NAME     "template"
DebugLogger dl;

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
    dbglog_init(&dl, MODULE_NAME);
    while (true) templateLoop();
}