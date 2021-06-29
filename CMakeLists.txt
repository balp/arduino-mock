cmake_minimum_required(VERSION 3.14)
if (NOT DEFINED PROJECT_NAME)
    set(NOT_SUBPROJECT ON)
endif ()

project(arduino_mock)

find_package(Threads REQUIRED)

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
        src/OneWire.cc
        src/Serial.cc
        src/Spark.cc
        src/Wire.cc
        src/IRremote.cc
        src/SPI.cc
        src/SoftwareSerial.cc
        src/WiFi.cc
        src/serialHelper.cc
        )
target_include_directories(arduino_mock
        PRIVATE "include"
        PUBLIC "include/arduino-mock"
        INTERFACE "include/arduino-mock"
        )
target_link_libraries(arduino_mock
        gmock
        gtest
        ${CMAKE_THREAD_LIBS_INIT}
        )
target_compile_features(arduino_mock PUBLIC cxx_std_11)
set_target_properties(arduino_mock PROPERTIES CXX_EXTENSIONS OFF)

set_target_properties(arduino_mock
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

add_dependencies(arduino_mock gtest gmock)

option(test "Build all tests." OFF)

if (test)
    enable_testing()
    add_subdirectory(test)
endif ()
