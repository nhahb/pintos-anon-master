/* Accesses a bad address.
   The process must be terminated with -1 exit code. */

#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "pt-bad-addr";

void
test_main (void)
{
  fail ("bad addr read as %d", *(int *) 0x04000000);
}
