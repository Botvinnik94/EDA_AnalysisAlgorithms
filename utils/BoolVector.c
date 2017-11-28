#include "BoolVector.h"


boolean* new_boolVector(size_t n){

	boolean* newVector;	
	newVector = calloc(n, sizeof(boolean));

	return newVector;
}
