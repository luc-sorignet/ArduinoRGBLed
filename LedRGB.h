//
//  LedRGB.hpp
//  LED
//
//  Created by luc on 13/11/2017.
//  Copyright © 2017 luc sorignet. All rights reserved.
//

#ifndef LedRGB_h
#define LedRGB_h

#include <stdio.h>

/**
 * led RGB Class
 **/
class LedRGB
{
    
public:
    /**
     * Constructor
     **/
    LedRGB(int pinRed, int pinGreen, int pinBlue, bool isCommonAnode=false);
    
    /**
     * setting RGB LED color
     * @param red red value (0 to 255)
     * @param green green value (0 to 255)
     * @param blue blue value (0 to 255)
     **/
    void setColor(int red, int green, int blue);
    
    /**
     * toggle the RGB LED
     * set the RGB LED on or off
     * depending of last state
     */
    void toggle();
   
    /**
     * set the RGB LED on
     */
    void on();
   
    /**
     * set the RGB LED off
     */
    void off();
   
    /**
     * blink the RGB LED
     */
    void blink (int ms);
    
    /**
     * fading color of RGB LED
     */
    void fade(int ms);
    
private:
    
    // LED arduino PIN
    int _pinRed;
    int _pinGreen;
    int _pinBlue;
    
    // LED RGB color value
    int _red;
    int _green;
    int _blue;
    
    // LED params if is common anode
    bool _isCommonAnode;
    
    // LED State (on or off)
    bool _isOn;
    
    
};

#endif /* LedRGB_h */
