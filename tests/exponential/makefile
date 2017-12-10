iterativeExponential: iterativeExponential.c exponential.o AlgorithmTester.o
	gcc -g iterativeExponential.c AlgorithmTester.o -o iterativeExponential

recursiveExponential: recursiveExponential.c exponential.o AlgorithmTester.o
	gcc -g recursiveExponential.c AlgorithmTester.o -o recursiveExponential

exponential.o: ../../generics/exponential.c ../../generics/exponential.h
	gcc -g -c ../../generics/exponential.c

AlgorithmTester.o: ../../tester/AlgorithmTester.c ../../tester/AlgorithmTester.h
	gcc -g -c ../../tester/AlgorithmTester.c

clean:
	rm *.o