#include "RobotIndustrialespcifico.h"
    void  (*activities[MAX_ACTIVITIES]) ();

void RobotIndustrialespcifico::armarRobot() {
  
  this->addArticulacion("SERVO", "ServoSmall",  8);
  this->addArticulacion("SERVO", "Servolarge",  9);
  this->addSensor("ULTRASONIC", "ULTRASONIC1", 3, 2);
  this->addSensor("PIR", "PIR1", 4);

}
void RobotIndustrialespcifico::rutinadeMovimientos() {
  this->addMovimiento("Motion1", "ServoSmall", 10, 170);
  this->addMovimiento("Motion2", "Servolarge", 10, 90);
  this->addMovimientoatras("Motion3", "Servolarge", 90, 170);
}

boolean RobotIndustrialespcifico::condicionSensores(){
  return (this->readdatafromsensor("PIR1")==0);
  }


void RobotIndustrialespcifico::addactivity(String activity_tag ,  void (*f)() ){
  if( activity_num < MAX_ACTIVITIES){
    activities[activity_num] = f;
    activities_tags[activity_num] = activity_tag;
    activity_num++;
  }
}


void RobotIndustrialespcifico::action(String activity_tag){
 for(int i = 0; i  < activity_num ;i++){
  if(activity_tag.equals(activities_tags[i])){
    (*activities[i])();
  }
 }
}
void RobotIndustrialespcifico::action(){
  for(int i = 0; i  < activity_num ;i++){
    (*activities[i])();
  }
}
