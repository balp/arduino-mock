cmake_minimum_required (VERSION 2.8)
project (arduino-mock)

find_package(Threads REQUIRED)
add_subdirectory(lib/gtest)
add_subdirectory(lib/gmock)

message ("building arduino-mock")
include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS} include)
file(GLOB SRC
    "src/ArduinoMockAll.cc"
)

add_library(arduino-mock STATIC ${SRC})

target_include_directories(arduino-mock
    PUBLIC "include"
)

target_link_libraries(arduino-mock
    ${GTEST_LIBS_DIR}/libgtest.a
    ${GMOCK_LIBS_DIR}/libgmock.a
    ${CMAKE_THREAD_LIBS_INIT}
)

set_target_properties( arduino-mock
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/bin"
)

add_dependencies(arduino-mock gtest gmock)

option(test "Build all tests." OFF)

if (test)
  enable_testing()
  add_subdirectory(test)
endif()

install (
  TARGETS arduino-mock
  ARCHIVE DESTINATION lib
)

export (
  TARGETS arduino-mock
  FILE ${CMAKE_BINARY_DIR}/arduino-mock-config.cmake
)
