quickSort: quickSort.c sortingSetup.o AlgorithmTester.o IntVector.o
	gcc -g quickSort.c sortingSetup.o AlgorithmTester.o IntVector.o -o quickSort

qsort_midP: qsort_midP.c sortingSetup.o AlgorithmTester.o IntVector.o
	gcc -g qsort_midP.c sortingSetup.o AlgorithmTester.o IntVector.o -o qsort_midP

sortingSetup.o: ../../generics/sortingSetup.c ../../generics/sortingSetup.h 
	gcc -g -c ../../generics/sortingSetup.c 

AlgorithmTester.o: ../../tester/AlgorithmTester.c ../../tester/AlgorithmTester.h
	gcc -g -c ../../tester/AlgorithmTester.c

IntVector.o: ../../utils/IntVector.c ../../utils/IntVector.h
	gcc -g -c ../../utils/IntVector.c

clean:
	rm *.o