//
// Created by Anders Arnholm on 2020-04-21.
//

#ifndef ARDUINO_MOCK_INCLUDE_CLIENT_H_
#define ARDUINO_MOCK_INCLUDE_CLIENT_H_

#include "Stream.h"
#include "IPAddress.h"
#include <gmock/gmock.h>

class Client : public Stream {

 public:
  virtual int connect(IPAddress ip, uint16_t port) =0;
  virtual int connect(const char *host, uint16_t port) =0;
  virtual size_t write(uint8_t) =0;
  virtual size_t write(const uint8_t *buf, size_t size) =0;
  virtual int available() = 0;
  virtual int read() = 0;
  virtual int read(uint8_t *buf, size_t size) = 0;
  virtual int peek() = 0;
  virtual void flush() = 0;
  virtual void stop() = 0;
  virtual uint8_t connected() = 0;
  virtual operator bool() = 0;
 protected:
  uint8_t* rawIPAddress(IPAddress& addr) { return addr.raw_address(); };
};

class ClientMock : public Client {
 public:
  MOCK_METHOD2(connect, int (IPAddress ip, uint16_t port));
  MOCK_METHOD2(connect, int (const char *host, uint16_t port));
  MOCK_METHOD1(write, size_t (uint8_t c));
  MOCK_METHOD2(write, size_t (const uint8_t *buf, size_t size));
  MOCK_METHOD0(available, int ());
  MOCK_METHOD0(read, int ());
  MOCK_METHOD2(read, int (uint8_t *buf, size_t size));
  MOCK_METHOD0(peek, int ());
  MOCK_METHOD0(flush, void ());
  MOCK_METHOD0(stop, void ());
  MOCK_METHOD0(connected, uint8_t ());
  MOCK_METHOD0(boolOp, bool ());
  operator bool() override { return boolOp(); }


};


#endif //ARDUINO_MOCK_INCLUDE_CLIENT_H_
