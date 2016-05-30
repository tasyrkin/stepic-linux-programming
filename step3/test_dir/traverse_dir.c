#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char*argv[]) {
  
  const char* dir = "/tmp/dir";
  DIR* dir_str = opendir(dir);
  if(dir_str == NULL) {
    printf("Unable to open a directory %s, error: %s\n", dir, strerror(errno));
    exit(1);
  }

  int sleep_secs = 10;
  printf("Sleeping for %d seconds\n", sleep_secs);
  sleep(sleep_secs);
  printf("Woke up!\n");

  struct dirent* entry;
  while(NULL != (entry = readdir(dir_str))) {
    printf("Found: %s\n", entry->d_name);
  }

  int close_result = closedir(dir_str);
  if(close_result != 0) {
    printf("Unable to close directory %s, error: %s\n", dir, strerror(errno));
    exit(1);
  }

  return 0;
}
