#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <DHT.h>

#define WIFI_SSID "Jet"
#define WIFI_PASSWORD "12345678"

#define FIREBASE_URL "ionicarduino-2393a.firebaseio.com"
#define FIREBASE_AUTH "lelyI1Z6qbaHrTaU39aYKXZCCUV9CPcT3jVLOVSA"

const int DHTPin = D5;

int DHTValue = 0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Please Wait");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");
  Serial.println("Connected.");
  Serial.print("IP Address : ");
  Firebase.begin(FIREBASE_URL, FIREBASE_AUTH);
  Firebase.stream("/DHTValue/");
  pinMode(buttonPin,INPUT);
  
}

