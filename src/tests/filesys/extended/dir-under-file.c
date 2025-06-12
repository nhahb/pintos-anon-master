/* Tries to create a directory with the same name as an existing
   file, which must return failure. */

#include <syscall.h>
#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "dir-under-file";


void
test_main (void) 
{
  CHECK (create ("abc", 0), "create \"abc\"");
  CHECK (!mkdir ("abc"), "mkdir \"abc\" (must return false)");
}
