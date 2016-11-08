#include "Arduino_unittest.cc"
#include "EEPROM_unittest.cc"
#include "Serial_unittest.cc"
#include "serialHelper_unittest.cc"
#include "Spark_unittest.cc"
#include "WiFi_unittest.cc"
#include "Wire_unittest.cc"
#include "SPI_unittest.cc"
int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
