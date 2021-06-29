
# arduino-mock

A GMock stub library for a mock of Arduino libraries.

## How it works

This is the mock library for Arduino sketch program.
To run unittest for this mock, please follow this
instruction.

## Sample and how to install to your app

### Catch2

Sample CMakeLists.txt using Catch2 and Google Mock:

```cmake
# Required include
include(FetchContent)

# Fetching all the required repositories and making them available
FetchContent_Declare(Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v2.11.1)

FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.10.0)

FetchContent_Declare(arduino_mock
    GIT_REPOSITORY https://github.com/balp/arduino-mock.git
    GIT_TAG cmake3)

FetchContent_MakeAvailable(Catch2 googletest arduino_mock)

# Adding the software and main test file as an executable
add_executable(tests
    main.cpp
    tests.cpp)

# Link all libraries
target_link_libraries(tests
    Catch2::Catch2
    arduino_mock)

# (Optional) Setting up the compiler
target_compile_features(tests PUBLIC cxx_std_11)
set_target_properties(tests PROPERTIES CXX_EXTENSIONS OFF)

# Enable CTest
enable_testing()
# Add your test to CTest
add_test(NAME tests COMMAND tests)
```

## GTest

Sample CMakeLists.txt using Google Test and Google Mock:

```cmake
# Required include
include(FetchContent)

# Fetching all the required repositories and making them available
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.10.0)

FetchContent_Declare(arduino_mock
    GIT_REPOSITORY https://github.com/balp/arduino-mock.git
    GIT_TAG cmake3)

FetchContent_MakeAvailable(googletest arduino_mock)

# Adding the software and main test file as an executable
add_executable(tests
    main.cpp
    tests.cpp)

# Link all libraries
target_link_libraries(tests
    gtest_main
    arduino_mock)

# (Optional) Setting up the compiler
target_compile_features(tests PUBLIC cxx_std_11)
set_target_properties(tests PROPERTIES CXX_EXTENSIONS OFF)

# Enable CTest
enable_testing()
# Add your test to CTest
add_test(NAME tests COMMAND tests)
```

## Contribution

Please send a pull-request.  
