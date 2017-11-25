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
    size_t size = strtoul(argv[1], NULL, 10);

    printf("Caso mejor:\n");
    setupIterativeSortingTest("casoMejor.txt", size, 'b');
    printf("Caso peor:\n");
    setupIterativeSortingTest("casoPeor.txt", size, 'w');
    printf("Caso medio:\n");
    setupIterativeSortingTest("casoMedio.txt", size, 'm');

    return EXIT_SUCCESS;
}