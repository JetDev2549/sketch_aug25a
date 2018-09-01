#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define WIFI_SSID "Iphone7"
#define WIFI_PASSWORD "123456789"

#define FIREBASE_URL "ionicarduino-2393a.firebaseio.com"
#define FIREBASE_AUTH "lelyI1Z6qbaHrTaU39aYKXZCCUV9CPcT3jVLOVSA"

const int LEDPin = D1;

void setup() {
  
 Serial.begin(115200);
 Serial.println(WiFi.localIP());
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

 Serial.println();
 Serial.print("Connected.");
 Serial.println(WiFi.localIP());

 pinMode(LEDPin, OUTPUT);

 Firebase.begin(FIREBASE_URL, FIREBASE_AUTH);
 Firebase.setInt("ArDUINO/LED", 0);
}
void loop() {
  digitalWrite(LEDPin, Firebase.getInt("ArDUINO/LED"));
  delay(200);
 }

