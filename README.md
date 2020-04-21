
arduino-mock
============

A GMock stub library for a mock of Arduino libraries.

How it works
============

This is the mock library for Arduino sketch program.
To run unittest for this mock, please follow this
instruction.

    

Sample and how to install to your app
====================================

Sample CMakeLists.txt, Using catch2 and google mock:

    FetchContent_Declare(Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG v2.11.1)

    FetchContent_MakeAvailable(Catch2)

    FetchContent_Declare(googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG release-1.10.0)

    FetchContent_MakeAvailable(googletest)
    
    FetchContent_Declare(arduino-mock
            GIT_REPOSITORY https://github.com/balp/arduino-mock.git
            GIT_TAG cmake3)

    FetchContent_MakeAvailable(arduino-mock)

    add_executable(tests
            main.cpp
            tests.cpp)
    
    target_link_libraries(tests
            Catch2::Catch2
            arduino_mock)
    
    target_compile_features(tests PUBLIC cxx_std_11)
    set_target_properties(tests PROPERTIES CXX_EXTENSIONS OFF)
    
    add_test(NAME tests
             COMMAND tests)






Contribution
============

Please send a pull-request.  


