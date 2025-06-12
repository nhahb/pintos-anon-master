/* This program attempts to execute code at a kernel virtual address. 
   This should terminate the process with a -1 exit code. */

#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "bad-jump2";

void
test_main (void) 
{
  msg ("Congratulations - you have successfully called kernel code: %d", 
        ((int (*)(void))0xC0000000)());
  fail ("should have exited with -1");
}
