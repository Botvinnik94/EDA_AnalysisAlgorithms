sequentialSearch: sequentialSearch.c searchSetup.o AlgorithmTester.o IntVector.o
	gcc -g sequentialSearch.c searchSetup.o AlgorithmTester.o IntVector.o -o sequentialSearch

searchSetup.o: ../../generics/searchSetup.c ../../generics/searchSetup.h 
	gcc -g -c ../../generics/searchSetup.c 

AlgorithmTester.o: ../../tester/AlgorithmTester.c ../../tester/AlgorithmTester.h
	gcc -g -c ../../tester/AlgorithmTester.c

IntVector.o: ../../utils/IntVector.c ../../utils/IntVector.h
	gcc -g -c ../../utils/IntVector.c

clean:
	rm *.o