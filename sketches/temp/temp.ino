#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht (DHTPIN, DHTTYPE);

void setup {
  Serial.begin(9600);
  Serial.println("test text");

 dht.begin();
}

void loop(){
  delay(1000);
  float h = dht.readHumidity;
  float t = dht.readTemperature;
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("DHT failed to read data.");
    return;
  }
  Serial.print("Humidity:  ")
  Serial.print(h);
  Serial.print("Temperature);
  Serial.print(t);
  Serial.print(" C  ");
  Serial.print(f);
  Serial.print("  F/t/n");
}

