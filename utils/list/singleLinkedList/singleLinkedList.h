#ifndef __SINGLE_LINKED_LIST
#define __SINGLE_LINKED_LIST

#include "../list.h"

typedef struct node node_t;

struct node{
    type_t info;
    node_t* next; 
};

typedef struct slList {
    node_t* first;
    node_t* last;
} slList_t;

slList_t* new_singleLinkedList();

node_t* new_node();

#endif