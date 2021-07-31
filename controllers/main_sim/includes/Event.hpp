#ifndef __EVENT_H__
#define __EVENT_H__

#include <cstdint>
#include <webots/Keyboard.hpp> //キー受け付け
#include <string>

class Controller;
using namespace webots;

#define E_UP ((unsigned long)0x00000001)
#define E_DOWN ((unsigned long)0x00000002)
#define E_LEFT ((unsigned long)0x00000004)
#define E_RIGHT ((unsigned long)0x00000008)
#define E_TRUE ((unsigned long)0xFFFFFFFF)
#define E_FALSE ((unsigned long)0x00000000)



class Event {
 public:
    Event(Controller* controller);
    int updateEvent();
    unsigned long getEvent();

private:
    Controller* controller;
    Keyboard keyboard;
    int oldKey;
    unsigned long event;
};

#endif
