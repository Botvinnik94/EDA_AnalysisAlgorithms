#ifndef __EXPONENTIAL_H
#define __EXPONENTIAL_H

#define ALGORITHM_TESTER_CONFIG_DEFAULT_MIN_REPETITIONS 5
#define ALGORITHM_TESTER_CONFIG_DEFAULT_MAX_EXECUTION_TIME 2

#include "../tester/AlgorithmTester.h"

#define BASE 2
#define NUMBER_TESTS 5

#define IS_ODD_NUMBER(num)  (num%2 != 0)
#define IS_EVEN_NUMBER(num) (num%2 == 0)

#ifndef exit_if_wrong_args                                              
#define exit_if_wrong_args(numberOfArgs)                                       \
    do{                                                                        \
        if(argc != numberOfArgs){                                              \
            printf("Use: %s [exponent]\n", argv[0]);                           \
            return EXIT_FAILURE;                                               \
        }                                                                      \
    } while(0)                                                                                                                                                  
#endif

void testExpAlgorithm(size_t exponent,
                      AlgorithmTesterBenchmark* benchmark,
                      void* data);

long exponentialAlgorithm(int base, size_t exponent);

void setupExponentialTest(size_t exponent, char* filePath);

#endif
