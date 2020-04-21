add_executable(arduino_mock_tests

        Arduino_unittest.cc
        EEPROM_unittest.cc
        SPI_unittest.cc
        Serial_unittest.cc
        Spark_unittest.cc
        WiFi_unittest.cc
        Wire_unittest.cc
        serialHelper_unittest.cc
        )

target_link_libraries(arduino_mock_tests
        gtest
        gtest_main
        arduino_mock
        )

target_compile_features(arduino_mock_tests PUBLIC cxx_std_11)

add_test(
        NAME arduino_mock_tests
        COMMAND arduino_mock_tests
)
