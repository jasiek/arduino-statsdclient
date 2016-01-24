#include "statsdclient.h"

statsdclient::statsdclient(IPAddress destIP,
                           uint16_t destPort,
                           UDP &udp) {
  this->destIP = destIP;
  this->destPort = destPort;
  this->udp = udp;
}

chain& statsdclient::begin() {
  return new chain(this);
}

void send(const char *buffer) {
  this->udp.beginPacket(this->destIP, this->destPort);
  this->udp.write(buffer, strlen(buffer));
  this->udp.endPacket();
}
