/* Passes a bad pointer to the create system call,
   which must cause the process to be terminated with exit code
   -1. */

#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "create-bad-ptr";

void
test_main (void) 
{
  msg ("create(0x20101234): %d", create ((char *) 0x20101234, 0));
}
