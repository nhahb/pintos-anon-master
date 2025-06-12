/* Tries to close an invalid fd, which must either fail silently
   or terminate with exit code -1. */

#include <syscall.h>
#include "tests/main.h"

const char *test_name = "close-bad-fd";

void
test_main (void) 
{
  close (0x20101234);
}
