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
