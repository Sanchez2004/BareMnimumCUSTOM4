/*
* Has five functions: 
* -On and off function
* -A func to change led power state
* -A func to check its state (HIGH or LOW)
* -Blink funciton.
* -Blink once func.
*
*It seem redundant ot have on/off and "changeLedState", but I think having clear control of what state the
*LED is in is better than fliping its state in some cases. Had to add two blink funcs to avoid iusses and to just
*get it to work.
*
*TODO: 
* -expand constBlink to inculde a "X seconds on and Y seconds off" function.
* -mirge both blink functions.
* 
*/

 #include "Arduino.h"
 #include "powerLED.h"


powerLED::powerLED( int physicalPin ){
  this->physicalPin = physicalPin;
  _timeKeeper = 0;
}

void powerLED::OnLED(){
  digitalWrite(physicalPin, HIGH);
}

void powerLED::OffLED(){
  digitalWrite(physicalPin, LOW);
}

bool powerLED::lightState(){
  return digitalRead(physicalPin);
}

//Simply flips what state of power the LED is in. HIGH or LOW is treated as bool in this case.
void powerLED::changeLedState(){
   digitalWrite(physicalPin, !digitalRead(physicalPin) );
}

void powerLED::constBlink( unsigned long timeToBlink ){

  _currentRunningTime = millis();
  
  if( _timeKeeper <= _currentRunningTime ){
	_timeKeeper = timeToBlink + _currentRunningTime;
	changeLedState(); 
  }
}

void powerLED::onceBlink( unsigned long timeToBlink ){
	
  _currentRunningTime = millis();
  
  if( digitalRead(physicalPin) == LOW ){
	 _timeKeeper = timeToBlink + _currentRunningTime;
	 OnLED();
  }
  if( _timeKeeper <= _currentRunningTime ){
	 OffLED(); 
  }
}
