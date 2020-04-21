//
// Created by Anders Arnholm on 2020-04-21.
//

#ifndef ARDUINO_MOCK_INCLUDE_PRINTABLE_H_
#define ARDUINO_MOCK_INCLUDE_PRINTABLE_H_

#include <stdlib.h>

class Print;

/** The Printable class provides a way for new classes to allow themselves to be printed.
    By deriving from Printable and implementing the printTo method, it will then be possible
    for users to print out instances of this class by passing them into the usual
    Print::print and Print::println methods.
*/

class Printable
{
 public:
  virtual size_t printTo(Print& p) const = 0;
};


#endif //ARDUINO_MOCK_INCLUDE_PRINTABLE_H_
