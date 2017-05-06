#include "Arduino.h"
#include "NwtLedLib.h"

NwtLedLib::NwtLedLib(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _state = false;
}

void NwtLedLib::on()
{
  digitalWrite(_pin, HIGH);
  _state = true;
}

void NwtLedLib::off()
{
  digitalWrite(_pin, LOW);
  _state = false;
}

void NwtLedLib::changeState()
{
  _state = !_state;
  if(_state){
    on();
  }else{
    off();
  }
}

void NwtLedLib::blinkNormal(float timesPerSecond, int times)
{
  int period = 500 / timesPerSecond;
  for(int i = 0; i < (2 * times); i++){
    changeState();
    delay(period);
  }
  off();
}

void NwtLedLib::analogOn(int value)
{
  analogWrite(_pin, value);
}

void NwtLedLib::fadeOn(int seconds)
{
  int waitTime = seconds / 1024;
  for(int i = 0; i <= 1023; i++){
    analogOn(i);
    delay(waitTime);
  }
}

void NwtLedLib::fadeOff(int seconds)
{
  int waitTime = seconds / 1024;
  for(int i = 1023; i >= 0; i--){
    analogOn(i);
    delay(waitTime);
  }
}

void NwtLedLib::blinkFade(float timesPerSecond, int times)
{
  int period = 500 / timesPerSecond;
  for(int i = 0; i < (1 * times); i++){
    fadeOn(period);
    fadeOff(period);
  }
  off();
}

int NwtLedLib::getState()
{
  return _state;
}

