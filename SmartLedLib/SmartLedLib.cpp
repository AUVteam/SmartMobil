#include "Arduino.h"
#include "SmartLedLib.h"

SmartLedLib::SmartLedLib(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _state = false;
}

void SmartLedLib::on()
{
  digitalWrite(_pin, HIGH);
  _state = true;
}

void SmartLedLib::off()
{
  digitalWrite(_pin, LOW);
  _state = false;
}

void SmartLedLib::changeState()
{
  _state = !_state;
  if(_state){
    on();
  }else{
    off();
  }
}

void SmartLedLib::blinkNormal(float timesPerSecond, int times)
{
  int period = 500 / timesPerSecond;
  for(int i = 0; i < (2 * times); i++){
    changeState();
    delay(period);
  }
  off();
}

void SmartLedLib::analogOn(int value)
{
  analogWrite(_pin, value);
}

void SmartLedLib::fadeOn(int seconds)
{
  int waitTime = seconds / 1024;
  for(int i = 0; i <= 1023; i++){
    analogOn(i);
    delay(waitTime);
  }
}

void SmartLedLib::fadeOff(int seconds)
{
  int waitTime = seconds / 1024;
  for(int i = 1023; i >= 0; i--){
    analogOn(i);
    delay(waitTime);
  }
}

void SmartLedLib::blinkFade(float timesPerSecond, int times)
{
  int period = 500 / timesPerSecond;
  for(int i = 0; i < (1 * times); i++){
    fadeOn(period);
    fadeOff(period);
  }
  off();
}

int SmartLedLib::getState()
{
  return _state;
}

