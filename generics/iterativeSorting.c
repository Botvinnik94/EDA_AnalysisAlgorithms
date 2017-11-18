#include "iterativeSorting.h"

void testRandomVector(size_t length,
                      AlgorithmTesterBenchmark* benchmark,
                      void* data)
{
    int *vector = IntVector__generateInRange(length, 0, TEST_RANGE);
    int *sorted;

    ALGORITHM_TESTER_TEST(sorted = iterativeSort(vector, length), benchmark);

    free(vector);
    free(sorted);
}

void testSortedVector(size_t length,
                      AlgorithmTesterBenchmark* benchmark,
                      void* data)
{
    int *vector = IntVector__generateInRange(length, 0, TEST_RANGE);
    int *sorted;

    qsort(vector, length, sizeof(int), cmpIntFunc);
    ALGORITHM_TESTER_TEST(sorted = iterativeSort(vector, length), benchmark);

    free(vector);
    free(sorted);
}

void testSortedBackwardsVector(size_t length,
                               AlgorithmTesterBenchmark* benchmark,
                               void* data)
{
    int *vector = IntVector__generateInRange(length, 0, TEST_RANGE);
    int *sorted;

    qsort(vector, length, sizeof(int), cmpIntFuncBackwards);
    ALGORITHM_TESTER_TEST(sorted = iterativeSort(vector, length), benchmark);

    free(vector);
    free(sorted);
}

int cmpIntFunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int cmpIntFuncBackwards (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}