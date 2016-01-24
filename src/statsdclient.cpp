#include "statsdclient.h"

statsdclient::statsdclient(IPAddress _destIP,
                           uint16_t _destPort,
                           UDP &_udp) : udp(_udp), destIP(_destIP), destPort(_destPort) {
}

chain& statsdclient::begin() {
  return new chain(*this);
}

void statsdclient::send(const char *buffer) {
  this->udp.beginPacket(this->destIP, this->destPort);
  this->udp.write(buffer, strlen(buffer));
  this->udp.endPacket();
}
