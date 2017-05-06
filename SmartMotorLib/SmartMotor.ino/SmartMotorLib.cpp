#include "Arduino.h"
#include "SmartMotorLib.h"

SmartMotorLib::SmartMotorLib(int pin1, int pin2)
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  _pin1 = pin1;
  _pin2 = pin2;
}

void SmartMotorLib::turn(bool dir)
{
  if(dir){
    digitalWrite(_pin1, HIGH);
    digitalWrite(_pin2, LOW);
  }else{
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, HIGH);
  }
}

