#include "epidemic.hpp"
#include "agent.hpp"
#include "position.hpp"
#include <vector>

Epidemic::Epidemic(int initial_agent_count) {
  ticks = 0;
  for (int i = 0; i < initial_agent_count; i++) {
    Epidemic::add_agent();
  }
}

Epidemic::~Epidemic() { space.clear(); }

void Epidemic::add_agent(void) {
  Point point;
  while (point = new_point(), space.find(point) != space.end()) {
    space.insert(std::make_pair(point, new Agent(point)));
  }
}

void Epidemic::tick(void) {
  ticks += 1;
  for (auto i = space.begin(); i != space.end(); ++i) {
    i->second->update(space);
  }
}