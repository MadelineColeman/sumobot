#define trigPin 12
#define echoPin 13
float duration, distance;

// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;

// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

void offA() {
  //turns off left motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
}
void offB() {
  //turns off right motor
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}
void onA() {
  //turns on left motor
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 100);
}
void onB() {
  //turns on right motor
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 100);
}
void oppDirA() {
  //turns on left motor in opp dir
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 50);
}
void oppDirB() {
  //turns on right motor in opp dir
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 50);
}
float distance_sensor() {
  //uses ultrasonic sensor to deterimine distance 
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

  return distance;
}
int phRes() {
  //takes reading from photo resistor
  int phRes = analogRead(A0);
  return phRes;
}
void border() {
  //moves robot back if it is at the edge of ring
  if (phRes() > 600) {
    oppDirA();
    oppDirB();
    delay(1000);
  }

}
void setup() {
  Serial.begin(9600);

  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //distance setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}
void loop() {
  //Serial.println(phRes());
  border();
  if (distance_sensor() < 10) {
    //Serial.println("enter");
    onA();
    onB();
    delay(100);
  }
  else {
    //Serial.println("searching");
    offA();
    offB();
    delay(10);
    oppDirA();
    onB();
    delay(100);
  }
}
