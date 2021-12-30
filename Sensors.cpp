#include "Sensors.h"


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
   Agregar metodos para sensores nuevos
*/


/*
   Se agrega sensor de ultrasonido
*/

int Sensor::addUltrasonic(int echo, int trig) {
  Ultrasonic_class.init(echo, trig);
  this->sensor_type = "ULTRASONIC";
}


/*
  Se agrega sensor PIR
*/
int Sensor::addPir( int pin) {
  pir_class.init(pin);
  this->sensor_type = "PIR";
}


int Sensor::addInfrarrojo( int pin) {
  Infrarrojo_class.init(pin);
  this->sensor_type = "Infrarrojo";
}

int Sensor::addGenerico( int pin) {
  Generico_class.init(pin);
  this->sensor_type = "Generico";
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
   Leé los datos de los sensores mediante una asbtracción generalizada
*/



float Sensor::readdata() {
  if (this->sensor_type == "ULTRASONIC") {
    return Ultrasonic_class.dist();
  }
  else if (this->sensor_type == "PIR") {
    return  pir_class.readmotion();
  }

  else if (this->sensor_type == "Infrarrojo") {
  return  Infrarrojo_class.readmotion();
  }

  else if (this->sensor_type == "Generico") {
  return  Generico_class.readmotion();
  }
}
