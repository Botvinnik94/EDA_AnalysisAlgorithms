#include "../../generics/iterativeSorting.h"

#define BUBBLE_SORT iterativeSort


int* BUBBLE_SORT (int* vector, size_t length){
    int* sorted = IntVector_clone(vector, length);
    size_t i, j;
    int temp;

    for (i = 0; i < length; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (sorted[j] > sorted[j + 1]) {
                temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    return sorted;
}

int main(int argc, char** argv){
    
    SETUP_ITERATIVE_SORTING_TEST("results.txt");

    return EXIT_SUCCESS;
}
