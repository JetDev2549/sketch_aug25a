URL: arduino-23468.firebaseio.com
Auth: PguRO8UGBa2Bw9o6aLyAor4H7qyQGpOpeQEa8Wrq

#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID "heating spotttt"
#define WIFI_PASSWORD "lmaoman123"

#define FIREBASE_URL "arduino-23468.firebaseio.com"
#define FIREBASE_AUTH "PguRO8UGBa2Bw9o6aLyAor4H7qyQGpOpeQEa8Wrq"

void setup() {
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
}

void loop() {
  digitalWrite(D1, LOW);
  delay(500);
  digitalWrite(D1, HIGH);
  delay(500);
  digitalWrite(D1, LOW);
  delay(500);
  digitalWrite(D2, LOW);
  delay(500);
  digitalWrite(D2, HIGH);
  delay(500);
  digitalWrite(D2, LOW);
  delay(500);
}
