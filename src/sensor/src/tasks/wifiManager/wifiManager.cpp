// #include <Arduino.h>
// #include <WiFi.h>
// #include <freertos/queue.h>
// #include <freertos/task.h>
// #include <DebugLogger.h>
// #include "wifiManager.h"

// static DebugLogger dbglog(TASK_NAME);

// void 
// wifiManagerSetup(void *parameters)  
// {
//     dbglog.info("Setting up wifiManager task...");
//     Serial.printf("Connecting to %s ", ssids);
//     WiFi.begin(ssids, passwords);
//     while (WiFi.status() != WL_CONNECTED) {
//         delay(500);
//         Serial.print(".");
//     }
//     Serial.println(" CONNECTED");
//     while (true) wifiManagerLoop();
// }

// void
// wifiManagerLoop()
// {
//     dbglog.info("Running wifiManager loop...");
    
//     vTaskDelay(WIFI_CHECKING_INTERVAL / portTICK_PERIOD_MS);
// }



// // void setup()
// // {
// //   Serial.begin(115200);
  
// //   //connect to WiFi
// //   Serial.printf("Connecting to %s ", ssid);
// //   WiFi.begin(ssid, password);
// //   while (WiFi.status() != WL_CONNECTED) {
// //       delay(500);
// //       Serial.print(".");
// //   }
// //   Serial.println(" CONNECTED");
  
// //   //init and get the time
// //   configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
// //   printLocalTime();

// //   //disconnect WiFi as it's no longer needed
// //   WiFi.disconnect(true);
// //   WiFi.mode(WIFI_OFF);
// // }

// // void loop()
// // {
// //   delay(1000);
// //   printLocalTime();
// // }