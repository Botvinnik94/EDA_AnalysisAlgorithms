#ifndef __SEARCH_SETUP_H
#define __SEARCH_SETUP_H

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

typedef struct {
    int* vector;
    int length;
    int toFind;
} searchElements;

int searchAlgorithm(int* vector, int length, int toFind);

void setupSearchTest(char * filePath,
                     size_t size,
                     char option);

void testSearchAlgorithm(size_t length,
                   AlgorithmTesterBenchmark* benchmark,
                   searchElements* elements);

int cmpIntFunc (const void * a, const void * b);

#endif