#include "chain.h"

chain::chain(statsdclient &client) {
  this->buffer = new char[128];
  memset(this->buffer, 0, 128);
}

chain &chain::counter(const char *metric, int value) {
  char stringValue[16];
  itoa(value, stringValue, 10);
  append(metric, stringValue, "c");
  return this;
}

chain &chain::timing(const char* metric, int value, float freq) {
  char stringValue[16];
  itoa(value, stringValue, 10);
  append(metric, stringValue, "ms", freq);
  return this;
}

chain &chain::gauge(const char* metric, int value) {
  char stringValue[16];
  itoa(value, stringValue, 10);
  append(metric, stringValue, "g");
  return this;
}

chain &chain::set(const char* metric, const char* value) {
  append(metric, value, "s");
  return this;
}

void chain::send() {
  this->client.send(this->buffer);
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
  char stringFreq[16];
  ftoa(freq, stringFreq);
  strcat(this->buffer, metric);
  strcat(this->buffer, ":");
  strcat(this->buffer, value);
  strcat(this->buffer, "|");
  strcat(this->buffer, type);
  strcat(this->buffer, "|@");
  strcat(this->buffer, stringFreq);
  strcat(this->buffer, "\n");
}
