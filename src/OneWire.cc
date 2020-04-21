#include "OneWire.h"

static OneWireMock* gOneWireMock = NULL;

OneWireMock* oneWireMockInstance() {
    if( !gOneWireMock ) {
        gOneWireMock = new OneWireMock();
    }

    return gOneWireMock;
}


void releaseOneWireMock() {
    if( gOneWireMock ) {
        delete gOneWireMock;
        gOneWireMock = NULL;
    }
}


bool OneWire::search( uint8_t* buf ) {
    assert( gOneWireMock != NULL );
    return gOneWireMock->search( buf );
}

void OneWire::reset_search( void ) {
    assert( gOneWireMock != NULL );
    gOneWireMock->reset_search( );
}