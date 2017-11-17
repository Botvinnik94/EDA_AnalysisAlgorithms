# EDA_AnalysisAlgorithms

This is a trial of an interface for getting empirical results by analyzing algorithms as done in the practice classes in the subject "Estructuras de datos y algoritmos (EDA)" (Data structures and algorithms) in the University of Salamanca as part of the Computer Science and Engineering program.

I'm doing this thanks to the amazing work done by another fellow student @emilio, he built a generic engine for the analysis we do in this subject. 

The goal here is to simply write the algorithm to analyse on C, save it in a folder inside tests/ and then just call some generic function or macro to get the results. I'm doing this by wrapping the similar types of algorithms in a generic file that comunicates with the analysis engine and some auxiliary functions (for instance, iterativeSorting.c is a generic for bubbleSort, selectionSort and insertionSort). It is also possible to call directly for the analysis without the wrapping but I want to make as many generics as possible to reduce the redundancy to a minumum.
