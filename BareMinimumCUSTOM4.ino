
/*
*
* !This is the old code! Please see new code.
*
*/

//Vars for timing leds, regurdless of the number of leds.
unsigned long signalShort = 200;
unsigned long signalLong = 500;
unsigned long shortDelay = 200;
unsigned long longDelay = 1000;
unsigned long currentRunningTime;

//vars for button
const int buttonPin = 7;
int lastState = HIGH;
int currentState;

//class TODO document
class powerLED{

  public: 
    powerLED( int physicalPin, unsigned long timeKeeper );
    int physicalPin;
    bool isPowered;
    unsigned long powerOffTime;
    unsigned long powerOnTime;
    unsigned long timeKeeper;
    void blinkLED( unsigned long powerOffTime, unsigned long powerOnTime );
};

powerLED::powerLED( int physicalPin, unsigned long timeKeeper ){
      this->physicalPin = physicalPin;
      //this->powerOffTime = powerOffTime;
      //this->powerOnTime = powerOnTime;
      isPowered = false;
      this->timeKeeper = timeKeeper;
}

void powerLED::blinkLED(unsigned long powerOffTime, unsigned long powerOnTime){

  if( isPowered == true && timeKeeper <= currentRunningTime ){
    digitalWrite(physicalPin, LOW);
    isPowered = false;
    timeKeeper = currentRunningTime + powerOffTime;
  };
  
  if( isPowered == false && timeKeeper <= currentRunningTime ){

    if(lastState == LOW && currentState == HIGH){
      digitalWrite(physicalPin, HIGH);
      isPowered = true;
      timeKeeper = currentRunningTime + powerOnTime;
    }
  };
}

//Vars for each LED conneted.
unsigned long timeMark1;
int pinToPower1 = 8;
powerLED ledOne = powerLED(pinToPower1, timeMark1);

//TODO document
void setup() {

  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  
  timeMark1 = millis();
  pinMode(pinToPower1, OUTPUT);
}

void loop() {

  currentState = digitalRead(buttonPin);
  currentRunningTime = millis();
  ledOne.blinkLED(longDelay, longDelay);
  lastState = currentState;
}
