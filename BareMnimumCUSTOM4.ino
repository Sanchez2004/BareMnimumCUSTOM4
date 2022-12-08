#include <powerLED.h>

int pinLED1 = 3;//The physical pin conneting to the LED.
int pinButton1 = 2;//Button pin. NOTE: only pin2 and 3 can have attachInterrupt function!
volatile byte buttonState = false;

powerLED led1(pinLED1);

//This is the "ISR". Needs to be fast and light.
void blink() {
  buttonState = true;
}

void setup() {
  
  Serial.begin(9600);
  
  pinMode(pinLED1, OUTPUT);
  pinMode(pinButton1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinButton1), blink, RISING);
}

void loop() {
  if( buttonState == true ){
    led1.onceBlink(1600);
    if( led1.lightState() == LOW ){
      buttonState = false;
    }
  };
    
}
