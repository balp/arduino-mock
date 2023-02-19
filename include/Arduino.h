/**
 * Arduino mock header
 */
#ifndef ARDUINO_H
#define ARDUINO_H

#include <stdint.h>
#include "Serial.h"
#include "Wire.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PROGMEM
#define PGM_P const char *
#define PGM_VOID_P const void *
#define PSTR(s) (s)

#define pgm_read_byte(p) (* (const uint8_t*) (p))
#define pgm_read_word(p) (* (const uint16_t*) (p))
#define pgm_read_dword(p) (* (const uint32_t*) (p))
#define pgm_read_float(p) (* (const float*) (p))
#define pgm_read_ptr(p) (* (const void* const*) (p))

#define pgm_read_byte_near(expr)  pgm_read_byte(expr)
#define pgm_read_word_near(expr)  pgm_read_word(expr)
#define pgm_read_dword_near(expr) pgm_read_dword(expr)
#define pgm_read_float_near(expr) pgm_read_float(expr)
#define pgm_read_ptr_near(expr)   pgm_read_ptr(expr)

#define pgm_read_byte_far(expr)   pgm_read_byte(expr)
#define pgm_read_word_far(expr)   pgm_read_word(expr)
#define pgm_read_dword_far(expr)  pgm_read_dword(expr)
#define pgm_read_float_far(expr)  pgm_read_float(expr)
#define pgm_read_ptr_far(expr)    pgm_read_ptr(expr)

  
#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#ifdef WIN32
#elif linux
#else
#define true 0x1
#define false 0x0
#endif

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

#define NUM_DIGITAL_PINS            20
#define NUM_ANALOG_INPUTS           6
#define analogInputToDigitalPin(p)  ((p < 6) ? (p) + 14 : -1)

#define digitalPinHasPWM(p)         ((p) == 9 || (p) == 10 || (p) == 11)

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

//bit manipulation macros
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
#define bit(b) (1UL << (b))


typedef uint8_t boolean;
typedef uint8_t byte;

void init(void);

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
int analogRead(uint8_t);
void analogReference(uint8_t mode);
void analogWrite(uint8_t, int);

unsigned long millis(void);
unsigned long micros(void);
void delay(unsigned long);
void delayMicroseconds(unsigned int us);
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

void attachInterrupt(uint8_t, void (*)(void), int mode);
void detachInterrupt(uint8_t);

void yield(void);
  
void setup(void);
void loop(void);

#ifdef __cplusplus
} // extern "C"
#endif

#include <gmock/gmock.h>

#define UNUSED(expr) do { (void)(expr); } while (0)
#define F(x) (x)

class ArduinoMock {
  public:
    MOCK_METHOD2(pinMode, void (uint8_t, uint8_t));
    MOCK_METHOD2(analogWrite, void (uint8_t, int));
    MOCK_METHOD2(digitalWrite, void (uint8_t, uint8_t));
    MOCK_METHOD1(digitalRead, int (int));
    MOCK_METHOD1(analogRead, int (int));
    MOCK_METHOD1(delay, void (int));
    MOCK_METHOD0(millis, unsigned long ());
};
ArduinoMock* arduinoMockInstance();
void releaseArduinoMock();

#endif // ARDUINO_H
