#include "../../generics/sortingSetup.h"

#define MERGE_SORT sortAlgorithm

void merge(int* vector_A, size_t length_A, int* vector_B, size_t length_B){
    size_t indexA = 0, indexB = 0, indexT = 0;
    
    int* vector_T = vector_A;
    size_t length_T = length_A + length_B;

    int* tempA = IntVector_clone(vector_A, length_A);
    int* tempB = IntVector_clone(vector_B, length_B);

    while(indexA < length_A && indexB < length_B){
        if(tempA[indexA] < tempB[indexB])
            vector_T[indexT] = tempA[indexA++];
        else
            vector_T[indexT] = tempB[indexB++];
        
        indexT++;
    }

    if(indexA >= length_A){
        while(indexT < length_T)
            vector_T[indexT++] = tempB[indexB++];
    }
    else{
        while(indexT < length_T)
            vector_T[indexT++] = tempA[indexA++];
    }

    free(tempA);
    free(tempB);
}


void MERGE_SORT (int * vector, size_t length){
    if(length > 1){
        size_t length_A = length/2;
        size_t length_B = length_A + (length%2);
        int *vector_A = vector;
        int *vector_B = vector + length_A;

        MERGE_SORT(vector_A, length_A);
        MERGE_SORT(vector_B, length_B);
        merge(vector_A, length_A, vector_B, length_B);
    }
}

int main(int argc, char** argv){

    exit_if_wrong_args(2);
    size_t size = strtoul(argv[1], NULL, 10);

    setupSortingTest("results.txt", size, 'm');

    return EXIT_SUCCESS;
}