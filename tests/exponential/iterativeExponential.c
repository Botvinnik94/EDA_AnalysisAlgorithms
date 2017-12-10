#include "../../generics/exponential.h"

long exponentialAlgorithm(int base, size_t exponent){
    size_t i;
    long result = 1;

    for(i = 0; i < exponent; i++) result *= base;

    return result;
}

int main(int argc, char** argv){

    exit_if_wrong_args(2);

    int i;
    size_t exponent = strtoul(argv[1], NULL, 10);

    setupExponentialTest(exponent, "iterativeExponential.txt");

    return EXIT_SUCCESS;
}

