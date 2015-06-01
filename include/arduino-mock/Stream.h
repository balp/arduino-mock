#ifndef STREAM_H
#define STREAM_H

#include <gmock/gmock.h>

class Stream {
  virtual int available() = 0;
  virtual int read() = 0;
  virtual int peek() = 0;
  virtual void flush() = 0;
};

class StreamMock : public Stream {
  public:
    MOCK_METHOD0(available, int ());
    MOCK_METHOD0(read, int ());
    MOCK_METHOD0(peek, int ());
    MOCK_METHOD0(flush, void ());
};

#endif
