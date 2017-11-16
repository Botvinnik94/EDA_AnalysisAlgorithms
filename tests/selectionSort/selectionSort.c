#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALGORITHM_TESTER_CONFIG_DEFAULT_MIN_REPETITIONS 5
#define ALGORITHM_TESTER_CONFIG_DEFAULT_MAX_EXECUTION_TIME 2

#include "../../tester/AlgorithmTester.h"
#include "../../utils/IntVector.h"

// Quick compilation
#include "../../tester/AlgorithmTester.c"
#include "../../utils/IntVector.c"

#define TEST_RANGE 10000
#define NUMBER_TESTS 5

int* selectionSort(int* vector, size_t length){
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

void testSelectionSort(size_t length,
                       AlgorithmTesterBenchmark* benchmark,
                       void *data)
{
    int *vector = IntVector__generateInRange(length, 0, TEST_RANGE);
    int *sorted;

    ALGORITHM_TESTER_TEST(sorted = selectionSort(vector, length), benchmark);

    free(vector);
    free(sorted);
}

int main(int argc, char **argv){
    AlgorithmTester* tester;
    AlgorithmTesterBenchmark* benchmark;
    AlgorithmTesterConfig* config;
    FILE* results;

    int i;
    size_t size;

    if(argc != 2){
        printf("Use: %s [collection_size]\n", argv[0]);
        return EXIT_FAILURE;
    }

    size = strtoul(argv[1], NULL, 10);

    tester = newAlgorithmTester(testSelectionSort);
    config = newAlgorithmTesterConfig(size,
                                      ALGORITHM_TESTER_CONFIG_DEFAULT_MIN_REPETITIONS,
                                      ALGORITHM_TESTER_CONFIG_DEFAULT_MAX_EXECUTION_TIME);
    results = fopen("results.txt", "w");

    for(i = 0; i < NUMBER_TESTS; i++){
        benchmark = AlgorithmTester_test(tester, config, NULL);
        AlgorithmTesterBenchmark_toConsole(benchmark);
        AlgorithmTesterBenchmark_toStreamDelimited(benchmark, results, ';');
        free(benchmark);

        config->collection_size += size;
    }

    fclose(results);
    free(config);
    free(tester);

    return EXIT_SUCCESS;
}