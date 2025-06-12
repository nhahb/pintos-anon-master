/* Tries to close the console output stream, which must either
   fail silently or terminate with exit code -1. */

#include <syscall.h>
#include "tests/main.h"

const char *test_name = "close-stdout";

void
test_main (void) 
{
  close (1);
}
