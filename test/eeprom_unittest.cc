#include "gtest/gtest.h"
#include "arduino-mock/eeprom.h"
#include "arduino-mock/arduino.h"
EEPROM eeprom;
using ::testing::Return;

TEST(eeprom, access) {
  EEPROMMock* mock = EEPROMMockInstance();
  int a = 5; int b = 6;
  EXPECT_CALL(*mock, read(a));
  EXPECT_CALL(*mock, write(a,b));
  eeprom.read(a);
  eeprom.write(a,b);
  releaseEEPROMMock();
}
