#include <WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "SEU_SSID";       // Substituir pelo seu WiFi
const char* password = "SUA_SENHA";
WiFiClient client;

unsigned long myChannelNumber = 1234567; // Substituir pelo seu número de canal
const char * myWriteAPIKey = "SUA_API_KEY"; // Substituir pela API do canal

const int sensorPin = 4;
int pulseCount = 0;
bool lastState = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(1000);

  ThingSpeak.begin(client);
}

void loop() {
  bool currentState = digitalRead(sensorPin);

  if (lastState == HIGH && currentState == LOW) {
    pulseCount++;
    Serial.println("Pulso detectado!");
  }
  lastState = currentState;

  // Envia para o ThingSpeak a cada 15s
  static unsigned long lastSend = 0;
  if (millis() - lastSend > 15000) {
    ThingSpeak.writeField(myChannelNumber, 1, pulseCount, myWriteAPIKey);
    Serial.print("Pulsos enviados: ");
    Serial.println(pulseCount);
    lastSend = millis();
  }
}
