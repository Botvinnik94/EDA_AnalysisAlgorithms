mergeSort: mergeSort.c sortingSetup.o AlgorithmTester.o IntVector.o
	gcc -g mergeSort.c sortingSetup.o AlgorithmTester.o IntVector.o -o mergeSort

sortingSetup.o: ../../generics/sortingSetup.c ../../generics/sortingSetup.h 
	gcc -g -c ../../generics/sortingSetup.c 

AlgorithmTester.o: ../../tester/AlgorithmTester.c ../../tester/AlgorithmTester.h
	gcc -g -c ../../tester/AlgorithmTester.c

IntVector.o: ../../utils/IntVector.c ../../utils/IntVector.h
	gcc -g -c ../../utils/IntVector.c

clean:
	rm *.o