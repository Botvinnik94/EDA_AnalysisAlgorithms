#ifndef __ITERATIVE_SORTING_H
#define __ITERATIVE_SORTING_H

#define ALGORITHM_TESTER_CONFIG_DEFAULT_MIN_REPETITIONS 5
#define ALGORITHM_TESTER_CONFIG_DEFAULT_MAX_EXECUTION_TIME 2

#include "../tester/AlgorithmTester.h"
#include "../utils/IntVector.h"

#define TEST_RANGE 10000
#define NUMBER_TESTS 5

#define SETUP_ITERATIVE_SORTING_TEST(filePath)                                                          \
    do{                                                                                         \
        AlgorithmTesterBenchmark* benchmark;                                                    \
        AlgorithmTesterConfig* config;                                                          \
        AlgorithmTester* tester;                                                                \
        FILE* results;                                                                          \
                                                                                                \
        int i;                                                                                  \
        size_t size;                                                                            \
                                                                                                \
        exit_if_wrong_args(2);                                                                  \
                                                                                                \
        size = strtoul(argv[1], NULL, 10);                                                      \
                                                                                                \
        tester = newAlgorithmTester(testAlgorithm);                                             \
        config = newAlgorithmTesterConfig(size,                                                 \
                                        ALGORITHM_TESTER_CONFIG_DEFAULT_MIN_REPETITIONS,        \
                                        ALGORITHM_TESTER_CONFIG_DEFAULT_MAX_EXECUTION_TIME);    \
        results = fopen(filePath,"w");                                                          \
                                                                                                \
        for(i = 0; i < NUMBER_TESTS; i++){                                                      \
            benchmark = AlgorithmTester_test(tester, config, NULL);                             \
            AlgorithmTesterBenchmark_toConsole(benchmark);                                      \
            AlgorithmTesterBenchmark_toStreamDelimited(benchmark, results, ';');                \
            free(benchmark);                                                                    \
                                                                                                \
            config->collection_size += size;                                                    \
        }                                                                                       \
                                                                                                \
        fclose(results);                                                                        \
        free(config);                                                                           \
        free(tester);                                                                           \
    } while(0)

int* iterativeSort(int* vector, size_t length);

void testAlgorithm(size_t length,
                   AlgorithmTesterBenchmark* benchmark,
                   void* data);

#endif