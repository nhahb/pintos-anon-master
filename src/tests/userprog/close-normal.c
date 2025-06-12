/* Opens a file and then closes it. */

#include <syscall.h>
#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "close-normal";

void
test_main (void) 
{
  int handle;
  CHECK ((handle = open ("sample.txt")) > 1, "open \"sample.txt\"");
  msg ("close \"sample.txt\"");
  close (handle);
}
