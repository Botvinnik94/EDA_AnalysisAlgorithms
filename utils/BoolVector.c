#include "BoolVector.h"


boolean* new_boolVector(size_t n){

	boolean* newVector;	
	newVector = calloc(n, sizeof(boolean));

	return newVector;
}

boolean* BoolVector_clone(boolean* vector, size_t length) {
    boolean* ret = newIntVector(length);

    memcpy(ret, vector, length * sizeof(boolean));

    return ret;
}
