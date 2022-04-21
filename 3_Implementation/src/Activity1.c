#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief defining status of switch_1 is defined by considering the status of input hardware pin
 * @brief defining status of switch_2 is defined by considering the status of input hardware pin
 */

#define switch_1 !(PIND & (1 << PD2))
#define switch_2 !(PIND & (1 << PD3))

void pin_config()
{
    // Direction of ports
    DDRB |= (1 << PB0);
    DDRD &= ~(1 << PD2);
    DDRD &= ~(1 << PD3);

    // PULL-UP +5V for push-buttons
    PORTD |= (1 << PD2);
    PORTD |= (1 << PD3);
}

int activity1(void)
{
    // call function that configures the registers
    pin_config();
    while (1)
    {
        // condition will turn to be true only when both switches are closed
        if ((switch_1) && (switch_2))
        {
            // LED set to ON if true
            PORTB |= (1 << PB0);
            _delay_ms(200);
            activity2();
            activity3();
        }
        else
        {
            // LED set to OFF if false.
            PORTB &= ~(1 << PB0);
            _delay_ms(200);
        }
    }

    return 0;
}