#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define WIFI_SSID "Jet"
#define WIFI_PASSWORD "12345678"

#define FIREBASE_URL "<Firebase-URL>"
#define FIREBASE_AUTH "<Firebase-Password>"
//You need 

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
  //Makes a new directory in Database
 }

