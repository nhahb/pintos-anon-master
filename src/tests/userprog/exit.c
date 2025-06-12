/* Tests the exit system call. */

#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "exit";

void
test_main (void) 
{
  exit (57);
  fail ("should have called exit(57)");
}
