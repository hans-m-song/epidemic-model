#include "debug.h"
#include "epidemic.hpp"
#include "flags.h"

int main(int argc, char** argv) {
  Epidemic* epidemic = new Epidemic(INITIAL_AGENTS);

  for (int i = 0; i < MAX_TICKS; i++) {
    debug("tick %d\n", i);
    epidemic->tick();
  }

  delete epidemic;
  return 0;
}
