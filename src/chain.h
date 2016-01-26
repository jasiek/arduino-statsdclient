#ifndef _CHAIN_H_
#define _CHAIN_H_

#include <Arduino.h>
#include <Udp.h>

class chain {
 public:
  chain(UDP &);
  chain& counter(const char*, int, float);
  chain& counter(const char*, int);
  
  template <typename Numeric> chain& timing(const char*, Numeric, float);
  template <typename Numeric> chain& timing(const char*, Numeric);
  
  template <typename Numeric> chain& gauge(const char*, Numeric);
  chain& set(const char*, const char*);
  void send();
 private:
  void append(const char *, const char *, const char*);
  void append(const char *, const char *, const char*, float);
  
  UDP &udp;
  char *buffer;
};

// http://stackoverflow.com/questions/10632251/undefined-reference-to-template-function

template <typename Numeric> chain &chain::timing(const char* metric, Numeric value, float freq) {
  String stringValue(value);
  append(metric, stringValue.c_str(), "ms", freq);
  return *this;
}

template <typename Numeric> chain &chain::timing(const char* metric, Numeric value) {
  String stringValue(value);
  append(metric, stringValue.c_str(), "ms");
  return *this;
}

template <typename Numeric> chain &chain::gauge(const char* metric, Numeric value) {
  String stringValue(value);
  append(metric, stringValue.c_str(), "g");
  return *this;
}

#endif
