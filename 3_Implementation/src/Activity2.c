#include <avr/io.h>
#include <util/delay.h>
#include "Activity2.h"

void InitADC()
{
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
}

uint16_t ReadADC(uint8_t ch)
{
    //Selection of ADC channel ch=[0-7]
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    //Start Single Conversion
    ADCSRA|=(1<<ADSC);
    //Wait for conversion to complete
    while(!(ADCSRA & (1<<ADIF)));
    //clearing ADIF
    ADCSRA|=(1<<ADIF);
    return(ADC);
}
int activity2(void)
{
    InitADC();
    ReadADC(0);
    _delay_ms(200);
    return 0;
}