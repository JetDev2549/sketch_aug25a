#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>



#define WIFI_SSID "<SSID>"
#define WIFI_PASSWORD "<Password>"

#define FIREBASE_URL "<Firebase-URL>"
#define FIREBASE_AUTH "<Firebase-Password>"
//Use Realtime Database, because Cloud Firestore is not compatible with Arduino yet.

const int DHTPin = D5;
const int DHTType = DHT11;
//This assums that you have DHT11, if you have DHT22, type it in like this.
//const int DHTType = DHT22;
const int LEDPin = D1;
const int LEDPin2 = D2;
 DHT dht(DHTPin, DHTType);

void setup() {
  
  Serial.println("");
  Serial.println("Connected.");
  Serial.print(WiFi.localIP());
  Firebase.begin(FIREBASE_URL, FIREBASE_AUTH);
  Serial.begin(115200);
  Serial.println();
  dht.begin();
  
}

void loop() {
  float temperature, humidity;


  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Please Wait");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  delay(2000);

  char tempF[6];
  char humF[6];
  dtostrf(temperature, 5, 1, tempF);
  dtostrf(humidity, 5, 1, humF);
  Firebase.setFloat("Arduino/temperature", atof(tempF));
  Firebase.setFloat("Arduino/humidity", atof(humF));
  Serial.print("T:");
  Serial.print(tempF);
  Serial.print("H: ");
  Serial.print(humF);
  Serial.println("%");
  if (temperature > 30)
  {
    digitalWrite(LEDPin, HIGH);
  } else {
    digitalWrite(LEDPin, LOW);
  }
  if (temperature < 10)
  {
    digitalWrite(LEDPin2, HIGH);

  } else {
    digitalWrite(LEDPin2, LOW);
  }
  
  
   


}

