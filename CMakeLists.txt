cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "-std=c++98")
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

include(ExternalProject)
include(external)

project (arduino-mock)

#Test libs
ExternalProject_Add(gtest
    URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    UPDATE_COMMAND ""
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(gtest source_dir)
set(GTEST_INCLUDE_DIR ${source_dir}/include)
message("GTEST_INCLUDE_DIR: ${GTEST_INCLUDE_DIR}")

ExternalProject_Get_Property(gtest binary_dir)
set(GTEST_LIB_DIR ${binary_dir})
message("GTEST_LIB_DIR: ${GTEST_LIB_DIR}")

include_directories( arduino-mock ${GTEST_INCLUDE_DIR} )


ExternalProject_Add(gmock
    URL https://googlemock.googlecode.com/files/gmock-1.7.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gmock
    UPDATE_COMMAND ""
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(gmock source_dir)
set(GMOCK_INCLUDE_DIR ${source_dir}/include)
message("GMOCK_INCLUDE_DIR: ${GMOCK_INCLUDE_DIR}")

ExternalProject_Get_Property(gmock binary_dir)
set(GMOCK_LIB_DIR ${binary_dir})
message("GMOCK_LIB_DIR: ${GMOCK_LIB_DIR}")


include_directories( arduino-mock ${GMOCK_INCLUDE_DIR} )

include_directories( arduino-mock include )
#library setup
add_library(arduino-mock STATIC "src/ArduinoMockAll.cc")

target_include_directories(arduino-mock
    PUBLIC "include"
)

message("target_link_libraries:")

target_link_libraries( arduino-mock
    ${GTEST_LIB_DIR}/libgtest.a
    ${GMOCK_LIB_DIR}/libgmock.a
    ${CMAKE_THREAD_LIBS_INIT}
)

add_dependencies(arduino-mock gtest gmock)

set_target_properties( arduino-mock
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/bin"
)

# install (
#   TARGETS arduino-mock
#   ARCHIVE DESTINATION lib
# )
#
# export (
#   TARGETS arduino-mock
#   FILE ${CMAKE_BINARY_DIR}/arduino-mock-config.cmake
# )
#
# export (
#   PACKAGE arduino-mock
# )

option(test "Build all tests." OFF)

if (test)
  enable_testing()
  add_subdirectory(test)
endif()
