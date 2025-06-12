/* Try to remove the root directory.
   This must fail. */

#include <syscall.h>
#include "tests/lib.h"
#include "tests/main.h"

const char *test_name = "dir-rm-root";


void
test_main (void) 
{
  CHECK (!remove ("/"), "remove \"/\" (must fail)");
  CHECK (create ("/a", 243), "create \"/a\"");
}
