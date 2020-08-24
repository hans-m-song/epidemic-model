#include "coordinate.hpp"
#include "debug.h"
#include "util.h"
#include <vector>

int Coordinate::X::rand(void) {
  return ::rand(Coordinate::X::Min, Coordinate::X::Max);
}

int Coordinate::Y::rand(void) {
  return ::rand(Coordinate::Y::Min, Coordinate::Y::Max);
}

Point new_point() {
  int x = Coordinate::X::rand();
  int y = Coordinate::Y::rand();
  return new_point(x, y);
};

Point new_point(int x, int y) { return std::pair<int, int>(x, y); };

Point bounded_point(int x_bound, int y_bound) {
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
