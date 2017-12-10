#ifndef __SINGLE_LINKED_LIST_H
#define __SINGLE_LINKED_LIST_H

#include "../../../tester/AlgorithmTester.h"

#define return_if_null(exp)     if((exp) == NULL) return NULL;

typedef int type_t;
typedef struct node node_t;

struct node{
    type_t info;
    node_t* next; 
};

typedef struct slList {
    node_t* first;
    node_t* last;
} SList_t;

SList_t* SList_generateInRange(size_t size, type_t min, type_t max);

SList_t* SList_new_singleLinkedList();

node_t* SList_new_node();

void SList_insert(type_t val, node_t* pos, SList_t* list);

node_t* SList_seek(type_t val, SList_t* list);

void SList_remove(node_t* pos, SList_t* list);

void SList_clear(SList_t* list);

#endif