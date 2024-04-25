#include <SPI.h>
#include <RF24.h>

RF24 radio(4, 2);

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, address); // 打开接收管道1，并设置地址
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening(); // 开始监听
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}