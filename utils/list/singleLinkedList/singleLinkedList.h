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

SList_t* slList_generateInRange(size_t size, type_t min, type_t max);

SList_t* new_singleLinkedList();

node_t* new_node();

void insert(type_t val, node_t* pos, SList_t* list);

node_t* seek(type_t val, SList_t* list);

void remove_pos(node_t* pos, SList_t* list);

void clear(SList_t* list);

#endif