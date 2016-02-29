#include "mbed.h"
#include "rtos.h"
#include "leds.h"

/*
 * Точка входа в программу
 */
int main()
{
    led.sys = 0;
    
    Thread thread(taskLedRed);

    while (true) {

        led_sys = 1;
        Thread::wait(LED_SYS_BLINK_ON_SEC);

        led_sys = 0;
        Thread::wait(LED_SYS_BLINK_OFF_SEC);

    }
}
