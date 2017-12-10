#include "singleLinkedList.h"
#include <stdio.h>

int main (int argc, char** argv){

    size_t size = strtoul(argv[1], NULL, 10), i;
    const int min = 0;
    const int max = 100000;

    slList_t *List = slList_generateInRange(size, min, max);

    node_t *aux = List->first;
    while(aux->next != NULL){
        aux = aux->next;
        printf("%d\t", aux->info);
    }

    return 0;
}