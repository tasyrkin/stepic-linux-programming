#include <string.h>

int stringStat(const char *string, int multiplier, int *count) {

  if(NULL != count){
    *count += 1;
  }

  int len = NULL == string ? 0 : strlen(string);
  return multiplier * len;
}
