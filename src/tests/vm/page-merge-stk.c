#include "tests/main.h"
#include "tests/vm/parallel-merge.h"

const char *test_name = "page-merge-stk";

void
test_main (void) 
{
  parallel_merge ("child-qsort", 72);
}
