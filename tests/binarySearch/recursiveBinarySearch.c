#include "../../generics/searchSetup.h"

#define RECURSIVE_BINARY_SEARCH searchAlgorithm

int RECURSIVE_BINARY_SEARCH(int* vector, int length, int toFind){
    
    if(length < 1)
        return -1;
    
    int floor = 0, ceil = length-1;
    int mid = ceil/2;

    if(vector[mid] < toFind)
        return RECURSIVE_BINARY_SEARCH(vector+mid+1, mid, toFind);
    else if(vector[mid] > toFind)
        return RECURSIVE_BINARY_SEARCH(vector+mid-1, mid, toFind);
    else
        return mid;   
    
}

int main(int argc, char **argv){
    
    exit_if_wrong_args(2);
    size_t size = strtoul(argv[1], NULL, 10);

    setupSearchTest("results.txt", size, 'm');

    return EXIT_SUCCESS;
}