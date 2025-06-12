/* Tests argument passing to child processes. */

#include <syscall.h>
#include "tests/main.h"

const char *test_name = "exec-arg";

void
test_main (void) 
{
  wait (exec ("child-args childarg"));
}
