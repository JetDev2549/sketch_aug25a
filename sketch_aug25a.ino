
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

//Do not copy WiFi links. This is only for my device.
#define WIFI_SSID "Jet"
#define WIFI_PASSWORD "12345678"

//Example Links Below. Do Not Copy These Links!
#define FIREBASE_URL "ionicarduino-2393a.firebaseio.com"
#define FIREBASE_AUTH "lelyI1Z6qbaHrTaU39aYKXZCCUV9CPcT3jVLOVSA"

const int buttonPin = D2;
const int ledPin = D3;

int buttonState = 0;

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
  Firebase.stream("/Button/");
  pinMode(buttonPin,INPUT);
  
}


void loop() {
  {
    buttonState = digitalRead(buttonPin);
    if (buttonState == 1)
    {
      digitalWrite(ledPin, HIGH);
      Firebase.setInt("Button",buttonState);
      Serial.println(buttonState);
      delay(500);
    }
    else if (buttonState == 0)
    {
      digitalWrite(ledPin, LOW);
      Firebase.setInt("Button",buttonState);
      Serial.println(buttonState);
      delay(500);
    }
  }
}
  
