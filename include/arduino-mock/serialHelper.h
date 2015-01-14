#ifndef SERIALHELPER_H
#define SERIALHELPER_H

/*
 * This is a helper class which can be Invoked on EXPECT_CALL to gather data
 * from repeated calls to Serial functions. For example usage, see the unit
 * tests in test/serial_unittest.cc
 *
 */
class stringCapture {
  public:
    stringCapture();
    bool captureUInt8(uint8_t c);
    bool captureUInt16(uint16_t c);
    bool captureCStr(const uint8_t *buffer, size_t size);
    void clear();
    std::string get();

  private:
    std::stringstream d;
};


#endif // SERIALHELPER_H
