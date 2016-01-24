#ifndef _STATSD_CLIENT_H_
#define _STATSD_CLIENT_H_

#include <IPAddress.h>
#include <Udp.h>

#include "chain.h"

class statsdclient {
 public:
  statsdclient(IPAddress ip,
               uint16_t port,
               UDP &udp);
  chain& begin();
 private:
  IPAddress destIP;
  uint16_t destPort;
  UDP &udp;
};

#endif
