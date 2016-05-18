#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

struct dl_data {
  void* handle;
  void (*hello_message)(const char*);
};


void close_library(struct dl_data* lib_data){
  if(NULL != lib_data){
    if(NULL != lib_data->handle) {
      dlclose(lib_data->handle);
    }
    free(lib_data);
  }
}

struct dl_data* init_library() {

  struct dl_data* lib_data = (struct dl_data*)malloc(sizeof(struct dl_data));
  if(NULL == lib_data) {
    return NULL;
  }

  lib_data->handle = dlopen("./libHello.so", RTLD_LAZY);
  if(NULL == lib_data->handle) {
    printf("Unable to initialize library: %s\n", dlerror());
    close_library(lib_data);
    return NULL;
  }

  lib_data->hello_message = (void (*)(const char*))dlsym(lib_data->handle, "hello_message");
  if(NULL == lib_data->hello_message) {
    printf("Unable to extract 'hello_message' method: %s\n", dlerror());
    close_library(lib_data);
    return NULL;
  }
  return lib_data;
}

int main(){

  struct dl_data* handle = init_library();

  if(NULL == handle) {
    printf("Unable to initialize hello_message, exiting...\n");
    close_library(handle);
    return 1;
  }

  handle->hello_message("Peter");

  close_library(handle);
  return 0;
}
