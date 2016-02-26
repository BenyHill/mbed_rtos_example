#include "mbed.h"
#include "rtos.h"


#define LED_SYS_BLINK_OFF_SEC   1.0f        //Время нахождения системного светодиода в выключенном состоянии
#define LED_SYS_BLINK_ON_SEC    0.1f        //Время нахождения системного светодиода во включенном состоянии

#define LED_RED_SWITCH_PERIOD   0.2f        //Период изменения яркости красного светодиода


DigitalOut  led_sys  ( PA_5 );
PwmOut      led_red  ( PA_0 );

// bool        led_red_enable;

/**
* задача моргания мигяния красным светодиодом
*/
void taskLedRed(void const *args)
{

    while (true) {

        led_red = 0.0f;
        Thread::wait(LED_RED_SWITCH_PERIOD);

        led_red = 0.25f;
        Thread::wait(LED_RED_SWITCH_PERIOD);

        led_red = 0.5f;
        Thread::wait(LED_RED_SWITCH_PERIOD);

        led_red = 0.75f;
        Thread::wait(LED_RED_SWITCH_PERIOD);

        led_red = 1.0f;
        Thread::wait(LED_RED_SWITCH_PERIOD);

    }
}

/**
* Блок инициализации перед началов выполнения программы
*/
void init()
{

    led_red = 0;
    led_sys = 0;

//      led_red_enable = true;

}


/**
 * Точка входа в программу
 */
int main()
{

    Thread thread(taskLedRed);

    while (true) {

        led_sys = 1;
        Thread::wait(LED_SYS_BLINK_ON_SEC);

        led_sys = 0;
        Thread::wait(LED_SYS_BLINK_OFF_SEC);

    }
}
