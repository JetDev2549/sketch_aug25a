#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <Servo.h>

#define WIFI_SSID "Jet"
#define WIFI_PASSWORD "12345678"

#define FIREBASE_URL "ionicarduino-2393a.firebaseio.com"
#define FIREBASE_AUTH "lelyI1Z6qbaHrTaU39aYKXZCCUV9CPcT3jVLOVSA"

Servo myservo;

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

 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 Firebase.setInt("ArDuInO/Servo",0);
 myservo.attach(D6);


