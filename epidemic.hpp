#ifndef EPIDEMIC_H
#define EPIDEMIC_H

#include "agent.hpp"
#include "coordinate.hpp"
#include "coordinate_map.hpp"

class Epidemic {
  CoordinateMap* space;

  public:
  Epidemic(int initial_agent_count, int width, int height);
  ~Epidemic();
  void tick(void);
};

#endif
