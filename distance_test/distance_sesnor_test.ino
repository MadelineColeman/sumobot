#define trigPin 12
#define echoPin 13

float duration, distance;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //sends a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //measure response
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  //determine distance from duration

  distance = (duration / 2) * 0.0343;

  //send results to monitor

  Serial.print("Distance =");
  if (distance >= 400 || distance <= 2) {
    Serial.println("Out of Range :(");
  }
  else {
    Serial.print(distance);
    Serial.println("cm");
    delay(500);
  }
  delay(500);
}
