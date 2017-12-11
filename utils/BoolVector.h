#ifndef __BOOL_VECTOR_H
#define __BOOL_VECTOR_H

#include<stdlib.h>

#define TRUE 1
#define FALSE 0
typedef short boolean;

boolean* new_boolVector(size_t n);

boolean* BoolVector_clone(boolean* vector, size_t length);

#endif
