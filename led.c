#include <avr/io.h>

#define F_CPU 16000000
#define BLINK_DELAY_MS 500

#include <util/delay.h>

#define _EEMEM  __attribute__((__used__, __section__ (".eeprom")))
#define _EEPROM uint8_t __eeprom[32] _EEMEM
_EEPROM = { "Hello World!" };

FUSES = { 0xF7, 0xD6, 0xFD }; // lfuse, hfuse, efuse

const uint8_t one[] __attribute__((__progmem__)) = {
  'B', 'o', 'n', 'j', 'o', 'u', 'r', ' ', 'l', 'e', ' ', 'm', 'o', 'n', 'd', 'e', '\n', 0 };

const uint8_t two[] __attribute__ ((__section__((".progmemx.data")))) = {
   'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '\n', 0 };

int main (void)
{
  // Arduino digital pin 13 (pin 5 of PORTB) for output
  DDRB |= 0B100000; // PORTB5

  while(1) {
    // turn LED on
    PORTB |= 0B100000; // PORTB5
    _delay_ms(BLINK_DELAY_MS);

    // turn LED off
    PORTB &= ~ 0B100000; // PORTB5
    _delay_ms(BLINK_DELAY_MS);
  }
}
