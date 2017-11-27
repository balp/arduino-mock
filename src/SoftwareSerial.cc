
#include "arduino-mock/SoftwareSerial.h"

#include "gmock/gmock.h"
using testing::DoDefault;

void SoftwareSerialMock::mock_buffer_load(uint8_t buffer_0[], const uint8_t len, bool ignore_calls) {
    assert (len <= buffer_size);

    memcpy(buffer, buffer_0, len);
    buffer_head = 0;
    buffer_tail = len;

    if (ignore_calls) {
        EXPECT_CALL(*this, available())
            .WillRepeatedly(DoDefault());
        EXPECT_CALL(*this, read())
            .WillRepeatedly(DoDefault());
        EXPECT_CALL(*this, at(_))
            .WillRepeatedly(DoDefault());
    }
}

void SoftwareSerialMock::mock_buffer_load(char buffer_0[], const uint8_t len, bool ignore_calls) {
    SoftwareSerialMock::mock_buffer_load((uint8_t*)buffer_0, len, ignore_calls);
}

uint8_t SoftwareSerialMock::mock_buffer_available() {
    return (buffer_tail - buffer_head);
}

uint8_t SoftwareSerialMock::mock_buffer_read()
{
    assert(buffer_tail - buffer_head > 0);

    return buffer[buffer_head++];
}
uint8_t SoftwareSerialMock::mock_buffer_at(const uint8_t index) {
    assert(buffer_head + index < buffer_tail);

    return buffer[buffer_head + index];
}

