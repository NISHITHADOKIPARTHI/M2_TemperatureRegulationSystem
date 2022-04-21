#include <avr/io.h>
#include <util/delay.h>
#include "Activity4.h"

void USARTInit(uint16_t ubrr_value)
{
    // Set Baud rate
    
    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&0x00ff;
    UCSR0C = (1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);

    /// Enable the Receiver and Transmitter
    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);

}

char USARTReadChar()
{
    // Wait until data is available

    while(!(UCSR0A & (1<<RXC0)))
    {
        //Do nothing
    }

    return UDR0;
}

void USARTWriteChar(char data)
{
    // Wait until the transmitter is ready

    while(!(UCSR0A & (1<<UDRE0)))
    {
        //Do Nothing
    }

    // Not write the data to USART buffer
   _delay_ms(200);
    UDR0 = data;
}


int activity4(uint16_t temp1)
{
    USARTWriteChar(temp1);
    return 0;
}