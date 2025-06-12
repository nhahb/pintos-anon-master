/* Creates an ordinary empty file. */

#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "create-normal";

void
test_main (void) 
{
  CHECK (create ("quux.dat", 0), "create quux.dat");
}
