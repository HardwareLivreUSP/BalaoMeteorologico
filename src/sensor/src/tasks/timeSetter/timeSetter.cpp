#include <Arduino.h>
#include <freertos/queue.h>
#include <freertos/task.h>
#include <DebugLogger.h>
#include "time.h"
#include "timeSetter.h"

static DebugLogger dbglog(TASK_NAME);
static bool *wifiConnected;

void 
timeSetterSetup(void *parameters)  
{
    dbglog.info("Setting up timeSetter task...");
    wifiConnected = (bool *) parameters;
    while (true) timeSetterLoop();
}

void
timeSetterLoop()
{
    dbglog.info("Running timeSetter loop...");
    // TODO: exchange WiFi.status for a globally available variable
    if (*wifiConnected) {
        dbglog.debug("WiFi is connected");
        configTime(GMT_OFFSET, DAYLIGHT_OFFSET, NTP_SERVER);
        dbglog.debug("Time was fetched from the ntp server!");
    }
    else {
        dbglog.debug("WiFi is not connected");
    }

    vTaskDelay(TIME_SETTING_INTERVAL / portTICK_PERIOD_MS);
}