#include "chain.h"

chain::chain(UDP &_udp) : udp(_udp) {
  this->buffer = new char[128];
  memset(this->buffer, 0, 128);
}

chain &chain::counter(const char *metric, int value, float freq) {
  String stringValue(value);
  append(metric, stringValue.c_str(), "c", freq);
  return *this;
}

chain &chain::counter(const char *metric, int value) {
  String stringValue(value);
  append(metric, stringValue.c_str(), "c");
  return *this;
}

chain &chain::timing(const char* metric, int value, float freq) {
  String stringValue(value);
  append(metric, stringValue.c_str(), "ms", freq);
  return *this;
}

chain &chain::timing(const char* metric, int value) {
  String stringValue(value);
  append(metric, stringValue.c_str(), "ms");
  return *this;
}

chain &chain::gauge(const char* metric, int value) {
  String stringValue(value);
  append(metric, stringValue.c_str(), "g");
  return *this;
}

chain &chain::set(const char* metric, const char* value) {
  append(metric, value, "s");
  return *this;
}

void chain::send() {
  this->udp.write((uint8_t *)this->buffer, strlen(this->buffer));
  this->udp.endPacket();
  delete this;
}

void chain::append(const char* metric, const char* value, const char* type) {
  strcat(this->buffer, metric);
  strcat(this->buffer, ":");
  strcat(this->buffer, value);
  strcat(this->buffer, "|");
  strcat(this->buffer, type);
  strcat(this->buffer, "\n");
}

void chain::append(const char* metric, const char* value, const char* type, float freq) {
  String stringFreq(freq);
  strcat(this->buffer, metric);
  strcat(this->buffer, ":");
  strcat(this->buffer, value);
  strcat(this->buffer, "|");
  strcat(this->buffer, type);
  strcat(this->buffer, "|@");
  strcat(this->buffer, stringFreq.c_str());
  strcat(this->buffer, "\n");
}
