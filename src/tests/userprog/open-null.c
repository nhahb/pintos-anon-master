/* Tries to open a file with the null pointer as its name.
   The process must be terminated with exit code -1. */

#include <stddef.h>
#include <syscall.h>
#include "tests/main.h"

const char *test_name = "open-null";

void
test_main (void) 
{
  open (NULL);
}
