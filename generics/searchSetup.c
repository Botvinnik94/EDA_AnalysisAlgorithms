#include "searchSetup.h"

void setupSearchTest(char * filePath,
                      size_t size,
                      char option)
{
    AlgorithmTesterBenchmark* benchmark;                                                    
    AlgorithmTesterConfig* config;                                                          
    AlgorithmTester* tester;                                                              
    FILE* results;

    int i;
    
    searchElements elements;  

    tester = newAlgorithmTester(&testSearchAlgorithm);
    config = newAlgorithmTesterConfig(size,                                                 
                                      ALGORITHM_TESTER_CONFIG_DEFAULT_MIN_REPETITIONS,        
                                      ALGORITHM_TESTER_CONFIG_DEFAULT_MAX_EXECUTION_TIME);
    results = fopen(filePath,"w");



    for(i = 0; i < NUMBER_TESTS; i++){
        elements.vector = IntVector__generateInRange(config->collection_size, 0, TEST_RANGE);
        qsort(elements.vector, config->collection_size, sizeof(int), cmpIntFunc);
        elements.length = config->collection_size; 

        switch(option){
            case 'b':
                
                break;

            case 'w':
                elements.toFind = elements.vector[elements.length - 1];
                break;
            
            case 'm':
                elements.toFind = IntVector__randomInt(0, TEST_RANGE);
                break;
        }

        benchmark = AlgorithmTester_test(tester, config, &elements);                             
        AlgorithmTesterBenchmark_toConsole(benchmark);                                      
        AlgorithmTesterBenchmark_toStreamDelimited(benchmark, results, ';');  

        free(benchmark);
        free(elements.vector);
                                                                                                                                                                         
        config->collection_size *= 2; 
    }

    fclose(results);
    free(config);
    free(tester);
}

void testSearchAlgorithm(size_t length,
                         AlgorithmTesterBenchmark* benchmark,
                         searchElements* elements)
{
    ALGORITHM_TESTER_TEST(searchAlgorithm(elements->vector, length, elements->toFind), benchmark);
}

int cmpIntFunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}