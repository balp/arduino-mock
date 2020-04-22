cmake_minimum_required(VERSION 3.14)
if (NOT DEFINED PROJECT_NAME)
    set(NOT_SUBPROJECT ON)
endif ()

project(arduino_mock)

find_package(Threads REQUIRED)

set(CMAKE_VERBOSE_MAKEFILE on)

# If we are a stand alone project not included with add_subdirectory() and
# googletest, e.g. googlemock is not provided make sure to download it.
if (NOT_SUBPROJECT)
    if (NOT TARGET gmock_main)
        include(FetchContent)

        FetchContent_Declare(googletest
                GIT_REPOSITORY https://github.com/google/googletest.git
                GIT_TAG release-1.10.0)
        FetchContent_MakeAvailable(googletest)
    endif ()
endif ()

add_library(arduino_mock STATIC
        src/Arduino.cc
        src/EEPROM.cc
        src/IPAddress.cpp
        src/IRremote.cc
        src/OneWire.cc
        src/Serial.cc
        src/SoftwareSerial.cc
        src/Spark.cc
        src/SPI.cc
        src/WiFi.cc
        src/WiFiNINA.cc
        src/Wire.cc
        src/WMath.cpp
        src/WString.cpp
        src/dtostrf.c
        src/itoa.c
        src/serialHelper.cc
        include/Arduino.h
        include/EEPROM.h
        include/IPAddress.h
        include/IRremote.h
        include/Print.h
        include/RedBot.h
        include/Serial.h
        include/Spark.h
        include/WString.h
        include/Wire.h
        include/Client.h
        include/IPAddress.h
        include/OneWire.h
        include/Printable.h
        include/SPI.h
        include/SoftwareSerial.h
        include/Stream.h
        include/WiFi.h
        include/WiFiNINA.h
        include/dtostrf.h
        include/itoa.h
        include/serialHelper.h
        src/Print.cc)
target_include_directories(arduino_mock
        PRIVATE "include"
        PUBLIC "include"
        INTERFACE "include"
        )
target_link_libraries(arduino_mock
        gmock
        gtest
        ${CMAKE_THREAD_LIBS_INIT}
        )
target_compile_features(arduino_mock PUBLIC cxx_std_11)
set_target_properties(arduino_mock PROPERTIES CXX_EXTENSIONS OFF)

if (NOT_SUBPROJECT)
    enable_testing()
    add_subdirectory(test)
endif ()
