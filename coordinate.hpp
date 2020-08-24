#ifndef COORDINATE_H
#define COORDINATE_H

#include "flags.h"
#include <utility>

typedef std::pair<int, int> Point;

namespace Coordinate {
  namespace X {
    const int Min = COORDINATE_X_MIN;
    const int Max = COORDINATE_X_MAX;
    int rand(void);
  } // namespace X
  namespace Y {
    const int Min = COORDINATE_Y_MIN;
    const int Max = COORDINATE_Y_MAX;
    int rand(void);
  } // namespace Y
} // namespace Coordinate

Point new_point();

Point new_point(int x, int y);

Point bounded_point(int x_bound, int y_bound);

namespace Direction {
  enum Type { N, NE, E, SE, S, SW, W, NW };
  Point apply(Point point, Direction::Type direction);
} // namespace Direction

#endif
