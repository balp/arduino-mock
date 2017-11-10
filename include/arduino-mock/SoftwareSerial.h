/**
 * Arduino SoftwareSerial mock
 */
#ifndef SOFTWARE_SERIAL_H
#define SOFTWARE_SERIAL_H

#include <gmock/gmock.h>

#include "Serial.h"

class SoftwareSerial : public Serial_ {

  public:
    SoftwareSerial( uint8_t receivePin, uint8_t transmitPin, bool inverse_logic = false ){};
    ~SoftwareSerial(){}

    virtual bool listen(){}
    virtual void restore_listener(){}

    virtual size_t write( uint8_t byte ){}

    //TODO: Add [] operator
    //virtual uint8_t operator[]( const uint8_t pos_0 )const;

    //Methods from Stream class
    virtual bool find(char *target){}

};

class SoftwareSerialMock : public SerialMock, public SoftwareSerial {
  public:
    SoftwareSerialMock(uint8_t receivePin, uint8_t transmitPin, bool inverse_logic = false) :
        SoftwareSerial(receivePin, transmitPin, inverse_logic) {};
    MOCK_METHOD0(listen, bool());
    MOCK_METHOD0(restore_listener, void());
    MOCK_METHOD1(write, size_t(uint8_t byte));
    MOCK_METHOD1(find, bool(char* target));
};

#endif // SOFTWARE_SERIAL_H
