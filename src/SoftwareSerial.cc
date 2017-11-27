
#include "arduino-mock/SoftwareSerial.h"

void SoftwareSerialFake::buffer_load(uint8_t buffer_0[], const uint8_t len) {
    assert (len <= buffer_size);

    memcpy(buffer, buffer_0, len);
    buffer_head = 0;
    buffer_tail = len;
}

uint8_t SoftwareSerialFake::available() {
    return (buffer_tail - buffer_head);
}

uint8_t SoftwareSerialFake::read()
{
    assert(buffer_tail - buffer_head > 0);

    return buffer[buffer_head++];
}
uint8_t SoftwareSerialFake::at(const uint8_t index) {
    assert(buffer_head + index < buffer_tail);

    return buffer[buffer_head + index];
}

