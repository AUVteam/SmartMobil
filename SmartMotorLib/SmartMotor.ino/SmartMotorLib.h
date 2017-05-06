#ifndef SmartMotorLib_h
#define SmartMotorLib_h
#include "Arduino.h"
class SmartMotorLib
{
  private:
  int _pin1;
  int _pin2;
  public:
  SmartMotorLib(int pin1, int pin2);
  void turn(bool dir);
};
#endif
