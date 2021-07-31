#include "includes/Controller.hpp"
#include <webots/Supervisor.hpp>

#define TIME_STEP 20

using namespace webots;

Controller* Controller::_instance = 0;

Controller* Controller::getInstance() {
    if (_instance == 0) {
        _instance = new Controller();
    }

    return _instance;
}

Controller::Controller() {
    this->supervisor = new Supervisor();
    twinWheelDriver = TwinWheelDriver::getInstance(supervisor, "motorL", "motorR");
}

Controller::~Controller(void) {
}

void Controller::changeDriveMode(Mode mode, int power) {
    this->twinWheelDriver->changeDriveMode(mode, power);
}

bool Controller::clockForward() {
    return this->supervisor->step(TIME_STEP) != -1;
}
