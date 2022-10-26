#include <Arduino.h>
#include <freertos/queue.h>
#include <freertos/task.h>
#include <DebugLogger.h>
#include <DataLogger.h>
#include <Radio.h>
#include "template.h"

static DebugLogger dbglog(MODULE_NAME);
static DataLogger  dtlog(MODULE_NAME);
static Radio r();

void 
templateSetup(void *parameters)  
{
    dbglog.info("templateSetup");
    while (true) templateLoop();
}

void
templateLoop()
{
    dbglog.info("templateLoop");
    vTaskDelay(500 / portTICK_PERIOD_MS);
}

