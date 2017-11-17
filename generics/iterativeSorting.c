#include "iterativeSorting.h"

void testAlgorithm(size_t length,
                   AlgorithmTesterBenchmark* benchmark,
                   void* data)
{
    int *vector = IntVector__generateInRange(length, 0, TEST_RANGE);
    int *sorted;

    ALGORITHM_TESTER_TEST(sorted = iterativeSort(vector, length), benchmark);

    free(vector);
    free(sorted);
}