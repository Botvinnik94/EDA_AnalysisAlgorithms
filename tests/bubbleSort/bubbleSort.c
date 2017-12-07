#include "../../generics/sortingSetup.h"

#define BUBBLE_SORT sortAlgorithm


void BUBBLE_SORT (int* vector, size_t length){
    size_t i, j;
    int temp;

    for (i = 0; i < length; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char** argv){
    
    exit_if_wrong_args(2);
    size_t size = strtoul(argv[1], NULL, 10);

    setupSortingTest("results.txt", size, 'm');

    return EXIT_SUCCESS;
}
