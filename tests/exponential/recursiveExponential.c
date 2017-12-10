#include "../../generics/exponential.h"

long exponentialAlgorithm(int base, size_t exponent){

    if(exponent == 0) return 1;

    else if(exponent == 1) return base;

    else if(IS_ODD_NUMBER(exponent))
        return base * exponentialAlgorithm(base, exponent-1);

    else
        return exponentialAlgorithm(base, exponent/2) * exponentialAlgorithm(base, exponent/2);
}

int main(int argc, char **argv){

    exit_if_wrong_args(2);

    int i;
    size_t exponent = strtoul(argv[1], NULL, 10);

    setupExponentialTest(exponent, "recursiveExponential.txt");

    return EXIT_SUCCESS;
}