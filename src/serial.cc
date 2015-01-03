// Copyright 2014 http://switchdevice.com

#include "arduino-mock/serial.h"

static SerialMock* gSerialMock = NULL;
SerialMock* serialMockInstance() {
    if(!gSerialMock) {
        gSerialMock = new SerialMock();
    }
    return gSerialMock;
}

void releaseSerialMock() {
    if(gSerialMock) {
        delete gSerialMock;
        gSerialMock = NULL;
    }
}

size_t Serial_::print(const char *s) {
  return gSerialMock->print(s);
}

size_t Serial_::print(char c) {
  return gSerialMock->print(c);
}

size_t Serial_::print(unsigned char c, int base) {
  return gSerialMock->print(c, base);
}

size_t Serial_::print(int num, int base) {
  return gSerialMock->print(num, base);
}

size_t Serial_::print(unsigned int num, int base) {
  return gSerialMock->print(num, base);
}

size_t Serial_::print(long num, int base) {
  return gSerialMock->print(num, base);
}

size_t Serial_::print(unsigned long num, int base) {
  return gSerialMock->print(num, base);
}

size_t Serial_::print(double num, int digits) {
  return gSerialMock->print(num, digits);
}

size_t Serial_::println(const char *s) {
  return gSerialMock->println(s);
}

size_t Serial_::println(char c) {
  return gSerialMock->println(c);
}

size_t Serial_::println(unsigned char c, int base) {
  return gSerialMock->println(c, base);
}

size_t Serial_::println(int num, int base) {
  return gSerialMock->println(num, base);
}

size_t Serial_::println(unsigned int num, int base) {
  return gSerialMock->println(num, base);
}

size_t Serial_::println(long num, int base) {
  return gSerialMock->println(num, base);
}

size_t Serial_::println(unsigned long num, int base) {
  return gSerialMock->println(num, base);
}

size_t Serial_::println(double num, int digits) {
  return gSerialMock->println(num, digits);
}

size_t Serial_::println(void) {
  return gSerialMock->println();
}

uint8_t Serial_::begin(uint16_t port) {
  return gSerialMock->begin(port);
}

void Serial_::flush() {
  return gSerialMock->flush();
}
