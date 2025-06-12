#include "tests/main.h"
#include "tests/vm/parallel-merge.h"

const char *test_name = "page-merge-par";


void
test_main (void) 
{
  parallel_merge ("child-sort", 123);
}
