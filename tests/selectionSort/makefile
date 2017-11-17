
selectionSort: selectionSort.c iterativeSorting.o AlgorithmTester.o IntVector.o
	gcc -g selectionSort.c iterativeSorting.o AlgorithmTester.o IntVector.o -o selectionSort

iterativeSorting.o: ../../generics/iterativeSorting.c ../../generics/iterativeSorting.h 
	gcc -g -c ../../generics/iterativeSorting.c 

AlgorithmTester.o: ../../tester/AlgorithmTester.c ../../tester/AlgorithmTester.h
	gcc -g -c ../../tester/AlgorithmTester.c

IntVector.o: ../../utils/IntVector.c ../../utils/IntVector.h
	gcc -g -c ../../utils/IntVector.c

clean:
	rm *.o