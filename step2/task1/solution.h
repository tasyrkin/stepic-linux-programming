#ifndef __SOLUTION__
#define __SOLUTION__

//extern "C" tells the C++ compiler to have "C" linkage, the compiler does not mangle the name
#ifdef __cplusplus
extern "C" 
#endif
int stringStat(const char *string, int multiplier, int *count);

#endif //__SOLUTION__
