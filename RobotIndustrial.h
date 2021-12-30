#include "Sensors.h"
#include "Movimiento.h"

#define Max_Movements 10
#define MAX_Articulacion 10
#define MAX_SENSORS 10

class RobotIndustrial
{
  protected:
    Articulacion arts[MAX_Articulacion];/*[MAX_Articulacion]*/;
    Sensor sensors[MAX_SENSORS];
    Movimiento movimientos[Max_Movements] ;
    unsigned int curr_art = 0;
    unsigned int curr_move = 0;
    unsigned int curr_sensor = 0;
    String sensors_tag[MAX_SENSORS];
    String Articulacion_tag[MAX_Articulacion];
    String movimientos_tag[Max_Movements];
    bool flag_assembled = false;
  public:
    RobotIndustrial() = default;

    // //Aquí se añade el objeto de articulación con un tipo de motor (servo o motor) con un pin
    void addArticulacion(String Motor_type, String Motor_tag_, int pin);
    // Aquí se añade el objeto de articulación con un tipo de motor (servo o motor) con dos pin
    void addArticulacion(String Motor_type, String Motor_tag_, int pin1, int pin2);

    // Sensores con un pin
    void addSensor(String Sensor_type, String Sensor_tag, int pin);

    // Sensores con dos pins
    void addSensor(String Sensor_type, String Sensor_tag, int pin1, int pin2);
    // Leé los datos del sensor
    int readdatafromsensor( String sensor_tag);
    
    void addMovimiento(String motion_tag, String motor_tag, int posF, int posI);

    void addMovimientoatras(String motion_tag, String motor_tag, int posF, int posI);
    
    //dirá que el robot se ha completado y es capaz de ejecutar a través de Robot.action();
    void robotassembly();

   // void action();

    void executemove(String);
    
    ~RobotIndustrial(){};
    
    virtual void armarRobot(){};

    virtual void rutinadeMovimientos(){};

    virtual boolean condicionSensores(){};


};
 
