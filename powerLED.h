/*
 * Power a LED light.
 *
 *TODO: Expand the blink funcion to include a X seconds on and Y seconds off opintion.
 */
 #ifndef powerLED_h
 #define powerLED_h
 
 #include "Arduino.h"

class powerLED{

  public: 
    powerLED( int physicalPin );
    void constBlink( unsigned long timeToBlink );
    void onceBlink( unsigned long timeToBlink );
    void changeLedState();
    void OnLED();
    void OffLED();
	bool lightState();
    unsigned long timeToBlink;
    int physicalPin;
  private:
    unsigned long _timeKeeper;
    unsigned long _currentRunningTime;
	bool _repeatBlink;
};

 #endif
