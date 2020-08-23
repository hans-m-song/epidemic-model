#ifndef EPIDEMIC_H
#define EPIDEMIC_H

#include "agent.hpp"
#include "position.hpp"
#include <map>

class Epidemic {
  std::map<Point, Agent*> space;
  int ticks;

  void add_agent();

  public:
  Epidemic(int initial_agent_count);
  ~Epidemic();
  void tick(void);
};

#endif
