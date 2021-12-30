/*
#include "RobotIndustrial.h"


RobotIndustrial R;


void setup() {
  Serial.begin(115200);
  R.addArticulacion("SERVO", "ServoSmall",  8);
  R.addArticulacion("SERVO", "Servolarge",  9);
  R.addMovimiento("ServoSmall", 10, 170);
  R.addMovimiento("Servolarge", 10, 90);
  R.addSensor("ULTRASONIC", "ULTRASONIC1", 3, 2);
  R.addSensor("PIR", "PIR1", 4);
}

void loop() {
  R.action();
  Serial.println(R.readdatadromsensor("ULTRASONIC1"));
  if (R.readdatadromsensor("PIR1") == 1) {
    Serial.println("There is motion");
  }
  else if (R.readdatadromsensor("PIR1") == 0) {
    Serial.println("There is no motion");
  }
}
*/
#include "RobotIndustrialespcifico.h"

RobotIndustrialespcifico R1;

void activity1(){
  
// There is a motion
  if(R1.readdatafromsensor("PIR1") == 1){
    R1.executemove("Motion1");
  }
  else{
    //there in no movement you can do a specific movement
  }
}


void activity2(){
    if(R1.readdatafromsensor("ULTRASONIC1") >= 80){
    R1.executemove("Motion2");
  }
  else{
    R1.executemove("Motion3");
    //there in no movement you can do a specific movement
  }
}
void setup() {
  /*R.addArticulacion("SERVO", "ServoSmall",  8);*/
  Serial.begin(9600);
  /*
  R1.addRoutine1();
  R1.addRoutine2();*/
  /*R1.addSensor("ULTRASONIC", "ULTRASONIC1", 5, 4);
  /*R1.addSensor("Infrarrojo", "Infrarrojo1", 3);
  R1.addSensor("Generico", "generico1", 2);
  
  R1.robotassembly();*/
  R1.armarRobot();
  R1.rutinadeMovimientos();
  R1.robotassembly();
  R1.addactivity("a1" , activity1);
  R1.addactivity("b1" , activity2);
}


void loop() {
  R1.action();
 // R1.action("b1"); 
   
/*
 /* Serial.println(R1.readdatafromsensor("ULTRASONIC1"));
  if (R1.readdatafromsensor("generico1") == 0) {
    Serial.println("There is motion");
  }

    if (R1.readdatafromsensor("Infrarrojo1") == 0) {
    Serial.println("There is motion2");
  }*/
}
