/**
 * Arduino SoftwareSerial mock
 */
#ifndef SOFTWARE_SERIAL_H
#define SOFTWARE_SERIAL_H

#include <gmock/gmock.h>
using ::testing::_;
using ::testing::Invoke;

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

    /**************************************************************************/
    /*   Standard GoogleMock methods                                          */
    /**************************************************************************/

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


    /**************************************************************************/
    /*   Custom functionality to mock SoftwareSerial RX buffer                */
    /*   -----------------------------------------------------                */
    /*                                                                        */
    /* The mock implements an internal RX buffer, where the user can pre-load */
    /*  the data that the mock will serve on subsequent calls to the buffer   */
    /*  related methods: available, read and operator []                      */
    /*                                                                        */
    /* Usage:                                                                 */
    /*  Call mock_buffer_load to load the data into the RX buffer before the  */
    /*   code under test will make use the related methods. Such methods will */
    /*   then correct behave and return expected values.                      */
    /*                                                                        */
    /* Limitations:                                                           */
    /*  - Buffer size is fixed, see private const buffer_size                 */
    /*  - It is not a ringbuffer: subsequent calls to mock_buffer_load will   */
    /*    override contents of the buffer.                                    */
    /**************************************************************************/

    /**
      \brief Load user specified buffer into SoftwareSerial RX buffer (mock)
      \param buffer Buffer of any length to copy the data from
      \param len Length of the buffer
      \param ignore_calls Flag to set the mock to expect and ignore all calls on
             methods related to the buffer (available, read and operator [])
    */
    void mock_buffer_load(uint8_t buffer[], const uint8_t len, bool ignore_calls = true);
    void mock_buffer_load(char buffer[], const uint8_t len, bool ignore_calls = true);

    /**
      \brief Constructor. Sets default mock actions for available, read and operator []
    */
    SoftwareSerialMock() {
        ON_CALL(*this, available())
            .WillByDefault(Invoke(this, &SoftwareSerialMock::mock_buffer_available));
        ON_CALL(*this, read())
            .WillByDefault(Invoke(this, &SoftwareSerialMock::mock_buffer_read));
        ON_CALL(*this, at(_))
            .WillByDefault(Invoke(this, &SoftwareSerialMock::mock_buffer_at));
    }

    /**
      \brief Overloaded methods for available, read and operator []
    */
    uint8_t mock_buffer_available();
    uint8_t mock_buffer_read();
    uint8_t mock_buffer_at(const uint8_t index);

  private:
    static const uint8_t buffer_size = 128;
    uint8_t buffer[buffer_size] = {0};
    uint8_t buffer_head = 0;
    uint8_t buffer_tail = 0;
};

#endif // SOFTWARE_SERIAL_H
