#include "coordinate_map.hpp"
#include "agent.hpp"
#include "debug.h"

CoordinateMap::CoordinateMap(int x_bound, int y_bound)
    : x_bound(x_bound), y_bound(y_bound) {}

CoordinateMap::~CoordinateMap() {
  for (auto i : map) {
    delete i.second;
  }

  map.clear();
}

bool CoordinateMap::is_empty(Point point) {
  return map.find(point) == map.end();
}

bool CoordinateMap::add_agent(Point point, Agent* element) {
  if (is_empty(point)) {
    map[point] = element;
    return true;
  }

  return false;
}

Point CoordinateMap::get_empty_point() {
  int max_capacity = x_bound * y_bound;
  if (map.size() > max_capacity) {
    debug("map is at maximum capacity %d", max_capacity);
    return new_point(-1, -1);
  }

  Point point;
  for (int i = 0; i < max_capacity; i++) {
    point = bounded_point(x_bound, y_bound);
    if (map.find(point) == map.end()) {
      return point;
    }
  }

  return new_point(-1, -1);
}

Point CoordinateMap::get_empty_point(Point origin) {
  Point point;
  for (int i = Direction::N; i <= Direction::NE; i++) {
    point = Direction::apply(origin, (Direction::Type)i);
    if (is_empty(point)) {
      return point;
    }
  }

  debug("no empty points around %d, %d", origin.first, origin.second);
  return origin;
}