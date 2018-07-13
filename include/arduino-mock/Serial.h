/**
 * Arduino Serial mock
 */
#ifndef SERIAL_H
#define SERIAL_H

#include <stdint.h>
#include <gmock/gmock.h>

using ::testing::_;
using ::testing::Invoke;
using ::testing::DoDefault;

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2


/**
  \see #SoftwareSerialFake
*/
class SerialFake {

   public:

    /**
      \brief Load user specified data into SerialFake buffer
      \param buffer User buffer to copy the data from
      \param len Length of the user buffer
    */
    void buffer_load(uint8_t buffer_0[], const uint8_t len);

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

class SerialMock {
  public:
    MOCK_METHOD0(getWriteError, int());
    MOCK_METHOD0(clearWriteError, void());
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

    /* Not implemented yet
    MOCK_METHOD2(println, size_t(unsigned char, int));
    MOCK_METHOD2(println, size_t(unsigned int, int));
    MOCK_METHOD2(println, size_t(long, int));
    MOCK_METHOD2(println, size_t(unsigned long, int));
    MOCK_METHOD2(println, size_t(double, int));
    */

    //Serial methods
    MOCK_METHOD1(at, uint8_t(const uint8_t index));
    uint8_t operator [] (const uint8_t index) { return at(index); }

    /**
      \brief Load user specified buffer into the fake RX buffer
      \param buffer Buffer of any length to copy the data from
      \param len Length of the buffer
      \param ignore_calls Flag to set the mock to expect and ignore all calls on
             methods related to the buffer (available, read and operator [])
    */
    void mock_buffer_load(uint8_t buffer[], const uint8_t len, bool ignore_calls = true) {
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
    void mock_buffer_load(char buffer[], const uint8_t len, bool ignore_calls = true) {
        mock_buffer_load((uint8_t*)buffer, len, ignore_calls);
    }

    /**
      \brief Constructor. Sets default mock actions for available, read and operator [],
             to be redirected to SerialFake
    */
    SerialMock() {
        ON_CALL(*this, available())
            .WillByDefault(Invoke(&fake_, &SerialFake::available));
        ON_CALL(*this, read())
            .WillByDefault(Invoke(&fake_, &SerialFake::read));
        ON_CALL(*this, at(_))
            .WillByDefault(Invoke(&fake_, &SerialFake::at));
    }

   private:
    SerialFake fake_;  // Keeps an instance of the fake in the mock.
};


class Serial_ {

  private:
    static bool printToCout;

  public:
    static void setPrintToCout(bool flag);

  public:
    virtual size_t print(const char[]);
    virtual size_t print(char);
    virtual size_t print(unsigned char, int = DEC);
    virtual size_t print(int, int = DEC);
    virtual size_t print(unsigned int, int = DEC);
    virtual size_t print(long, int = DEC);
    virtual size_t print(unsigned long, int = DEC);
    virtual size_t print(double, int = 2);

    virtual size_t println(const char[]);
    virtual size_t println(char);
    virtual size_t println(unsigned char, int = DEC);
    virtual size_t println(int, int = DEC);
    virtual size_t println(unsigned int, int = DEC);
    virtual size_t println(long, int = DEC);
    virtual size_t println(unsigned long, int = DEC);
    virtual size_t println(double, int = 2);
    virtual size_t println(void);

    virtual size_t write(uint8_t);
    virtual size_t write(const char *str);
    virtual size_t write(const uint8_t *buffer, size_t size);

    virtual uint8_t begin(uint32_t);

    virtual uint8_t available();
    virtual uint8_t read();

    virtual void flush();

    //WiTraC extensions for Serial_
    virtual uint8_t operator [] (const uint8_t index);

    /*
    TODO: Not implemented yet.
    int getWriteError();
    void clearWriteError();
    static size_t print(const __FlashStringHelper *);
    static size_t print(const String &);
    static size_t print(const Printable&);
    static size_t println(const __FlashStringHelper *);
    static size_t println(const String &s);
    static size_t println(const Printable&);
    */
};
extern Serial_ Serial;

SerialMock* serialMockInstance();
void releaseSerialMock();


#endif // SERIAL_H
