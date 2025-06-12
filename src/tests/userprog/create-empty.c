/* Tries to create a file with the empty string as its name. */

#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "create-empty";

void
test_main (void) 
{
  msg ("create(\"\"): %d", create ("", 0));
}
