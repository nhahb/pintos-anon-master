/* Wait for a process that will be killed for bad behavior. */

#include <syscall.h>
#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "wait-kill";


void
test_main (void) 
{
  msg ("wait(exec()) = %d", wait (exec ("child-bad")));
}
