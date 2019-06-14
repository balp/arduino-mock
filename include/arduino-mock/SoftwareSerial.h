/**
 * Arduino SoftwareSerial mock and fake
 *
 * Using Fake+Mock design suggested at GoogleMocks CookBook.
 * ref https://github.com/google/googletest/blob/master/googlemock/docs/CookBook.md#delegating-calls-to-a-fake
 */
#ifndef SOFTWARE_SERIAL_H
#define SOFTWARE_SERIAL_H

#include <gmock/gmock.h>
using ::testing::_;
using ::testing::Invoke;
using ::testing::DoDefault;

#include "Serial.h"

/**
  \class SoftwareSerial
  \brief Interface for serial communications using GPIO pins

  \note In the actual Arduino architecture, SoftwareSerial does not inherit from HardwareSerial but
        from Stream, meaning that SoftwareSerial and HardwareSerial are rather siblings. In the mock
        we define SoftwareSerial as a child of HardwareSerial for the sake of simplicity and to
        avoid conflicts when upmerging from the original project into this fork.
*/
class SoftwareSerial : public Serial_ {

  public:
    SoftwareSerial( uint8_t receivePin, uint8_t transmitPin, bool inverse_logic = false ){};
    ~SoftwareSerial(){};

    //Arduino's SoftwareSerial methods not present in HardwareSerial
    virtual bool listen(){ return true; }
    virtual void end(){}
    virtual bool isListening(){ return true; }
    virtual bool stopListening(){ return true; }
    virtual bool overflow(){ return true; }

    //WiTraC extensions for SoftwareSerial
    virtual void restore_listener(){}

  protected:
    SoftwareSerial(){}

};

/**
  \class SoftwareSerialFake
  \brief Fake implementation of the serial interface, capable of simulating RX

  The class implements an internal buffer, where the user can pre-load the data that the fake will
  serve on subsequent calls to related methods: available, read and operator [].

  Limitations:
  - Buffer size is fixed, see private const buffer_size
  - It is not a ringbuffer: subsequent calls to buffer_load will override contents of the buffer.
*/
class SoftwareSerialFake : public SoftwareSerial {

  public:

    /**
      \brief Load user specified data into SoftwareSerialFake buffer
      \param buffer User buffer to copy the data from
      \param len Length of the user buffer
    */
    void buffer_load(const uint8_t buffer_0[], const uint8_t len);

    /**
      \brief Fake methods to operate with the RX buffer
    */
    uint8_t available();
    uint8_t read();
    uint8_t at(const uint8_t index);

  private:
    static const uint8_t buffer_size = 128;
    uint8_t buffer[buffer_size] = {0};
    uint8_t buffer_head = 0;
    uint8_t buffer_tail = 0;
};

/**
  \class SoftwareSerialMock
  \brief Standard GoogleMock class of SoftwareSerial. It uses a private instance of SoftwareSerialFake
         to mock the behaviour of RX related methods available, read and operator []
*/
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
    MOCK_METHOD0(end, void());

    //SoftwareSerial methods
    MOCK_METHOD0(listen, bool());
    MOCK_METHOD0(isListening, bool());
    MOCK_METHOD0(stopListening, bool());
    MOCK_METHOD0(overflow, bool());
    MOCK_METHOD0(restore_listener, void());
    MOCK_METHOD1(at, uint8_t(const uint8_t index));
    uint8_t operator [] (const uint8_t index) override { return at(index); }

    /**
      \brief Load user specified buffer into the fake RX buffer
      \param buffer Buffer of any length to copy the data from
      \param len Length of the buffer
      \param ignore_calls Flag to set the mock to expect and ignore all calls on
             methods related to the buffer (available, read and operator [])
    */
    void mock_buffer_load(const uint8_t buffer[], const uint8_t len, bool ignore_calls = true) {
        fake_.buffer_load(buffer, len);
        if (ignore_calls) {
            EXPECT_CALL(*this, available())
                .WillRepeatedly(DoDefault());
            EXPECT_CALL(*this, read())
                .WillRepeatedly(DoDefault());
            EXPECT_CALL(*this, at(_))
                .WillRepeatedly(DoDefault());
        }
    }
    void mock_buffer_load(const char buffer[], const uint8_t len, bool ignore_calls = true) {
        mock_buffer_load((const uint8_t*)buffer, len, ignore_calls);
    }

    /**
      \brief Constructor. Sets default mock actions for available, read and operator [],
             to be redirected to SoftwareSerialFake
    */
    SoftwareSerialMock() {
        ON_CALL(*this, available())
            .WillByDefault(Invoke(&fake_, &SoftwareSerialFake::available));
        ON_CALL(*this, read())
            .WillByDefault(Invoke(&fake_, &SoftwareSerialFake::read));
        ON_CALL(*this, at(_))
            .WillByDefault(Invoke(&fake_, &SoftwareSerialFake::at));
    }

  private:
    SoftwareSerialFake fake_;  // Keeps an instance of the fake in the mock.
};

#endif // SOFTWARE_SERIAL_H
