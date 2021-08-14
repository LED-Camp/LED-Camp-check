#include "LEDTank.hpp"
#include "includes/Event.hpp"
#include <stdio.h>
#include <unistd.h>

LEDTank::LEDTank(Controller *controller) {
    this->state = _STATE_INITIAL;
    this->controller = controller;
}

void LEDTank::execState() {
    switch(this->state) {
    case STATE_STOP:

        break;
    case STATE_FOWARD:

        break;
    case STATE_BACK:

        break;
    case STATE_RIGHT:

        break;
    case STATE_LEFT:

        break;
    default:
        break;
    }
}

void LEDTank::doTransition(unsigned long event) {
    this->_beforeState = this->state;
    switch(this->state) {
    case _STATE_INITIAL:
        this->state = STATE_STOP;
        // entry
        controller->changeDriveMode(STOP, 77);
        printf("STOP\n");
        break;
    case STATE_STOP:
        if(((event & E_UP) != 0)) {
            this->state = STATE_FOWARD;
            controller->changeDriveMode(FORWARD, 15);
            printf("FORWARD\n");
        } else if(((event & E_LEFT) != 0)) {
            this->state = STATE_LEFT;
            controller->changeDriveMode(CCW, 15);
            printf("LEFT\n");
        } else if(((event & E_DOWN) != 0)) {
            this->state = STATE_BACK;
            controller->changeDriveMode(BACKWARD, 15);
            printf("BACKWARD\n");
        } else if(((event & E_RIGHT) != 0)) {
            this->state = STATE_RIGHT;
            controller->changeDriveMode(CW, 15);
            printf("RIGHT\n");
        }
        break;
    case STATE_FOWARD:
        if(((event & E_DOWN) != 0)) {
            // exit

            // action

            this->state = STATE_STOP;

            // entry
            controller->changeDriveMode(STOP, 77);
            printf("STOP\n");
        } else if(((event & E_RIGHT) != 0)) {
            // exit

            // action

            this->state = STATE_RIGHT;

            // entry
            controller->changeDriveMode(CW, 15);
            printf("RIGHT\n");
        } else if(((event & E_LEFT) != 0)) {
            // exit

            // action

            this->state = STATE_LEFT;

            // entry
            controller->changeDriveMode(CCW, 15);
            printf("LEFT\n");
        }
        break;
    case STATE_BACK:
        if(((event & E_UP) != 0)) {
            // exit

            // action

            this->state = STATE_STOP;

            // entry
            controller->changeDriveMode(STOP, 77);
            printf("STOP\n");
        } else if(((event & E_LEFT) != 0)) {
            // exit

            // action

            this->state = STATE_LEFT;

            // entry
            controller->changeDriveMode(CCW, 15);
            printf("LEFT\n");
        } else if(((event & E_RIGHT) != 0)) {
            // exit

            // action

            this->state = STATE_RIGHT;

            // entry
            controller->changeDriveMode(CW, 15);
            printf("RIGHT\n");
        }
        break;
    case STATE_RIGHT:
        if(((event & E_LEFT) != 0)) {
            // exit

            // action

            this->state = STATE_STOP;

            // entry
            controller->changeDriveMode(STOP, 77);
            printf("STOP\n");
        } else if(((event & E_DOWN) != 0)) {
            // exit

            // action

            this->state = STATE_BACK;

            // entry
            controller->changeDriveMode(BACKWARD, 15);
            printf("BACKWARD\n");
        } else if(((event & E_UP) != 0)) {
            // exit

            // action

            this->state = STATE_FOWARD;

            // entry
            controller->changeDriveMode(FORWARD, 15);
            printf("FORWARD\n");
        }
        break;
    case STATE_LEFT:
        if(((event & E_RIGHT) != 0)) {
            // exit

            // action

            this->state = STATE_STOP;

            // entry
            controller->changeDriveMode(STOP, 77);
            printf("STOP\n");
        } else if(((event & E_UP) != 0)) {
            // exit

            // action

            this->state = STATE_FOWARD;

            // entry
            controller->changeDriveMode(FORWARD, 15);
            printf("FORWARD\n");
        } else if(((event & E_DOWN) != 0)) {
            // exit

            // action

            this->state = STATE_BACK;

            // entry
            controller->changeDriveMode(BACKWARD, 15);
            printf("BACKWARD\n");
        }
        break;
    default:
        break;
    }
}