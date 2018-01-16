#include "../../generics/searchSetup.h"

#define SEQUENTIAL_SEARCH searchAlgorithm

int SEQUENTIAL_SEARCH(int* vector, int length, int toFind){
    int i;

    for(i = 0; i < length; i++){
        if(vector[i] == toFind)
            return i;
    }

    return -1;
}

int main(int argc, char **argv){
    
    exit_if_wrong_args(2);
    size_t size = strtoul(argv[1], NULL, 10);

    printf("Caso medio:\n");
    setupSearchTest("regular.txt", size, 'm');
    printf("Caso peor:\n");
    setupSearchTest("worst.txt", size, 'w');

    return EXIT_SUCCESS;
}