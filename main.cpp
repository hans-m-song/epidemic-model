#include "debug.h"
#include "epidemic.hpp"
#include "flags.h"
#include <iostream>

int main(int argc, char** argv) {
  if (argc != 5) {
    std::cout << "not enough args"
              << "\n"
              << "example: ./epidemic agent_count duration width height"
              << "\n";
    return 1;
  }

  // TODO use these
  int agent_count = atoi(argv[1]);
  int duration = atoi(argv[2]);
  int width = atoi(argv[3]);
  int height = atoi(argv[4]);

  debug("params: agent_count = %d, width = %d, height = %d", agent_count, width,
        height);

  Epidemic* epidemic = new Epidemic(agent_count, width, height);

  for (int i = 0; i < duration; i++) {
    debug("tick %d", i);
    epidemic->tick();
  }

  delete epidemic;
  return 0;
}
