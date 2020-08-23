#include "util.h"
#include <cstdlib>

int rand(int lower, int upper) { return lower + (std::rand() % (upper - lower + 1)); }
