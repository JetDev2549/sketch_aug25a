#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <DHT.h>

#define WIFI_SSID "Jet"
#define WIFI_PASSWORD "12345678"

#define FIREBASE_URL "ionicarduino-2393a.firebaseio.com"
#define FIREBASE_AUTH "lelyI1Z6qbaHrTaU39aYKXZCCUV9CPcT3jVLOVSA"

const int DHTPin = D5;
const int DHTType DHT11


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
  Serial.print(WiFi.localIP());
  Firebase.begin(FIREBASE_URL, FIREBASE_AUTH);
  Serial.begin(115200);
  Serial.println();
  dht.begin()
  
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  //Credits to auditronics.com for helping me out. with the above part.
  if (isnan(t)|| isnan(h)) {
    Serial.println("Failed");
  } else {
    Firebase.setInt(h);
    Firebase.setInt
  }
   


}

