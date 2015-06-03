// Copyright 2014 http://switchdevice.com
// This example code is in the public domain.

#include "gtest/gtest.h"
#include "Arduino.h"
#include "Stream.h"

using ::testing::_;
using ::testing::Return;
using ::testing::Matcher;
using ::testing::AtLeast;
using ::testing::Invoke;

TEST(stream, available) {
  StreamMock streamMock;
  EXPECT_CALL(streamMock, available())
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, streamMock.available());
}

TEST(stream, read) {
  StreamMock streamMock;
  EXPECT_CALL(streamMock, read())
  .WillRepeatedly(Return(101));
  EXPECT_EQ(101, streamMock.read());
}

TEST(stream, peek) {
  StreamMock streamMock;
  EXPECT_CALL(streamMock, peek())
  .WillRepeatedly(Return(254));
  EXPECT_EQ(254, streamMock.peek());
}

TEST(stream, flush) {
  StreamMock streamMock;
  EXPECT_CALL(streamMock, flush());
  streamMock.flush();
}
