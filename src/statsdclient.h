#ifndef _STATSD_CLIENT_H_
#define _STATSD_CLIENT_H_

#include "chain.h"

class statsdclient {
 public:
  statsdclient(IPAddress ip,
               uint16_t port,
               int (*beginPacket)(IPAddress ip, uint16_t port),
               size_t (*write)(const uint8_t *buffer, size_t size),
               int (*endPacket)());
  chain& begin();
  void send(const char* buffer);
 private:
  IPAddress destIP;
  uint16_t destPort;
  int (*beginPacket)(IPAddress, uint16_t);
}

#endif
