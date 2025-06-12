/* Tries to execute a nonexistent process.
   The exec system call must return -1. */

#include <syscall.h>
#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "exec-missing";

void
test_main (void) 
{
  msg ("exec(\"no-such-file\"): %d", exec ("no-such-file"));
}
