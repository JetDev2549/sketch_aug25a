const int pingPin = D1;
int inPin = D2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long duration, cm;
  pinMode(pingPin, LOW);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  unsigned int PulseWidth = pulseln(pingPin, HIGH);
  unsigned int distance = PulseWidth / 29 / 2;
  
  
  
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 /2;
}

