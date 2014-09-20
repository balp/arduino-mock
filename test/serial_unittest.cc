// Copyright 2014 http://switchdevice.com
// This example code is in the public domain.

#include "gtest/gtest.h"
#include "arduino-mock/arduino.h"
#include "arduino-mock/serial.h"
Serial_ Serial;

using ::testing::Return;
TEST(loop, pushed) {
  SerialMock* serialMock = serialMockInstance();
  EXPECT_CALL(*serialMock, println(1, 10));
  Serial.println(1, 10);
  delete serialMock;
}
