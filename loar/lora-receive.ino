#include <SPI.h>
#include <LoRa.h>
 
// Define the pins used by the LoRa module
const int csPin = 4;     // LoRa radio chip select
const int resetPin = 2;  // LoRa radio reset
const int irqPin = 3;    // Must be a hardware interrupt pin
 
// Message counter
byte msgCount = 0;
 
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
 
  Serial.print("Sending packet: ");
  Serial.println(msgCount);
 
  // Send packet
  LoRa.beginPacket();
  LoRa.print("Packet ");
  LoRa.print(msgCount);
  LoRa.endPacket();
 
  // Increment packet counter
  msgCount++;
 
  // 5-second delay
  delay(5000);
}