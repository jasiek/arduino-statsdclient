#include "statsdclient.h"

statsdclient::statsdclient(IPAddress _destIP,
                           uint16_t _destPort,
                           UDP &_udp) : udp(_udp), destIP(_destIP), destPort(_destPort) {
}

chain& statsdclient::begin() {
  this->udp.beginPacket(this->destIP, this->destPort);
  return *(new chain(this->udp));
}
