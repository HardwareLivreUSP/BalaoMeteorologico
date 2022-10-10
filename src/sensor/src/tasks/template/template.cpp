#include <Arduino.h>
#include <freertos/queue.h>
#include <freertos/task.h>
#include <DebugLogger.h>
#include <DataLogger.h>
#include <Radio.h>
#include "template.h"

static DebugLogger debug(MODULE_NAME);
static DataLogger data(MODULE_NAME);
static Radio r();

void 
templateSetup(void *pvParameters)  
{
    debug.info("templateSetup");
    while (true) templateLoop();
}

void
templateLoop()
{
    debug.info("templateLoop");
    vTaskDelay(500 / portTICK_PERIOD_MS);
}

