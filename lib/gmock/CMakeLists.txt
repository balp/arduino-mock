cmake_minimum_required(VERSION 2.8.8)
project(gmock_builder C CXX)
include(ExternalProject)

ExternalProject_Add(gmock
    URL https://googlemock.googlecode.com/files/gmock-1.7.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gmock
    INSTALL_COMMAND ""
)

# Specify include dir
ExternalProject_Get_Property(gmock source_dir)
set(GMOCK_INCLUDE_DIRS ${source_dir}/include PARENT_SCOPE)

# Specify MainTest's link libraries
ExternalProject_Get_Property(gmock binary_dir)
set(GMOCK_LIBS_DIR ${binary_dir} PARENT_SCOPE)
