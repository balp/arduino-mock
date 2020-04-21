
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


## License and credits

Library was started by Anders Arnholm <Anders@Arnholm.se> in 2013 and have
duirng the years have several contributors including, Yasuki Ikeuchi <ikeyasu@gmail.com>
from where most contributes forked.

The original License for the library is under a ICS, or OpenBSD licence. With some
helper files form the Arduino source code with a LGPL v2.1 licence.
At the moment this is the WString, WMath and itoa code.   
 


Some helpers are same as Arduino library (SAMD 1.8.6) 
```
  Copyright (c) 2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
```
