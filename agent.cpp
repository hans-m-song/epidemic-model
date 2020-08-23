#include "agent.hpp"
#include "debug.h"
#include "position.hpp"
#include <cstdlib>

Agent::Agent(Point initial_position) { position = initial_position; }

void Agent::move(Point new_position) { position = new_position; }

Point Agent::get_position(void) const { return position; }

void Agent::update(std::map<Point, Agent*> space) {
  if (status == Status::Deceased) {
    debug("updating dead agent");
    return;
  }

  switch (status) {
    case Status::Normal:
      break;
    case Status::Immune:
      time_in_status += 1;
      if (time_in_status > StatusTime::Immune) {
        time_in_status = 0;
        status = Status::Normal;
      }
    case Status::Infected:
      time_in_status += 1;
    default:
      break;
  }

  age += 1;
}
