#include "gtest/gtest.h"
#include <SPI.h>
#include "WiFiNINA.h"
#include "Arduino.h"

WiFiClass WiFi;

using ::testing::Return;
TEST(wifinina, smoketest) {
  WiFiNinaMock *mock = WiFiNinaMockInstance();
  char IPAddr[] = "192.168.0.1";
  uint8_t n_times = 10;
  EXPECT_CALL(*mock, begin("test_net"));
  EXPECT_CALL(*mock, begin("test_net", "password"));
  EXPECT_CALL(*mock, begin("test_net", 2, "123450987654321"));

  WiFi.begin("test_net");
  WiFi.begin("test_net", "password");
  WiFi.begin("test_net", 2, "123450987654321");

  releaseWiFiNinaMock();
}
