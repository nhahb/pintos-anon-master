/* Wait for a subprocess to finish. */

#include <syscall.h>
#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "wait-simple";


void
test_main (void) 
{
  msg ("wait(exec()) = %d", wait (exec ("child-simple")));
}
