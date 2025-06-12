/* Try reading a file in the most normal way. */

#include "tests/userprog/sample.inc"
#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "read-normal";


void
test_main (void) 
{
  check_file ("sample.txt", sample, sizeof sample - 1);
}
