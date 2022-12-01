CFLAGS ?= -Os -DF_APU=16000000UL -mmcu=atmega328p
LDFLAGS ?= -mmcu=atmega328p
# Path where your Arduino Uno is connected to
ARDUINO_USB ?= /dev/ttyUSB0

all: led.hex

led.hex: led.elf
	avr-objcopy -O ihex -R .eeprom -R .fuse led.elf led.hex

led.elf: led.o
	avr-gcc $(LDFLAGS) -o $@ $^

led.o: led.c
	avr-gcc $(CFLAGS) -c -o $@ $<

deploy: led.hex
	avrdude -F -V -c arduino -p ATMEGA328p -P ${ARDUINO_USB} -b 115200 -U flash:w:led.hex  

clean: FRC
	rm -f led.elf led.hex led.o led

FRC:
