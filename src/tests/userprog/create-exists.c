/* Verifies that trying to create a file under a name that
   already exists will fail. */

#include <syscall.h>
#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "create-exists";

void
test_main (void) 
{
  CHECK (create ("quux.dat", 0), "create quux.dat");
  CHECK (create ("warble.dat", 0), "create warble.dat");
  CHECK (!create ("quux.dat", 0), "try to re-create quux.dat");
  CHECK (create ("baffle.dat", 0), "create baffle.dat");
  CHECK (!create ("warble.dat", 0), "try to re-create quux.dat");
}
