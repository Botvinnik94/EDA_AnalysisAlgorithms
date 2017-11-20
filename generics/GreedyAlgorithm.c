#include "GreedyAlgorithm.h"

void testGreedyAlgorithm(size_t length, 
                         AlgorithmTesterBenchmark* benchmark,
                         dataGreedy* data)
{
    ALGORITHM_TESTER_TEST(greedyAlgorithm(data), benchmark);
    free(data->solutionSet);
}

void setupGreedyAlgorithmTest(char * filePath, dataGreedy* data){
    AlgorithmTesterBenchmark* benchmark;                                                  
    AlgorithmTesterConfig* config;                                                        
    AlgorithmTester* tester;                                                              
    FILE* results;

    tester = newAlgorithmTester(testGreedyAlgorithm);
    config = AlgorithmTesterConfig__default();

    results = fopen(filePath,"w"); 

    benchmark = AlgorithmTester_test(tester, config, data);                             
    AlgorithmTesterBenchmark_toConsole(benchmark);                                      
    AlgorithmTesterBenchmark_toStreamDelimited(benchmark, results, ';');     
   
    fclose(results);  
    free(benchmark);                                                                      
    free(config);                                                                           
    free(tester);
}