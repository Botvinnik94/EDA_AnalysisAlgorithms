#include "../../generics/iterativeSorting.h"

#define QUICK_SORT iterativeSort

size_t place(int* vector, size_t length){
    size_t i, indexPivot;
    int pivotNow;

    pivotNow = 0;
    indexPivot = 0;
    for(i = 1; i < length; i++){
        if(vector[pivotNow] > vector[i]){
            indexPivot++;
            swap(&vector[i], &vector[indexPivot]);
        }
    }
    swap(&vector[pivotNow], &vector[indexPivot]);
    return indexPivot;
}

void QUICK_SORT (int* vector, size_t length){
    if(length > 0){
        size_t indexPivot = place(vector, length);
        QUICK_SORT (vector + indexPivot + 1, length - indexPivot - 1);
        QUICK_SORT (vector, length - (length-indexPivot-1) - 1);
    }
}

int main(int argc, char** argv){

    exit_if_wrong_args(2);
    size_t size = strtoul(argv[1], NULL, 10);

    printf("Caso peor:\n");
    setupIterativeSortingTest("casoPeor.txt", size, 'b');
    printf("Caso medio:\n");
    setupIterativeSortingTest("casoMedio.txt", size, 'm');

    return EXIT_SUCCESS;
}


