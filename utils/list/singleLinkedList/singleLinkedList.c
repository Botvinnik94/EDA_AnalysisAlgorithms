#include "singleLinkedList.h"

slList_t* new_singleLinkedList() {

    slList_t *List;

    List = malloc(sizeof(slList_t));
    if(List == NULL) return NULL;

    List->first = new_node();
    if(List->first == NULL){
        free(List);
        return NULL;
    }

    List->last = List->first;

    return List;
}

node_t* new_node(){

    node_t *Node;

    Node = malloc(sizeof(node_t));
    if(Node == NULL) return NULL;

    return Node;
}

void insert(type_t val, node_t* pos, slList_t* list){

    node_t* newNode;

    newNode = new_node();
    if(newNode == NULL) return;

    newNode->info = val;
    newNode->next = pos->next;
    pos->next = newNode;
}