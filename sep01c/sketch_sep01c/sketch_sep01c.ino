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

 Firebase.begin(FIREBASE_URL, FIREBASE_AUTH);
 Firebase.setInt("ArDuInO/Servo",0);
 myservo.attach(D6);

}
void loop() {

  myservo.write(Firebase.getInt("ArDuInO/Servo"));

  if (Firebase.available()) {
    FirebaseObject event = Firebase.readEvent();
    int data = event.getInt("data");

    Serial.println(data);
    if (data==0)
    {
      myservo.write(0);
    }
    else if (data==45)
    {
      myservo.write(45);
    }
    if (data==90)
    {
      myservo.write(90);
    }
    else if (data==105)
    {
      myservo.write(105);
    }
    if (data==120)
    {
      myservo.write(120);
    }
    else if (data==135)
    {
      myservo.write(135);
    }
    if (data==160)
    {
      myservo.write(160);
    }
    else if (data==180)
    {
      myservo.write(180);
    }
 }


