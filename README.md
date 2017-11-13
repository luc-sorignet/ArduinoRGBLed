RGB LED
====

Arduino RGB LED Library 

simplify your rgb led using on your Arduino Board
- support common cathode
- support common anode


INSTALL :
 - unzip the source lib in Arduino Libraries folder ( on mac : ~/Documents/Arduino/libraries/ )
 - import the lib in your .ino project (#include <LedRGB.h>)

 Exemple code:

```cpp
 #include <LedRGB.h>

int redpin = 5;
int greenpin = 6;
int bluepin = 7;

bool isCommonAnode = true;

LedRGB led(redpin, greenpin, bluepin, isCommonAnode);

void setup() {
  // set red color (you can use it in loop)
  led.setColor(255, 0, 0);
}

void loop() {
  // LED FUNCTIONS
  //led.blink(1000);
  //led.on();
  //led.off();
  //led.toggle();
  
led.fade(25);
 
}
```