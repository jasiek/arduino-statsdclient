#ifndef _CHAIN_H_
#define _CHAIN_H_

class chain {
 public:
  chain(statsdclient&);
  chain& counter(const char*, int, float);
  chain& timing(const char*, int, float);
  chain& gauge(const char*, int);
  chain& set(const char*, const char*);
  void send();
 private:
  statsdclient &client;
  char *buffer;
}

#endif
