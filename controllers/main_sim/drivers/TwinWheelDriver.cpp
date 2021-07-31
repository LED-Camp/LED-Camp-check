#include "includes/TwinWheelDriver.hpp"
#include <stdio.h>

using namespace webots;

TwinWheelDriver* TwinWheelDriver::_instance = 0;

TwinWheelDriver* TwinWheelDriver::getInstance(Supervisor* supervisor, std::string motorNameL, std::string motorNameR) {
    if (_instance == 0) {
      _instance = new TwinWheelDriver(supervisor, motorNameL, motorNameR);
    }

    return _instance;
}

TwinWheelDriver::TwinWheelDriver(Supervisor* supervisor, std::string motorNameL, std::string motorNameR) {
  this->motorL = supervisor->getMotor(motorNameL);
  motorL->setPosition(INFINITY);
  this->motorR = supervisor->getMotor(motorNameR);
  motorR->setPosition(INFINITY);
}

void TwinWheelDriver::changeDriveMode(Mode mode, int power) {
    double l = ((double) power * MAX_SPEED / 100.0);
    double r = ((double) power * MAX_SPEED / 100.0);

    if (mode == STOP) {
        motorL->setVelocity(0.0);
        motorR->setVelocity(0.0);
    } else if (mode == FORWARD) {
        motorL->setVelocity(l);
        motorR->setVelocity(r);
    } else if (mode == BACKWARD) {
        motorL->setVelocity(-l);
        motorR->setVelocity(-r);
    } else if (mode == CW) {
        motorL->setVelocity(l);
        motorR->setVelocity(-r);
    } else if (mode == CCW) {
        motorL->setVelocity(-l);
        motorR->setVelocity(r);
    }
}
