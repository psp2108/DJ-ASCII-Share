#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

int RELAY_ON = 1;
int RELAY_OFF = (RELAY_ON == 1)?0:1;
int DELAY = 300;

char bt='S';
void setup()
{
  Serial.begin(9600);

  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(19,INPUT);
 
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  Stop();
  digitalWrite(19, 1);
  alloff();
}


void loop() {
  bt=Serial.read();

  if(!(digitalRead(19) == 0)){
    alloff();
  }

  switch(bt){
    case 'F':
      forward(); 
      break;
    case 'B':
      backward(); 
      break;
    case 'L':
      left(); 
      break;
    case 'R':
      right(); 
      break;
    case 'S':
      Stop(); 
      break;
    default:
      if(digitalRead(19) == 0){
        switch(bt){
          case '1':
            digitalWrite(14,RELAY_ON);
            delay(DELAY);
            digitalWrite(14,RELAY_OFF);
            break;
          case '2':
            digitalWrite(15,RELAY_ON);
            delay(DELAY);
            digitalWrite(15,RELAY_OFF);    
            break;
          case '3':
            digitalWrite(16,RELAY_ON);
            delay(DELAY);
            digitalWrite(16,RELAY_OFF);
            break;
          case '4':
            digitalWrite(17,RELAY_ON);
            delay(DELAY);
            digitalWrite(17,RELAY_OFF);
            break;
          case '5':
            digitalWrite(18,RELAY_ON);
            delay(DELAY);
            digitalWrite(18,RELAY_OFF);
            break;/*
          case '6':
            digitalWrite(19,RELAY_ON);
            delay(700);
            //digitalWrite(19,RELAY_OFF);
            break;*/
          case 'a':
            pattern1();
            break;
          case '0':
            alloff();
            break;
        }
      }
      break;    
  }
}

void pattern1() {
  digitalWrite(14,RELAY_OFF);
  digitalWrite(18,RELAY_OFF);
  delay(DELAY);
  digitalWrite(14,RELAY_ON);
  digitalWrite(18,RELAY_ON);
  digitalWrite(16,RELAY_OFF);
  delay(DELAY);
  digitalWrite(16,RELAY_ON);
  digitalWrite(15,RELAY_OFF);
  digitalWrite(17,RELAY_OFF);
  delay(DELAY);
  digitalWrite(15,RELAY_ON);
  digitalWrite(17,RELAY_ON);
}

void alloff(){
  for(int i=14; i<=18; i++){
    digitalWrite(i,RELAY_OFF);
  }
}
void allon(){
  for(int i=14; i<=18; i++){
    digitalWrite(i,RELAY_ON);
  }
}

void forward() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void backward() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void left() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void right() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}











