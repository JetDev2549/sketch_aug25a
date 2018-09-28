#define Trig_PIN D1
#define Echo_PIN D2
//Change this according to your location of wires!

//You nned an ultrasonic sensor to use this file.
void setup() {
  pinMode(Echo_PIN, INPUT);
  pinMode(Trig_PIN, OUTPUT);
  pinMode(D4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(Trig_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(Trig_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_PIN, LOW);
  unsigned int PulseWidth = pulseIn(Echo_PIN, HIGH);
  unsigned int distance = PulseWidth * 0.0173681;

  Serial.print("Distance is  ");
  Serial.print(distance);
  Serial.println(" cm.");
  delay(100);

  if (distance <= 30)
  {
    digitalWrite(D4, HIGH);
  }
  else{
    digitalWrite(D4, LOW);
  }
}

