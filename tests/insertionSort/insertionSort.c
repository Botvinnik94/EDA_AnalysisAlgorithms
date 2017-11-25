#include "../../generics/iterativeSorting.h"

#define INSERTION_SORT iterativeSort

void INSERTION_SORT (int* vector, size_t length){
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
}

int main(int argc, char** argv){

    exit_if_wrong_args(2);

    printf("Caso mejor:\n");
    setupIterativeSortingTest("casoMejor.txt", argv, 'b');
    printf("Caso peor:\n");
    setupIterativeSortingTest("casoPeor.txt", argv, 'w');
    printf("Caso medio:\n");
    setupIterativeSortingTest("casoMedio.txt", argv, 'm');

    return EXIT_SUCCESS;
}