#include "RobotIndustrial.h"

#define MAX_ACTIVITIES 4
class RobotIndustrialespcifico : public RobotIndustrial {
  public:
   //up to 4 activities

    String activities_tags[MAX_ACTIVITIES];
    int activity_num = 0;
    ~RobotIndustrialespcifico(){};
    void armarRobot();
    void rutinadeMovimientos();
    boolean condicionSensores(); 
    void addactivity(String ,  void (*f)() );
    void action(String);
     void action();

};
