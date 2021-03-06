#include "sortingSetup.h"

void setupSortingTest(char * filePath,
                      size_t size,
                      char option)
{
    AlgorithmTesterBenchmark* benchmark;                                                    
    AlgorithmTesterConfig* config;                                                          
    AlgorithmTester* tester;                                                              
    FILE* results;

    int i;
    int *unsortedVector, *sortedVector, *sortedBackwardsVector;
    int *vectorToTest;

    tester = newAlgorithmTester(&testSortAlgorithm);
    config = newAlgorithmTesterConfig(size,                                                 
                                      ALGORITHM_TESTER_CONFIG_DEFAULT_MIN_REPETITIONS,        
                                      ALGORITHM_TESTER_CONFIG_DEFAULT_MAX_EXECUTION_TIME);
    results = fopen(filePath,"w");

    for(i = 0; i < NUMBER_TESTS; i++){
        unsortedVector = IntVector__generateInRange(config->collection_size, 0, TEST_RANGE);
        sortedVector = IntVector_clone(unsortedVector, config->collection_size);
        qsort(sortedVector, config->collection_size, sizeof(int), cmpIntFunc);
        sortedBackwardsVector = IntVector_clone(unsortedVector, config->collection_size);
        qsort(sortedBackwardsVector, config->collection_size, sizeof(int), cmpIntFuncBackwards);
        
        switch(option){
            case 'b':
                vectorToTest = sortedVector;
                break;

            case 'w':
                vectorToTest = sortedBackwardsVector;
                break;
            
            case 'm':
                vectorToTest = unsortedVector;
                break;
        }

        benchmark = AlgorithmTester_test(tester, config, vectorToTest);                             
        AlgorithmTesterBenchmark_toConsole(benchmark);                                      
        AlgorithmTesterBenchmark_toStreamDelimited(benchmark, results, ';');  

        free(benchmark);  
        free(unsortedVector);
        free(sortedVector);
        free(sortedBackwardsVector);                                                                  
                                                                                                
        config->collection_size += size; 
    }

    fclose(results);
    free(config);
    free(tester);
}

void testSortAlgorithm(size_t length,
                       AlgorithmTesterBenchmark* benchmark,
                       int* vector)
{
    int *sorted = IntVector_clone(vector, length);

    ALGORITHM_TESTER_TEST(sortAlgorithm(sorted, length), benchmark);
    free(sorted);
}

int cmpIntFunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int cmpIntFuncBackwards (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}