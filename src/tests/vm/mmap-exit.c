/* Executes child-mm-wrt and verifies that the writes that should
   have occurred really did. */

#include <syscall.h>
#include "tests/vm/sample.inc"
#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "mmap-exit";

void
test_main (void)
{
  pid_t child;

  /* Make child write file. */
  quiet = true;
  CHECK ((child = exec ("child-mm-wrt")) != -1, "exec \"child-mm-wrt\"");
  CHECK (wait (child) == 0, "wait for child (should return 0)");
  quiet = false;

  /* Check file contents. */
  check_file ("sample.txt", sample, sizeof sample);
}
