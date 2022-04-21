#include <avr/io.h>
#include <util/delay.h>
#include "Activity1.h"
#include "Activity2.h"
#include "Activity3.h"
#include "Activity4.h"
#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */
int main()
{
    // Calling the activity1 function which determines the status of LED actuator
    activity1();
    // Calling the activity2 function which converts the analog value into digital value
    activity2();
    // Calling the activity3 function which gives temperature as per the given % pwm
    activity3();
    // Calling the activity4 function which communicates through UART protocol and displays temperature values on serial monitor
    activity4();
    return 0;
}