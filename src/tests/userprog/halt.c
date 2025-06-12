/* Tests the halt system call. */

#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "halt";

void
test_main (void) 
{
  halt ();
  fail ("should have halted");
}
