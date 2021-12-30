#include <Arduino.h>
#include "complements.h"


// Esta clase define los sensores asociado al robot



class Sensor {
  private:

    // Tipo de sensor
    String sensor_type;



    //Sensor de ultrasonido
    HCSR04  Ultrasonic_class;

    //Objeto Pir
    PIR   pir_class;

    Infrarrojo Infrarrojo_class;

    Generico Generico_class;

  public:
    int addUltrasonic( int echo, int trig);
    int addPir( int pin);
    int addGenerico( int pin);
    int addInfrarrojo( int pin);

    float readdata();

};
