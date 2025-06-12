/* Executes and waits for a single child process. */

#include <syscall.h>
#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "exec-once";

void
test_main (void) 
{
  wait (exec ("child-simple"));
}
