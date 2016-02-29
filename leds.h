#include "mbed.h"

#ifndef LEDS_H
#define LEDS_H

#define LED_SYS_BLINK_OFF_SEC   1000        //Время нахождения системного светодиода в выключенном состоянии
#define LED_SYS_BLINK_ON_SEC    50          //Время нахождения системного светодиода во включенном состоянии

#define LED_RED_SWITCH_PERIOD   10          //Период изменения яркости красного светодиода
#define LED_RED_SWITCH_STEP     0.001f       
#define LED_RED_TIMEOUT         1000        //Периодичность активации светодиода


/*
 *Here defined all leds
 */
class LED
{
    
    public:
    
        DigitalOut  sys     ( PA_5 );
        PwmOut      red     ( PA_0 );
        
};


#endif