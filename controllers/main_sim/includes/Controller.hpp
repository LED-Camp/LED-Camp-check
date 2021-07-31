#ifndef __CONTROLLER__
#define __CONTROLLER__

#include <cstdint>
#include <webots/Supervisor.hpp>
#include "drivers/includes/TwinWheelDriver.hpp"

using namespace webots;
class Controller {
private:
    Supervisor* supervisor;
    TwinWheelDriver* twinWheelDriver;
protected:
    Controller();
    ~Controller(void);
public:
    static Controller* _instance;
    static Controller* getInstance();
    bool clockForward();
    void changeDriveMode(Mode mode, int power);
};

#endif
