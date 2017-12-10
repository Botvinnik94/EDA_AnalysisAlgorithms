#include "./exponential.h"

void setupExponentialTest(size_t exponent, char* filePath){
    int i;

    AlgorithmTesterBenchmark* benchmark;                                                    
    AlgorithmTesterConfig* config;                                                          
    AlgorithmTester* tester;                                                              
    FILE* results;

    tester = newAlgorithmTester(&testExpAlgorithm);
    config = newAlgorithmTesterConfig(exponent, 5, 2);
    results = fopen(filePath,"w");

    for(i = 0; i < NUMBER_TESTS; i++){
        benchmark = AlgorithmTester_test(tester, config, NULL);
        AlgorithmTesterBenchmark_toConsole(benchmark);                                      
        AlgorithmTesterBenchmark_toStreamDelimited(benchmark, results, ';');

        config->collection_size += exponent;
    }

    fclose(results);
}

void testExpAlgorithm(size_t exponent,
                      AlgorithmTesterBenchmark* benchmark,
                      void* data)
{
    ALGORITHM_TESTER_TEST(exponentialAlgorithm(BASE, exponent), benchmark);
}