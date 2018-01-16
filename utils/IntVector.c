#include "IntVector.h"
/**
 * Allocate a new int vector
 * @param size_t length
 *
 * @return IntVector
 */
IntVector newIntVector(size_t length) {
    IntVector ret;

    ret = (IntVector)malloc(length * sizeof(int));

    // return_null_if(ret == NULL);

    return ret;
}

/**
 * Create a vector of `length` elements between `min` and `max`
 *
 * @param size_t length
 * @param int min
 * @param int max
 *
 * @return IntVector
 */
IntVector IntVector__generateInRange(size_t length, int min, int max) {
    IntVector ret = newIntVector(length);
    size_t i = 0;

    // return_null_if(range < 0);

    for (; i < length; i++) {
        ret[i] = IntVector__randomInt(min, max);
    }

    return ret;
}

/**
 * Returns a random integer.
 *
 */
int IntVector__randomInt(int min, int max){
    int range = max - min;

    srand(time(NULL));
    return (min + (rand() % range));
}

/**
 * Clone an int vector
 *
 * @param IntVector vector
 * @param size_t length
 *
 * @return IntVector
 */
IntVector IntVector_clone(IntVector vector, size_t length) {
    IntVector ret = newIntVector(length);

    memcpy(ret, vector, length * sizeof(int));

    return ret;
}
