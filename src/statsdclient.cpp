#include "statsdclient.h"

statsdclient::statsdclient(IPAddress destIP,
                           uint16_t destPort,
                           int (*beginPacket)(IPAddress ip, uint16_t port),
                           size_t (*write)(const uint8_t *buffer, size_t size),
                           int (*endPacket)()) {
  this->destIP = destIP;
  this->destPort = destPort;
  this->beginPacket = beginPacket;
  this->write = write;
  this->endPacket = endPacket;
}

chain& statsdclient::begin() {
  return new chain(this);
}

void send(const char *buffer) {
  this->beginPacket(this->destIP, this->destPort);
  this->write(buffer, strlen(buffer));
  this->endPacket();
}
