#include <SPI.h>
#include <LoRa.h>
 
// Define the pins used by the LoRa module
const int csPin = 5;     // LoRa radio chip select
const int resetPin = 14;  // LoRa radio reset
const int irqPin = 2;    // Must be a hardware interrupt pin
 
void setup() {
  Serial.begin(9600);
  delay(1000); // 等待一秒鐘，確保串口初始化完成

  // Setup LoRa module
  LoRa.setPins(csPin, resetPin, irqPin);
  LoRa.setSpreadingFactor(7); // 將擴散因子設置為 7
  Serial.println("LoRa Receiver Test");

  // Start LoRa module at local frequency
  // 433E6 for Asia
  // 866E6 for Europe
  // 915E6 for North America

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

 
void loop() {
 
  // Try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // Received a packet
    Serial.print("Received '");
 
    // Read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
 
    // Print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}