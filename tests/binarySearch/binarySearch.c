#include "../../generics/searchSetup.h"

#define BINARY_SEARCH searchAlgorithm

int BINARY_SEARCH(int* vector, int length, int toFind){
    int floor = 0, ceil = length-1, mid;

    while(floor < ceil){
        mid = (floor + ceil)/2;

        if(vector[mid] < toFind)
            floor = mid+1;
        
        else if(vector[mid] > toFind)
            ceil = mid-1;
        
        else
            return mid;    
    }

    return -1;
}

int main(int argc, char **argv){
    
    exit_if_wrong_args(2);
    size_t size = strtoul(argv[1], NULL, 10);

    setupSearchTest("results.txt", size, 'm');

    return EXIT_SUCCESS;
}