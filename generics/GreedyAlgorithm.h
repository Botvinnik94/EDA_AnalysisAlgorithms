#ifndef __GREEDY_ALGORITHM_H
#define __GREEDY_ALGORITHM_H

#define ALGORITHM_TESTER_CONFIG_DEFAULT_COLLECTION_SIZE 0
#define ALGORITHM_TESTER_CONFIG_DEFAULT_MIN_REPETITIONS 5
#define ALGORITHM_TESTER_CONFIG_DEFAULT_MAX_EXECUTION_TIME 2

#include "../tester/AlgorithmTester.h"

typedef struct dataGreedy{
    void*** candidatesSet;  //<- Bidimentional array for the candidates set, every row is a 
                            //   different set of one attribute for every candidate.
    void ** solutionSet;    //<- Unidimentional array for the solution set.                        
    size_t length;          //<- @length: number of canditates. 
    size_t numValues;       //<- @numValues: number of attributes for each candidate.
    void* dataEnd;          //<- @dataEnd: condition for finishing the greedy algorithm.
    size_t indexDataEnd;    //<- @indexDataEnd: index row in the bidimentional array to 
                            //   know the condition attribute.
} dataGreedy;

void setupGreedyAlgorithmTest(char * pathFichero);

void testGreedyAlgorithm(size_t length, 
                         AlgorithmTesterBenchmark* benchmark,
                         dataGreedy* data);

void greedyAlgorithm(dataGreedy* data);

#endif