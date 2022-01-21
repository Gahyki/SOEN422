avr-gcc -Wall -mmcu=atmega328p -D MM_DefragOn -D MM_DebugOn -DF_CPU=16000000UL -Os -o task6.bin BargraphHAL.c bsl_MM.c hal_MM.c memory_viewer.c 
avr-objcopy -O ihex task6.bin task6.hex
avrdude -c arduino -p m328p -P COM5 -b 57600 -D -U flash:w:task6.hex:i