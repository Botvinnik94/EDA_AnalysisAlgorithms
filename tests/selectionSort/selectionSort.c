#include "../../generics/iterativeSorting.h"

#define SELECTION_SORT iterativeSort

int* SELECTION_SORT(int* vector, size_t length){
    int *sorted = IntVector_clone(vector, length);
    size_t i, j, selection;
    int temp;

    for(i = 0; i < length - 1; i++){
		selection = i;
		for(j = i+1; j < length; j++){
			if(sorted[j] < sorted[selection])
				selection = j;
 		}

		if(selection != i){
            temp = sorted[selection];
            sorted[selection] = sorted[i];
            sorted[i] = temp;
        }			
	}

    return sorted;
}


int main(int argc, char **argv){
    
    SETUP_ITERATIVE_SORTING_TEST("results.txt", testRandomVector);

    return EXIT_SUCCESS;
}