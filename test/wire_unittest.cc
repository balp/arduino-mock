#include "gtest/gtest.h"
#include "arduino-mock/wire.h"
#include "arduino-mock/arduino.h"
Wire wire;

using ::testing::Return;
TEST(wire, access) {
  uint8_t a = 10;
  uint8_t b = 12;
  WireMock* mock = WireMockInstance();
  EXPECT_CALL(*mock, endTransmission(10));
  EXPECT_CALL(*mock, begin());
  EXPECT_CALL(*mock, requestFrom(a,b));
  wire.endTransmission(10);
  wire.begin();
  wire.requestFrom(a,b);
  releaseWireMock();
}