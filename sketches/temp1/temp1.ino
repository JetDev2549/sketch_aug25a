#include <DHT11.h>
int pin = 4;
DHT11 dhtll(pin);

float Fahrenheit(float celsius){
  return ((float)(9/5)*celsius)+32;
}

float Kelvin(float celsius){
  return celsius + 273;
}

void setup() {
  Serial.begin(9600);
  Serial.println("Test");
  
  
}

void loop() {
  int err;
  float temp, humi;
  if ((err = dhtll.read(humi, temp)) == 0)


Serial.print("Temp: ");
Serial.print(temp);
Serial.print("  *C\t");
Serial.print("Humidity");
Serial.print(humi);
Serial.print("  %\t\n");
}
