#ifndef POSITION_H
#define POSITION_H

#include "flags.h"
#include <vector>

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

typedef std::pair<int, int> Point;

Point new_point();

Point new_point(int x, int y);

enum Direction { N, NE, E, SE, S, SW, W, NW };

#endif
