#include "debug.h"
#include "flags.h"
#include <stdarg.h>
#include <stdio.h>

void debug(const char* format, ...) {
  if (DEBUG) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    printf("\n");
    va_end(args);
  } else {
    printf("ignoring print\n");
  }
}
