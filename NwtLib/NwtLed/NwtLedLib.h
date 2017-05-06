#ifndef NwtLedLib_h
#define NwtLedLib_h
#include "Arduino.h"
class NwtLedLib
{
  private:
  int _pin;
  bool _state;
  public:
  NwtLedLib(int pin);
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
