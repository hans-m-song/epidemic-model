#ifndef EPIDEMIC_H
#define EPIDEMIC_H

#include "agent.hpp"
#include "coordinate.hpp"
#include "coordinate_map.hpp"

class Epidemic {
  CoordinateMap space;
  int ticks;
  void add_agent(void);

  public:
  Epidemic(int initial_agent_count);
  ~Epidemic();
  void tick(void);
};

#endif
