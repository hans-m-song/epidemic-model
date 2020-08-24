#include "coordinate_map.hpp"
#include "agent.hpp"
#include "debug.h"

bool is_empty(CoordinateMap space, Point point) {
  return space.find(point) == space.end();
}

bool add_element(CoordinateMap space, Point point, Agent* element) {
  if (is_empty(space, point)) {
    space[point] = element;
    return true;
  }

  return false;
}

Point get_empty_point(CoordinateMap space) {
  int max_capacity = Coordinate::X::Max * Coordinate::Y::Max - 2;
  if (space.size() > max_capacity) {
    debug("space is at maximum capacity %d", max_capacity);
    return new_point(-1, -1);
  }

  Point point;
  for (int i = 0; i < max_capacity; i++) {
    point = new_point();
    if (space.find(point) == space.end()) {
      return point;
    }
  }

  return new_point(-1, -1);
}

Point get_empty_point(CoordinateMap space, Point origin) {
  Point point;
  for (int i = Direction::N; i <= Direction::NE; i++) {
    point = Direction::apply(origin, (Direction::Type)i);
    if (is_empty(space, point)) {
      return point;
    }
  }

  debug("no empty points around %d, %d", origin.first, origin.second);
  return origin;
}