#include "agent.hpp"
#include "coordinate.hpp"
#include "debug.h"
#include "parameters.hpp"

Agent::Agent(Point initial_position, bool infected) {
  position = initial_position;
  status = infected ? Status::Infected : Status::Normal;
}

void Agent::move(Point new_position) { position = new_position; }

void Agent::update(bool infected_nearby) {
  switch (status) {
    case Status::Normal:
      if (infected_nearby) { // TODO transmission rate
        time_in_status = 0;
        status = Status::Infected;
      }
      break;
    case Status::Infected:
      time_in_status += 1;
      if (time_in_status > Parameters::InfectedDuration) {
        time_in_status = 0;
        status = Status::Immune;
      }
      time_in_status += 1;
      break;
    case Status::Immune:
      time_in_status += 1;
      if (time_in_status > Parameters::ImmuneDuration) {
        time_in_status = 0;
        status = Status::Normal;
      }
      break;
    case Status::Deceased:
      debug("warning: updating deceased agent");
      break;
  }

  age += 1;
}
