#include "../../generics/sortingSetup.h"

#define SELECTION_SORT sortAlgorithm

void SELECTION_SORT(int* vector, size_t length){
    size_t i, j, selection;
    int temp;

    for(i = 0; i < length - 1; i++){
		selection = i;
		for(j = i+1; j < length; j++){
			if(vector[j] < vector[selection])
				selection = j;
 		}

		if(selection != i){
            temp = vector[selection];
            vector[selection] = vector[i];
            vector[i] = temp;
        }			
	}
}


int main(int argc, char **argv){
    
    exit_if_wrong_args(2);
    size_t size = strtoul(argv[1], NULL, 10);

    setupSortingTest("results.txt", size, 'm');

    return EXIT_SUCCESS;
}