#include "WiFiNINA.h"

static WiFiNinaMock *p_WiFiNinaMock = nullptr;

WiFiNinaMock *WiFiNinaMockInstance() {
  if (!p_WiFiNinaMock) {
    p_WiFiNinaMock = new WiFiNinaMock();
  }
  return p_WiFiNinaMock;
}

void releaseWiFiNinaMock() {
  if (p_WiFiNinaMock) {
    delete p_WiFiNinaMock;
    p_WiFiNinaMock = nullptr;
  }
}

int WiFiClass::begin(const char *ssid) {
  return p_WiFiNinaMock->begin(ssid);
}
int WiFiClass::begin(const char *ssid, uint8_t key_idx, const char *key) {
  return p_WiFiNinaMock->begin(ssid, key_idx, key);
}
int WiFiClass::begin(const char *ssid, const char *passphrase) {
  return p_WiFiNinaMock->begin(ssid, passphrase);
}

#ifdef ARDUINO_MOCK_CONFIG_WIFININA
// Preinstantiate Objects
WiFiClass WiFi;
#endif // ARDUINO_MOCK_CONFIG_WIFININA