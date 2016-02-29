#include "mbed.h"
#include "rtos.h"
#include "leds.h"
 
LED led;

void taskLedRed(void const *args)
{
    //init red led
    led.red = 0.0f;
    
    //infinite loop
    while(true) {      
        
        //increases the brightness
        for( ; led.red < 1.000f; ){
            led.red += LED_RED_SWITCH_STEP;
            //delay
            Thread::wait(LED_RED_SWITCH_PERIOD);
        }
        
        //decreases the brightness
        for( ; led.red > 0.000f; ){
            led.red -= LED_RED_SWITCH_STEP;
            //delay
            Thread::wait(LED_RED_SWITCH_PERIOD);
        }
        
        //delay  
        Thread::wait(LED_RED_TIMEOUT);
        
    } //while
    
} //taskLedRed