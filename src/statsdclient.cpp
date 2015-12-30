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

statsdclient& statsdclient::begin() {
  if (this->buffer) delete this->buffer;
  this->buffer = new buffer[128];
  return this;
}

statsdclient& statsdclient::counter(const char* metric, int value) {
  return this;
}

statsdclient& statsdclient::sample(const char* metric, int value, float frequency) {
  return this;
}

statsdclient& statsdclient::timing(const char* metric, int value, float frequency) {
  return this;
}

statsdclient& statsdclient::gauge(const char* metric, int value) {
  return this;
}

statsdclient& statsdclient::set(const char* metric, const char* value) {
  return this;
}

void statsdclient::send() {
  
}
