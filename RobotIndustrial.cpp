#include "RobotIndustrial.h"

// Aquí se añade el objeto de la articulación con servo
void RobotIndustrial::addArticulacion(String Motor_type, String Motor_tag_, int pin)
{
  if (flag_assembled == false) {
    if (curr_art < MAX_Articulacion )
    {
      if (Motor_type == "SERVO") {
        arts[curr_art].initServo(Motor_tag_, pin);
        Articulacion_tag[curr_art] = Motor_tag_;
        curr_art++;
      }
    }
  }
}

// Aquí añade el objeto  articulación con un motor DC 

void RobotIndustrial::addArticulacion(String Motor_type, String Motor_tag_, int pin1, int pin2)
{


}

// Sensoresrs con un pin
void RobotIndustrial::addSensor(String Sensor_type, String Sensor_tag, int pin) {
  if (flag_assembled == false) {
    if (Sensor_type == "PIR") {
      if (curr_sensor < MAX_SENSORS) {
        sensors[curr_sensor].addPir( pin);
        sensors_tag[curr_sensor] = Sensor_tag;
        curr_sensor++;
      }
    }
  else if (Sensor_type == "Infrarrojo") {
  if (curr_sensor < MAX_SENSORS) {
  sensors[curr_sensor].addInfrarrojo( pin);
  sensors_tag[curr_sensor] = Sensor_tag;
  curr_sensor++;
  }
  }
    else if (Sensor_type == "Generico") {
  if (curr_sensor < MAX_SENSORS) {
  sensors[curr_sensor].addGenerico( pin);
  sensors_tag[curr_sensor] = Sensor_tag;
  curr_sensor++;
  }
  }
  }
}
// Sensors con dos pins
void RobotIndustrial::addSensor(String Sensor_type, String Sensor_tag, int pin1, int pin2)
{
  if (flag_assembled == false) {
    if (Sensor_type == "ULTRASONIC") {
      if (curr_sensor < MAX_SENSORS) {
        sensors[curr_sensor].addUltrasonic( pin1, pin2);
        sensors_tag[curr_sensor] = Sensor_tag;
        curr_sensor++;
      }
    }
  }
}
// leé los datos del sensor
int RobotIndustrial::readdatafromsensor( String sensor_tag) {
  for (int i = 0 ; i < curr_sensor ; i++) {
    if (sensor_tag.equals(sensors_tag[i])) {
      return sensors[i].readdata();
    }
  }
}

void RobotIndustrial::addMovimiento(String motion_tag, String motor_tag, int posF, int posI)
{
  if (flag_assembled == false) {
    if (curr_move < Max_Movements )
    {
      for (int i = 0 ; i < MAX_Articulacion ; i++) {
        if ( Articulacion_tag[i].equals( motor_tag)) {
          movimientos[curr_move].addMovimiento(arts[i], posF, posI);
           movimientos_tag[curr_move] = motion_tag;
          curr_move++;
        }
      }
    }
  }
}

void RobotIndustrial::addMovimientoatras(String motion_tag, String motor_tag, int posF, int posI)
{
  if (flag_assembled == false) {
    if (curr_move < Max_Movements )
    {
      for (int i = 0 ; i < MAX_Articulacion ; i++) {
        if ( Articulacion_tag[i].equals( motor_tag)) {
          movimientos[curr_move].addMovimiento(arts[i], posI, posF);
          movimientos_tag[curr_move] = motion_tag;
          curr_move++;
        }
      }
    }
  }
}
void RobotIndustrial::robotassembly() {
  flag_assembled = true;
}

// sentencia para decirle al robot que se mueva (actuators movement)
/*void RobotIndustrial::action()
{

  if (flag_assembled == true) {
    for (int i = 0; i < curr_move; i++)
    {
      movimientos[i].execute();
    }
  } else {
    Serial.println("You didin't indicate robot assembled");
  }
}
*/
// Run specific instant movements 
void RobotIndustrial::executemove(String tag_move)
{

  if (flag_assembled == true) {
    for (int i = 0; i < curr_move; i++)
    {
      if(tag_move.equals(movimientos_tag[i])){
      movimientos[i].execute();
      break;
      }
    }
  } else {
    Serial.println("You didin't indicate robot assembled");
  }
}
