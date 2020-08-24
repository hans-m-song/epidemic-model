#ifndef AGENT_H
#define AGENT_H

#include "coordinate.hpp"
#include <unordered_map>

enum class Status {
  Normal,
  Infected,
  Immune,
  Deceased,
};

namespace StatusTime {
  const int Immune = 5;
  const int Infected = 5;
} // namespace StatusTime

class Agent {
  public:
  Status status;
  int time_in_status;
  int age;
  Point position;

  Agent(Point initial_position, bool infected);
  void move(Point new_position);
  void update(bool infected_nearby);
};

#endif
