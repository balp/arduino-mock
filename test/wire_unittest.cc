#include "gtest/gtest.h"
#include "arduino-mock/wire.h"
#include "arduino-mock/arduino.h"
Wire wire;

using ::testing::Return;
TEST(wire, access) {
  uint8_t value1 = 10;
  uint8_t value2 = 12;
  char text[] = "Mock test";
  WireMock* mock = WireMockInstance();
  EXPECT_CALL(*mock, endTransmission(value1));
  EXPECT_CALL(*mock, begin());
  EXPECT_CALL(*mock, requestFrom(value1,value2));
  EXPECT_CALL(*mock, write(text));
  wire.endTransmission(value1);
  wire.begin();
  wire.requestFrom(value1,value2);
  wire.write(text);
  releaseWireMock();
}