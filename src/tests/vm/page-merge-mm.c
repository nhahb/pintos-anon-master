#include "tests/main.h"
#include "tests/vm/parallel-merge.h"

const char *test_name = "page-merge-mm ";


void
test_main (void) 
{
  parallel_merge ("child-qsort-mm", 80);
}
