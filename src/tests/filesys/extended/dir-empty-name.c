/* Tries to create a directory named as the empty string,
   which must return failure. */

#include <syscall.h>
#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "dir-empty-name";


void
test_main (void) 
{
  CHECK (!mkdir (""), "mkdir \"\" (must return false)");
}
