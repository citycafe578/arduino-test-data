#include <HardwareSerial.h>

// 定義ATGM336H的TX和RX引腳
const int gpsRxPin = 16; // ATGM336H的TX引腳連接到ESP32的16號引腳
const int gpsTxPin = 17; // ATGM336H的RX引腳連接到ESP32的17號引腳

// 定義硬體串口對象
HardwareSerial gpsSerial(1); // 使用硬體串口1

void setup() {
  // 初始化串口通訊
  Serial.begin(9600); // 初始化ESP32的串口
  gpsSerial.begin(9600, SERIAL_8N1, gpsRxPin, gpsTxPin); // 初始化GPS模組的串口
}

void loop() {
  if (gpsSerial.available() > 0) {
    // 如果從GPS模組收到了數據
    char c = gpsSerial.read(); // 讀取一個字符
    Serial.print(c); // 將字符輸出到ESP32的串口
  }

}