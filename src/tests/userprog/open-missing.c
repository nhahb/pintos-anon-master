/* Tries to open a nonexistent file. */

#include <syscall.h>
#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "open-missing";

void
test_main (void) 
{
  int handle = open ("no-such-file");
  if (handle != -1)
    fail ("open() returned %d", handle);
}
