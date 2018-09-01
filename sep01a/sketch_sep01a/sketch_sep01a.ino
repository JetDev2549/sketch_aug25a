#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>



#define WIFI_SSID "Jet"
#define WIFI_PASSWORD "12345678"

#define FIREBASE_URL "ionicarduino-2393a.firebaseio.com"
#define FIREBASE_AUTH "lelyI1Z6qbaHrTaU39aYKXZCCUV9CPcT3jVLOVSA"

const int DHTPin = D5;
const int DHTType = DHT11;
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
  Serial.print("C0");
  Serial.print("H: ");
  Serial.print(humF);
  Serial.println("%");
  }
   


}

