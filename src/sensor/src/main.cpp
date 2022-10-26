/*
 * TODO: comment
 */

#include <Arduino.h>
#include <ESP32Time.h>
#include <freertos/queue.h>
#include <freertos/task.h>
#include "tasks.h"
#include "tasks/template/template.h"
#include "tasks/timeSetter/timeSetter.h"
// #include "tasks/wifiManager/wifiManager.h"

static bool wifiConnected = false;
Task tasks[] = {  
//  { setupFunction, "taskName", stackSize, parameters, priority },
    { templateSetup, "template", 4096, NULL, 2 },
    { timeSetterSetup, "timeSetter", 4096, &wifiConnected, 2 },
    // { wifiManagerSetup, "wifiManager", 4096, &wifiConnected, 2 },
};

void 
setup() 
{
    Serial.begin(115200);
    // TODO: Create Radio, DataLogger and DebugLogger/FileWriter mutex
    // TODO: Pass them as arguments to each task

    // Initializes time as default value to allow logging to start
    ESP32Time rtc;
    rtc.setTime();

    // Creates all tasks
    uint8_t numberOfTasks = sizeof(tasks) / sizeof(Task);
    for (int i = 0; i < numberOfTasks; i++)
        xTaskCreate(
            tasks[i].setup, 
            tasks[i].name, 
            tasks[i].stackSize, 
            tasks[i].parameters,
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