/**
 * Arduino mock header
 */
#ifndef ARDUINO_H
#define ARDUINO_H

#include <stdint.h>

#include "Serial.h"

#ifdef __cplusplus
extern "C" {
#endif

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

#define NOT_AN_INTERRUPT -1
#define digitalPinToInterrupt(p)  ((p) == 2 ? 0 : ((p) == 3 ? 1 : NOT_AN_INTERRUPT))

#define A0
#define A1
#define A2
#define A3
#define A4
#define A5
#define A6
#define A7

typedef uint8_t boolean;
typedef uint8_t byte;

void init(void);

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
int analogRead(uint8_t);
void analogReference(uint8_t mode);
void analogWrite(uint8_t, int);

time_t millis(void);
time_t micros(void);
void delay(time_t);
void delayMicroseconds(time_t us);
time_t pulseIn(uint8_t pin, uint8_t state, time_t timeout);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

void attachInterrupt(uint8_t, void (*)(void), int mode);
void detachInterrupt(uint8_t);

void interrupts(void);
void noInterrupts(void);

void setup(void);
void loop(void);

#ifdef __cplusplus
} // extern "C"
#endif

#include <gmock/gmock.h>

#define UNUSED(expr) do { (void)(expr); } while (0)
#define F(x) (x)

class ArduinoMock {
  private:
    time_t currentMillis;

  public:
    ArduinoMock();

    time_t getMillis() {
      return currentMillis;
    };

    void setMillisRaw (time_t milliseconds) {
      currentMillis = (milliseconds & UINT32_MAX);
    };
    void setMillisSecs(time_t seconds) {
      setMillisRaw(seconds *      1000);
    };
    void setMillisMins(time_t minutes) {
      setMillisRaw(minutes *   60 * 1000);
    };
    void setMillisHrs (float         hours)   {
      setMillisRaw(hours  * 60 * 60 * 1000);
    };

    void addMillisRaw (time_t milliseconds) {
      currentMillis += milliseconds;
      currentMillis &= UINT32_MAX;
    };
    void addMillisSecs(time_t seconds) {
      addMillisRaw(seconds *      1000);
    };
    void addMillisMins(time_t minutes) {
      addMillisRaw(minutes *   60 * 1000);
    };
    void addMillisHrs (float         hours)   {
      addMillisRaw(hours  * 60 * 60 * 1000);
    };

    MOCK_METHOD2(pinMode, void (uint8_t, uint8_t));
    MOCK_METHOD2(analogWrite, void (uint8_t, int));
    MOCK_METHOD2(digitalWrite, void (uint8_t, uint8_t));
    MOCK_METHOD1(digitalRead, int (int));
    MOCK_METHOD1(analogRead, int (int));
    MOCK_METHOD1(delay, void (int));
    MOCK_METHOD0(millis, time_t ());
};
ArduinoMock* arduinoMockInstance();
void releaseArduinoMock();

#endif // ARDUINO_H
