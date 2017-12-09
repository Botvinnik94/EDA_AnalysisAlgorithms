#include "../../generics/sortingSetup.h"

#define QUICK_SORT sortAlgorithm

void QUICK_SORT (int *vector, size_t length){

    size_t pivot = length/2;
    int pivotValue = vector[pivot];
    size_t i = 0, j = length-1;

    do{
        while(vector[i] < pivotValue) i++;
        while(vector[j] > pivotValue) j--;

        if(i <= j) swap(&vector[i++], &vector[j--]);
    } while(j >= i);

    if(j > 0)         QUICK_SORT(vector, j+1);
    if(i < length-1)  QUICK_SORT(vector + i, length-i);
}

int main(int argc, char** argv){

    exit_if_wrong_args(2);
    size_t size = strtoul(argv[1], NULL, 10);

    printf("Vector ordenado:\n");
    setupSortingTest("qsort_midP_order.txt", size, 'b');
    printf("Vector ordenado al reves:\n");
    setupSortingTest("qsort_midP_orderBackwards.txt", size, 'w');
    printf("Caso medio:\n");
    setupSortingTest("qsort_midP_standard.txt", size, 'm');

    return EXIT_SUCCESS;
}