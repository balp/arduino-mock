// Header for Wifi Mock

#ifndef __Wifi_h__
#define __Wifi_h__

#include <gmock/gmock.h>
#include <stdint.h>
#include "IPAddress.h"

class WiFiClass {
 public:
  // static const char *firmwareVersion();
  int begin(const char *ssid);
  int begin(const char *ssid, uint8_t key_idx, const char *key);
  int begin(const char *ssid, const char *passphrase);

  uint8_t status();
  unsigned long getTime();

#if 0 // XXX Implement full WiFININA interface
  uint8_t beginAP(const char *ssid);
  uint8_t beginAP(const char *ssid, uint8_t channel);
  uint8_t beginAP(const char *ssid, const char* passphrase);
  uint8_t beginAP(const char *ssid, const char* passphrase, uint8_t channel);

  uint8_t beginEnterprise(const char* ssid, const char* username, const char* password);
  uint8_t beginEnterprise(const char* ssid, const char* username, const char* password, const char* identity);
  uint8_t beginEnterprise(const char* ssid, const char* username, const char* password, const char* identity, const char* ca);

  void config(IPAddress local_ip);
  void config(IPAddress local_ip, IPAddress dns_server);
  void config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway);
  void config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet);
  void setDNS(IPAddress dns_server1);
  void setDNS(IPAddress dns_server1, IPAddress dns_server2);
  void setHostname(const char* name);

  int disconnect(void);
  void end(void);
  uint8_t *macAddress(uint8_t *mac);
  IPAddress localIP();
  IPAddress subnetMask();
  IPAddress gatewayIP();
  const char *SSID();
  uint8_t *BSSID(uint8_t *bssid);
  int32_t RSSI();
  uint8_t encryptionType();
  int8_t scanNetworks();
  const char *SSID(uint8_t networkItem);
  uint8_t encryptionType(uint8_t networkItem);
  uint8_t *BSSID(uint8_t networkItem, uint8_t *bssid);
  uint8_t channel(uint8_t networkItem);
  int32_t RSSI(uint8_t networkItem);
  uint8_t reasonCode();
  int hostByName(const char *aHostname, IPAddress &aResult);

  unsigned long getTime();

  void lowPowerMode();
  void noLowPowerMode();

  int ping(const char *hostname, uint8_t ttl = 128);
  int ping(const String &hostname, uint8_t ttl = 128);
  int ping(IPAddress host, uint8_t ttl = 128);

  void setTimeout(unsigned long timeout);
#endif
};

extern WiFiClass WiFi;

class WiFiNinaMock {
 public:
  MOCK_METHOD1(begin, int(const char *));
  MOCK_METHOD3(begin, int(const char *, uint8_t, const char *));
  MOCK_METHOD2(begin, int(const char *, const char *));
  MOCK_METHOD0(status, uint8_t());
  MOCK_METHOD0(getTime, unsigned long());
};

WiFiNinaMock *WiFiNinaMockInstance();
void releaseWiFiNinaMock();

#endif
