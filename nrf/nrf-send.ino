#include <SPI.h>
#include <RF24.h>

RF24 radio(4, 2);

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

void loop() {
  const char text[] = "Hello, RF24!";
  radio.write(&text, sizeof(text));
  delay(1000);
}
