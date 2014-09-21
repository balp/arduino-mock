arduino-mock
============

A GMock stub library for a mock of Arduino libraries.

How it works
============

This mock can use for Arduino sketch.
To run unittest for this mock, please follow this
instruction.

    $ git clone https://github.com/ikeyasu/arduino-mock.git
    $ cd arduino-mock/test
    $ make test
    for t in arduino_unittest serial_unittest spark_unittest; do ./$t; done;
    Running main() from gmock_main.cc
    [==========] Running 2 tests from 2 test cases.
    [----------] Global test environment set-up.
    [----------] 1 test from digitalRead
    [ RUN      ] digitalRead.2
    [       OK ] digitalRead.2 (1 ms)
    [----------] 1 test from digitalRead (1 ms total)

    [----------] 1 test from delay
    [ RUN      ] delay.normal
    [       OK ] delay.normal (0 ms)
    [----------] 1 test from delay (0 ms total)

    [----------] Global test environment tear-down
    [==========] 2 tests from 2 test cases ran. (1 ms total)
    [  PASSED  ] 2 tests.
    Running main() from gmock_main.cc
    [==========] Running 1 test from 1 test case.
    [----------] Global test environment set-up.
    [----------] 1 test from loop
    [ RUN      ] loop.pushed
    [       OK ] loop.pushed (1 ms)
    [----------] 1 test from loop (1 ms total)

    [----------] Global test environment tear-down
    [==========] 1 test from 1 test case ran. (1 ms total)
    [  PASSED  ] 1 test.
    Running main() from gmock_main.cc
    [==========] Running 1 test from 1 test case.
    [----------] Global test environment set-up.
    [----------] 1 test from publish
    [ RUN      ] publish.normal
    [       OK ] publish.normal (1 ms)
    [----------] 1 test from publish (1 ms total)

    [----------] Global test environment tear-down
    [==========] 1 test from 1 test case ran. (1 ms total)
    [  PASSED  ] 1 test.

Installation to your app
========================

You need to copy "make/Makefile" to your app's dir
and modify it.

Please refer to
https://github.com/ikeyasu/arduino-gmock-sample
