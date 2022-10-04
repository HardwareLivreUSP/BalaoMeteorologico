#include <Arduino.h>
#include <freertos/queue.h>
#include <freertos/task.h>
#include "template.h"

void 
templateTask(void *pvParameters)  
{
    Serial.println("templateTask");
}
