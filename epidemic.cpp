#include "epidemic.hpp"
#include "agent.hpp"
#include "coordinate.hpp"
#include "coordinate_map.hpp"
#include "debug.h"
#include <vector>

Epidemic::Epidemic(int initial_agent_count, int width, int height) {
  space = new CoordinateMap(width, height);
  for (int i = 0; i < initial_agent_count; i++) {
    debug("new agent %d", i);
    Point point = space->get_empty_point();
    space->add_agent(point, new Agent(point, false));
  }
}

Epidemic::~Epidemic() { delete space; }

void Epidemic::tick(void) {
  Point point;
  for (auto i : space->map) {
    // TODO check out of bounds
    point = new_point(i.second->position.first, i.second->position.second);
    i.second->move(point);
  }

  for (auto i : space->map) {
    i.second->update(false);
  }
}
