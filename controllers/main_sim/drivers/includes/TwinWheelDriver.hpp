#include <webots/Motor.hpp>
#include <webots/Supervisor.hpp>

#ifndef __TWINWHEELDRIVER__
#define __TWINWHEELDRIVER__

using namespace webots;

#define MAX_SPEED 100

typedef enum {
  STOP, FORWARD, BACKWARD, CW, CCW,BRAKE
} Mode;

class TwinWheelDriver {
private:
    static TwinWheelDriver* _instance;
    Motor* motorL;
    Motor* motorR;
protected:
    TwinWheelDriver(Supervisor* supervisor, std::string motorNameL, std::string motorNameR);
public:
    ~TwinWheelDriver();

    static TwinWheelDriver* getInstance(Supervisor* supervisor, std::string motorNameL, std::string motorNameR);
    void changeDriveMode(Mode mode, int power);
};

#endif
