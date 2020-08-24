#include "coordinate.hpp"
#include "debug.h"
#include "util.h"
#include <vector>

Point new_point(int x, int y) { return std::pair<int, int>(x, y); };

Point new_bounded_point(int x_bound, int y_bound) {
  int x = ::rand(0, x_bound);
  int y = ::rand(0, y_bound);
  return new_point(x, y);
}

Point Direction::apply(Point origin, Direction::Type direction) {
  int x = origin.first;
  int y = origin.second;

  switch (direction) {
    case Direction::Type::N:
      y += 1;
      break;
    case Direction::Type::NE:
      x += 1;
      y += 1;
      break;
    case Direction::Type::E:
      x += 1;
      break;
    case Direction::Type::SE:
      x += 1;
      y -= 1;
      break;
    case Direction::Type::S:
      y -= 1;
      break;
    case Direction::Type::SW:
      x -= 1;
      y -= 1;
      break;
    case Direction::Type::W:
      x -= 1;
      break;
    case Direction::Type::NW:
      x -= 1;
      y += 1;
      break;
  }

  return new_point(x, y);
}
