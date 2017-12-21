/**
 * AVR defines needed for compilation
 */
#ifndef AVR_DEFINES_H
#define AVR_DEFINES_H

/* From avr/pgmspace.h */
#define PROGMEM
#define pgm_read_dword_near *

/* From avr/wdt.h.h */
#define wdt_reset()

#endif // AVR_DEFINES_H
