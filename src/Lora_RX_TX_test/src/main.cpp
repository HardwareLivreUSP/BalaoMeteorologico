#include <Arduino.h>
#include "heltec.h"

#define BAND 868E6

#define RX

int counter = 0;


void loraConfig() {
    LoRa.setSpreadingFactor(8);           // ranges from 6-12,default 7 see API docs
    LoRa.setTxPower(20, RF_PACONFIG_PASELECT_PABOOST);
    LoRa.setSignalBandwidth(125E3);
    LoRa.setCodingRate4(4);
    LoRa.setSyncWord(0x12);   
    LoRa.setPreambleLength(8);
    LoRa.dumpRegisters(Serial);
}

void sendPacketLora() {
    Serial.print("Numero de pacote enviado: " + String(counter));
    LoRa.beginPacket();
    LoRa.print(counter);
    LoRa.endPacket();
    Heltec.display->drawString(0, 0, "Pkt enviado:");
    Heltec.display->drawString(0, 30, String(counter));
    Heltec.display->clear();
}

void onReceiveLora(int packetSize){
    String incoming = "";
    Heltec.display->clear();
    if (packetSize) {
        while (LoRa.available()) incoming += (char)LoRa.read();
        Heltec.display->drawString(0, 0, + "Recv: " + String(incoming));
        Serial.println("Message: " + incoming);
        Serial.println("RSSI: " + String(LoRa.packetRssi()));
        Serial.println("Snr: " + String(LoRa.packetSnr()));
        Serial.println();
        Heltec.display->drawString(0, 30, + "RSSI:" + String(LoRa.packetRssi()));
        Heltec.display->display();
    }
}

void setup() {
    Serial.begin(115200);
    Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.Heltec.Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
    Heltec.display->init();
    Heltec.display->setContrast(255);
    Heltec.display->setFont(ArialMT_Plain_24);
    Heltec.display->clear(); 
    Heltec.display->drawString(0, 0, "Heltec.LoRa Initial success!");
    Heltec.display->display();  
    loraConfig(); 
}




void loop() {
    #ifdef TX
        sendPacketLora();
    #endif
    #ifdef RX
        onReceiveLora(LoRa.parsePacket());
    #endif
}

