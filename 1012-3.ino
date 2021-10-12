#include <Stepper.h> //引入步進馬達函示庫

const int stepsPerRevolution = 2048;  //此馬達轉一圈為2048步
const int RPM = 5; //馬達旋轉速度

//宣告Stepper物件，的步數和引腳
//引角依序對應驅動版的1N1、1N3、1N2、1N4
Stepper myStepper(stepsPerRevolution, 13, 14, 12, 27);  

void setup() {  
  pinMode(23, INPUT);
  pinMode(21, INPUT);
  Serial.begin(115200);
  myStepper.setSpeed(RPM);  //設定馬達轉速
}

void loop() {
  
  if(digitalRead(23)){
    myStepper.step(stepsPerRevolution/360);
    }else if(digitalRead(21)){
    myStepper.step(-stepsPerRevolution/360);
    }else{
      myStepper.step(0);
    }
  delay(10);

}
