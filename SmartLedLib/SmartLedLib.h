#ifndef SmartLedLib_h
#define SmartLedLib_h
#include "Arduino.h"
class SmartLedLib
{
  private:
  int _pin;
  bool _state;
  public:
  SmartLedLib(int pin);
  void on();
  void off();
  void changeState();
  void blinkNormal(float timesPerSecond, int times);
  void analogOn(int value);
  void fadeOn(int seconds);
  void fadeOff(int seconds);
  void blinkFade(float timesPerSecond, int times);
  int getState();
};
#endif
