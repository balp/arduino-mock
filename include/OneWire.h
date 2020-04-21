/**
 * Arduino Serial mock
 */
#ifndef ONEWIRE_H
#define ONEWIRE_H

#include "gmock/gmock.h"


/**
  \brief Mock para la clase onewire de arduino
  \author Borja Fons
  \date 10/11/2017
  \attention Este mock deberia moverse al repo del mock de arduino
*/
class OneWireMock {
  public:
    MOCK_METHOD1( search, bool( uint8_t* ) );
    MOCK_METHOD0( reset_search, void( void ) );
};

class OneWire {
  public:
    OneWire( const uint8_t ) {};
    bool search( uint8_t* buf );
    void reset_search( void );
  private:
    uint8_t pin;
};

OneWireMock* oneWireMockInstance();
void releaseOneWireMock();

#endif // ONEWIRE_H