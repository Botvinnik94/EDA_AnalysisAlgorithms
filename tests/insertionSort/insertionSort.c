#include "../../generics/iterativeSorting.h"

#define INSERTION_SORT iterativeSort

int* INSERTION_SORT (int* vector, size_t length){
    int *sorted = IntVector_clone(vector, length);
    size_t i, j;
    int temp;

	for(i = 1; i < length; i++){
		temp = vector[i];
		j = i-1;
		while(j >= 0 && vector[j] > temp){
			vector[j+1] = vector[j];
			j--;		
		}
		vector[j+1] = temp;
	}

    return sorted;
}

int main(int argc, char** argv){

    printf("Caso mejor:\n");
    SETUP_ITERATIVE_SORTING_TEST("casoMejor.txt", testSortedVector);
    printf("Caso peor:\n");
    SETUP_ITERATIVE_SORTING_TEST("casoPeor.txt", testSortedBackwardsVector);
    printf("Caso medio:\n");
    SETUP_ITERATIVE_SORTING_TEST("casoMedio.txt", testRandomVector);

    return EXIT_SUCCESS;
}