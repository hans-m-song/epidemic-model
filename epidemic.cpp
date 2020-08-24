#include "epidemic.hpp"
#include "agent.hpp"
#include "coordinate.hpp"
#include "coordinate_map.hpp"
#include "debug.h"
#include <vector>

Epidemic::Epidemic(int initial_agent_count) {
  ticks = 0;
  for (int i = 0; i < initial_agent_count; i++) {
    Point point = get_empty_point(space);
    add_element(space, point, new Agent(point));
  }
}

Epidemic::~Epidemic() { space.clear(); }

void Epidemic::tick(void) {
  ticks += 1;

  for (auto i : space) {
    i.second->move(
        new_point(i.second->position.first, i.second->position.second));
  }

  for (auto i : space) {
    i.second->update(false);
  }
}
