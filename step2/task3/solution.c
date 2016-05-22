#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

extern int optind, opterr, optopt;
extern char* optarg;

int main(int argc, char*argv[]){

  int opt;
  //switch off the error messages
  opterr = 0;

  bool met_invalid_option = false; 

  while(-1 != (opt = getopt(argc, argv, "q:iv")) && !met_invalid_option){
    switch (opt) {
      case 'q':
        printf("Encountered 'q'\n");
        printf("q's arg = %s\n", optarg);
        break;
      case 'i':
        printf("Encountered 'i'\n");
        break;
      case 'v':
        printf("Encountered 'v'\n");
        break;
      default:
        printf("optopt=%d\n", optopt);
        met_invalid_option = true;
    }
  }

  const char* result = met_invalid_option ? "-" : "+";

  printf("%s\n", result);

  return 0;
}
