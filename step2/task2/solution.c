#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

struct dl_data {
  void* handle;
  int (*f)(int);
};

void close_library(struct dl_data* lib_data){
  if(NULL != lib_data){
    if(NULL != lib_data->handle) {
      dlclose(lib_data->handle);
    }
    free(lib_data);
  }
}

struct dl_data* init_library(const char* lib_name, const char* funct_name) {

  struct dl_data* lib_data = (struct dl_data*)malloc(sizeof(struct dl_data));
  if(NULL == lib_data) {
    return NULL;
  }

  lib_data->handle = dlopen(lib_name, RTLD_LAZY);
  if(NULL == lib_data->handle) {
    printf("Unable to initialize library [%s]: %s\n", lib_name, dlerror());
    close_library(lib_data);
    return NULL;
  }

  lib_data->f = (int (*)(int))dlsym(lib_data->handle, funct_name);
  if(NULL == lib_data->f) {
    printf("Unable to extract method [%s], because of  [%s]\n", funct_name, dlerror());
    close_library(lib_data);
    return NULL;
  }
  return lib_data;
}

int main(int argc, char**argv){

  if(argc != 4) {
    printf("%s <libName> <functName> <argument>\n", argv[0]);
    return 1;
  }  

  const char* lib_name = argv[1];
  const char* funct_name = argv[2];
  int funct_arg = atoi(argv[3]);

  struct dl_data* handle = init_library(lib_name, funct_name);

  if(NULL == handle) {
    printf("Unable to initialize library [%s] and its method [%s], exiting...\n", lib_name, funct_name);
    close_library(handle);
    return 1;
  }

  int funct_result = handle->f(funct_arg);
  printf("%d\n", funct_result);

  close_library(handle);
  return 0;
}
