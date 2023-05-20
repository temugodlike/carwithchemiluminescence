 #include <Servo.h>
 Servo servo1;
 Servo servo2;
 Servo servo3;
  const int motorA1  = 8;  // L298N IN3
  const int motorA2  = 6;  // L298N IN1 
  const int motorB1  = 7; // L298N IN2 
  const int motorB2  = 9;  // L298N IN4 
  int i=0; 
  int j=0; 
  int state; 
  int vSpeed=255;

void setup() {
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT); 
    servo1.attach(2);
    servo2.attach(3);
    servo3.attach(5);  
    Serial.begin(9600);
}
 
void loop() {
    if(Serial.available() > 0){     
      state = Serial.read();   
    }  
/* 4 Speed Levels */      
    if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=100;}
    else if (state == '2'){
      vSpeed=180;}
    else if (state == '3'){
      vSpeed=200;}
    else if (state == '4'){
      vSpeed=255;}
     
  /***********************FORWARD****************************/
    if (state == 'F') {
      analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);
        analogWrite(motorB1, vSpeed);      analogWrite(motorB2, 0); 
    }
  /**********************F-LEFT************************/
    else if (state == 'G') {
      analogWrite(motorA1,vSpeed ); analogWrite(motorA2, 0);  
        analogWrite(motorB1, 100);    analogWrite(motorB2, 0); 
    }
  /**********************F-RIGHT************************/
    else if (state == 'I') {
        analogWrite(motorA1, 100); analogWrite(motorA2, 0); 
        analogWrite(motorB1, vSpeed);      analogWrite(motorB2, 0); 
    }
  /***********************BACK****************************/
    else if (state == 'B') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed); 
    }
  /**********************B-LEFT************************/
    else if (state == 'H') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 100); 
        analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed); 
    }
  /**********************B-RIGHT************************/
    else if (state == 'J') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, 100); 
    }
  /***************************LEFT*****************************/
    else if (state == 'L') {
      analogWrite(motorA1, vSpeed);   analogWrite(motorA2, 150); 
        analogWrite(motorB1, 0); analogWrite(motorB2, 0); 
    }
  /***************************RIGHT*****************************/
    else if (state == 'R') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, vSpeed);   analogWrite(motorB2, 150);     
    }
  
  /************************STOP*****************************/
    else if (state == 'S'){
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
    } 

    /********************SERVO-COMMANDS******************/

    else if (state == 'W'){
        servo1.write(0);
        servo2.write(160);
    }
    else if (state == 'U'){
        servo1.write(30);
        servo2.write(130);
    }
    else if (state == 'V'){
        servo1.write(90);
        servo2.write(70);
    }
    else if (state == 'X'){
        servo1.write(160);
        servo2.write(0);
    }
    else if (state == 'Y'){
      servo3.write(0);
      delay(250);
      servo3.write(75);
      delay(250);
    }
}
