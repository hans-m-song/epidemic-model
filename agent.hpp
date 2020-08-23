#ifndef AGENT_H
#define AGENT_H

#include "position.hpp"
#include <map>

enum class Status {
  Normal,
  Infected,
  Immune,
  Deceased,
};

namespace StatusTime {
  const int Immune = 5;
  const int Infected = 5;
}; // namespace StatusTime

class Agent {
  Status status;
  int time_in_status;
  int age;
  Point position;

  public:
  Agent(Point initial_position);
  void move(Point new_position);
  Point get_position(void) const;
  Status get_status(void) const;
  void update(std::map<Point, Agent*> space);
};

#endif
