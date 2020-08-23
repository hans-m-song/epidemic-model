#include "position.hpp"
#include "debug.h"
#include "util.h"
#include <vector>

int Coordinate::X::rand(void) {
  return ::rand(Coordinate::X::Max, Coordinate::X::Min);
}
int Coordinate::Y::rand(void) {
  return ::rand(Coordinate::Y::Max, Coordinate::Y::Min);
}

Point new_point() {
  int x = Coordinate::X::rand();
  int y = Coordinate::Y::rand();
  return new_point(x, y);
};

Point new_point(int x, int y) {
  if (x < Coordinate::X::Min || x > Coordinate::X::Max ||
      y < Coordinate::Y::Min || y > Coordinate::Y::Max) {
    debug("<%d, %d> out of coordinate bounds", x, y);
  }

  return std::make_pair(x, y);
};