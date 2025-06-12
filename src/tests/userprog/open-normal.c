/* Open a file. */

#include <syscall.h>
#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "open-normal";

void
test_main (void) 
{
  int handle = open ("sample.txt");
  if (handle < 2)
    fail ("open() returned %d", handle);
}
