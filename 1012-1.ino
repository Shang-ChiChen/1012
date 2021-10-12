#include<Servo.h>
Servo myservo;

const int servoPin = 14;
int pos = 0;
void setup() {
  myservo.attach(servoPin);
  Serial.begin(115200);
  pinMode(12, INPUT);
}

void loop() {
 int input = analogRead(12);
 input = input*0.044;
 Serial.println(input);
 myservo.write(input);
 delay(10);
}
