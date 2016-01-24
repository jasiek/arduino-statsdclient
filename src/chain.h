#ifndef _CHAIN_H_
#define _CHAIN_H_
#include "statsdclient.h"

class chain {
 public:
  chain(statsdclient&);
  chain& counter(const char*, int, float);
  chain& counter(const char*, int);
  
  chain& timing(const char*, int, float);
  chain& timing(const char*, int);
  
  chain& gauge(const char*, int);
  chain& set(const char*, const char*);
  void send();
 private:
  void append(const char *, const char *, const char*);
  void append(const char *, const char *, const char*, float);
  
  statsdclient &client;
  char *buffer;
};

#endif
