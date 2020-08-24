#ifndef COORDINATE_H
#define COORDINATE_H

#include "flags.h"
#include <utility>

typedef std::pair<int, int> Point;

Point new_point(int x, int y);

Point new_bounded_point(int x_bound, int y_bound);

namespace Direction {
  enum Type { N, NE, E, SE, S, SW, W, NW };
  Point apply(Point point, Direction::Type direction);
} // namespace Direction

#endif
