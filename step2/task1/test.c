#include "solution.h"

#include <stdio.h>

int main(int argc, char* argv[]) {

  int count = 1;
  int result = stringStat("four", 10, &count);
  printf("count correct? %d\n", count == 2);
  printf("result correct? %d\n", result == 40);

  return 0;
}
