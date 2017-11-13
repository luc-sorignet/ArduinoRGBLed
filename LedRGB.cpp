//
//  LedRGB.cpp
//  LED
//
//  Created by luc on 13/11/2017.
//  Copyright © 2017 luc sorignet. All rights reserved.
//

#include "LedRGB.h"
#include <Arduino.h>


LedRGB::LedRGB(int pinRed, int pinGreen, int pinBlue, bool isCommonAnode):
_pinRed(pinRed),
_pinGreen(pinGreen),
_pinBlue(pinBlue),
_red(0),
_green(0),
_blue(0),
_isCommonAnode(isCommonAnode),
_isOn(false)
{
    pinMode(_pinRed, OUTPUT);
    pinMode(_pinGreen, OUTPUT);
    pinMode(_pinBlue, OUTPUT);
}

void LedRGB::setColor(int red, int green, int blue)
{
    if(_isCommonAnode)
    {
        _red = 255 - red;
        _green = 255 - green;
        _blue = 255 - blue;
    }
    else
    {
        _red = red;
        _green = green;
        _blue = blue;
    }
    analogWrite(_pinRed, _red);
    analogWrite(_pinGreen, _green);
    analogWrite(_pinBlue, _blue);
}
void LedRGB::toggle()
{
    _isOn = !_isOn;
    if(_isOn)
    {
        analogWrite(_pinRed, _red);
        analogWrite(_pinGreen, _green);
        analogWrite(_pinBlue, _blue);
    }
    else
    {
        if(_isCommonAnode)
        {
            analogWrite(_pinRed, 255);
            analogWrite(_pinGreen, 255);
            analogWrite(_pinBlue, 255);
        }
        else
        {
            analogWrite(_pinRed, 0);
            analogWrite(_pinGreen, 0);
            analogWrite(_pinBlue, 0);
        }
       
    }
   
}
void LedRGB::on()
{
    _isOn = true;
    analogWrite(_pinRed, _red);
    analogWrite(_pinGreen, _green);
    analogWrite(_pinBlue, _blue);
    
}
void LedRGB::off()
{
    _isOn = false;
    if(_isCommonAnode)
    {
        analogWrite(_pinRed, 255);
        analogWrite(_pinGreen, 255);
        analogWrite(_pinBlue, 255);
    }
    else
    {
        analogWrite(_pinRed, 0);
        analogWrite(_pinGreen, 0);
        analogWrite(_pinBlue, 0);
    }
}
void LedRGB::blink (int ms)
{
    delay(ms);
    on();
    delay(ms);
    off();
}
void LedRGB::fade(int ms)
{
    unsigned int rgbColour[3];
    
    // Start off with red.
    rgbColour[0] = 255;
    rgbColour[1] = 0;
    rgbColour[2] = 0;
    
    // Choose the colours to increment and decrement.
    for (int decColour = 0; decColour < 3; decColour += 1)
    {
        int incColour = decColour == 2 ? 0 : decColour + 1;
        // cross-fade the two colours.
        for(int i = 0; i < 255; i += 1)
        {
            rgbColour[decColour] -= 1;
            rgbColour[incColour] += 1;
            
            setColor(rgbColour[0], rgbColour[1], rgbColour[2]);
            delay(ms);
        }
    }
}

