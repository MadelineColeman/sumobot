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
void offA(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
}
void offB(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}
void onA(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA,100);
}
void onB(){
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 100);
}
void oppDirA(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA,100);
}
void oppDirB(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB,100);
}
void loop() {
  onA();
  onB();
  delay(1000);
  offA();
  offB();
  delay(250);
  onA();
  oppDirB();
  delay(1000);
  offA();
  offB();
  delay(250);

  }
