/**
 * Arduino SoftwareSerial mock
 */
#ifndef SOFTWARE_SERIAL_H
#define SOFTWARE_SERIAL_H

#include <gmock/gmock.h>

#include "Serial.h"

class SoftwareSerial : public Serial_ {

  public:
    SoftwareSerial( uint8_t receivePin, uint8_t transmitPin, bool inverse_logic = false ){}
    virtual ~SoftwareSerial(){}

    //Arduino's SoftwareSerial methods not present in HardwareSerial
    virtual bool listen(){ return true; }
    virtual bool isListening(){ return true; }
    virtual bool stopListening(){ return true; }
    virtual bool overflow(){ return true; }

    //WiTraC extensions for SoftwareSerial
    virtual void restore_listener(){}
    virtual uint8_t operator [] (const uint8_t index)/*const*/ { return 0; }

  protected:
    SoftwareSerial(){}

};

class SoftwareSerialMock : public SoftwareSerial {
  public:

    //HardwareSerial methods (copied from SerialMock)
    MOCK_METHOD1(write, size_t(uint8_t));
    MOCK_METHOD1(write, size_t(const char *str));
    MOCK_METHOD2(write, size_t(const uint8_t *buffer, size_t size));
    MOCK_METHOD1(print, size_t(const char[]));
    MOCK_METHOD1(print, size_t(char));
    MOCK_METHOD2(print, size_t(unsigned char, int));
    MOCK_METHOD2(print, size_t(int, int));
    MOCK_METHOD2(print, size_t(unsigned int, int));
    MOCK_METHOD2(print, size_t(long, int));
    MOCK_METHOD2(print, size_t(unsigned long, int));
    MOCK_METHOD2(print, size_t(double, int));
    MOCK_METHOD1(println, size_t(const char[]));
    MOCK_METHOD1(println, size_t(char));
    MOCK_METHOD2(println, size_t(int, int));
    MOCK_METHOD0(println, size_t(void));
    MOCK_METHOD1(begin, uint8_t(uint32_t));
    MOCK_METHOD0(available, uint8_t());
    MOCK_METHOD0(read, uint8_t());
    MOCK_METHOD0(flush, void());

    //SoftwareSerial methods
    MOCK_METHOD0(listen, bool());
    MOCK_METHOD0(isListening, bool());
    MOCK_METHOD0(stopListening, bool());
    MOCK_METHOD0(overflow, bool());
    MOCK_METHOD0(restore_listener, void());
    MOCK_METHOD1(at, uint8_t(const uint8_t index));
    uint8_t operator [] (const uint8_t index) override { return at(index); }
};

#endif // SOFTWARE_SERIAL_H
