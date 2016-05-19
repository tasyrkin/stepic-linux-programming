#ifndef __HELLO__
#define __HELLO__

//extern "C" tells the C++ compiler to have "C" linkage, the compiler does not mangle the name
#ifdef __cplusplus
extern "C" 
#endif
void hello_message(const char* name);

#endif //__HELLO__
