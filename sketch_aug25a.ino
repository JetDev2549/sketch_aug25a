URL: arduino-23468.firebaseio.com
Auth: PguRO8UGBa2Bw9o6aLyAor4H7qyQGpOpeQEa8Wrq

#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID "heating spotttt"
#define WIFI_PASSWORD "lmaoman123"

#define FIREBASE_URL "arduino-23468.firebaseio.com"
#define FIREBASE_AUTH "PguRO8UGBa2Bw9o6aLyAor4H7qyQGpOpeQEa8Wrq"

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Please Wait");
  while (WiFi.status() != WL_CONNECTED
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");
  Serial.println("Connected.");
  Serial.print("IP Address : "):
  Firebase.begin(FIREBASE_URL, FIREBASE_AUTH);
  
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
