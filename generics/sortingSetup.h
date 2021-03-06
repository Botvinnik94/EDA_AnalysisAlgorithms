#ifndef __ITERATIVE_SORTING_H
#define __ITERATIVE_SORTING_H

#define ALGORITHM_TESTER_CONFIG_DEFAULT_MIN_REPETITIONS 5
#define ALGORITHM_TESTER_CONFIG_DEFAULT_MAX_EXECUTION_TIME 2

#include "../tester/AlgorithmTester.h"
#include "../utils/IntVector.h"

#define TEST_RANGE 1000000
#define NUMBER_TESTS 5

#ifndef exit_if_wrong_args                                              
#define exit_if_wrong_args(numberOfArgs)                                       \
    do{                                                                        \
        if(argc != numberOfArgs){                                              \
            printf("Use: %s [collection_size]\n", argv[0]);                    \
            return EXIT_FAILURE;                                               \
        }                                                                      \
    } while(0)                                                                                                                                                  
#endif

/*#define SETUP_ITERATIVE_SORTING_TEST(filePath, testerFunction)                                  \
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
        tester = newAlgorithmTester(testerFunction);                                            \
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
    } while(0)*/

void sortAlgorithm(int* vector, size_t length);

void setupSortingTest(char * filePath,
                      size_t size,
                      char option);

void testSortAlgorithm(size_t length,
                   AlgorithmTesterBenchmark* benchmark,
                   int* vector);

/*void testSortedVector(size_t length,
                      AlgorithmTesterBenchmark* benchmark,
                      void* data);

void testSortedBackwardsVector(size_t length,
                               AlgorithmTesterBenchmark* benchmark,
                               void* data);*/

int cmpIntFunc (const void * a, const void * b);
int cmpIntFuncBackwards (const void * a, const void * b);
void swap(int *a, int *b);            

#endif