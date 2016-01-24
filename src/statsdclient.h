#ifndef _STATSD_CLIENT_H_
#define _STATSD_CLIENT_H_

#include <IPAddress.h>
#include <Udp.h>

class chain;

class statsdclient {
 public:
  statsdclient(IPAddress ip,
               uint16_t port,
               UDP &udp);
  chain& begin();
  void send(const char* buffer);
 private:
  IPAddress destIP;
  uint16_t destPort;
  int (*beginPacket)(IPAddress, uint16_t);
};

#endif
