#ifndef __LEDTank__
#define __LEDTank__

#include "includes/Controller.hpp"

#define _STATE_INITIAL 0x00000000
#define STATE_STOP ((unsigned long)1)
#define STATE_FOWARD ((unsigned long)2)
#define STATE_BACK ((unsigned long)3)
#define STATE_RIGHT ((unsigned long)4)
#define STATE_LEFT ((unsigned long)5)

class LEDTank{
 public:
  LEDTank(Controller *controller);
  void execState();
  void doTransition(unsigned long event);
  unsigned long _state;

 private:
   Controller *controller;
   unsigned long _beforeState;
   unsigned long state;

};

#endif