#include <avr/io.h>
#include <util/delay.h>
#include "Activity2.h"
#include "Activity3.h"
#include "Activity4.h"
// temp1 contains the temperature value that ADC renders
unsigned volatile temp1;

int activity3()
{
    // using 16-bit timer and counter1
    TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    //64 Prescaler for appropriate resolution
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10); 
    // Setting direction of PB1 hardware pin as output
    DDRB|=(1<<PB1); 
    
    // OCR1A (16-bit register contains the converted value which is held by ADCregister)
    OCR1A=ADCregister;
    
    // conditions for temperature as per the % PWM given
    if (ADCregister>=0 && ADCregister<=200)
    {
        temp1=20;
        activity4(temp1);
    }else if(ADCregister>210 && ADCregister<500)
    {
        temp1=25;
        activity4(temp1);
    }else if(ADCregister>510 && ADCregister<700)
    {
        temp1=29;
        activity4(temp1);
    }else if(ADCregister>710 && ADCregister<1024)
    {
        temp1=33;
        activity4(temp1);
    }
    return 0;
}