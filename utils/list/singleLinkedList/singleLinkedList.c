#include "singleLinkedList.h"

node_t* new_node(){

    node_t *Node;

    Node = malloc(sizeof(node_t));
    return_if_null(Node);

    return Node;
}

SList_t* new_singleLinkedList() {

    SList_t *List;

    List = malloc(sizeof(SList_t));
    return_if_null(List);

    List->first = new_node();
    if(List->first == NULL){
        free(List);
        return NULL;
    }

    List->last = List->first;

    return List;
}

SList_t* slList_generateInRange(size_t size, type_t min, type_t max){
    SList_t* List = new_singleLinkedList();
    return_if_null(List);

    size_t i;

    srand(time(NULL));
    for(i = 0; i < size; i++){
        type_t val = min + (rand() % (max - min));
        insert(val, List->last, List);
    }

    return List;
}

void insert(type_t val, node_t* pos, SList_t* list){

    //TODO: error and nullPointer checking

    node_t* newNode = new_node();

    newNode->info = val;
    newNode->next = pos->next;
    pos->next = newNode;

    if(pos == list->last) list->last = newNode;
}

node_t* seek(type_t val, SList_t* list){

    return_if_null(list);
    node_t* iterator = list->first;
    
    while(iterator->next != NULL){
        iterator = iterator->next;
        if(iterator->info == val) return iterator;
    }

    return NULL;
}

void remove_pos(node_t* pos, SList_t* list){

    //TODO: null pointer exception checking

    node_t* toRemove = pos->next;
    pos->next = toRemove->next;
    free(toRemove);

    //TODO: update last if u kill the last node
}

void clear(SList_t* list){

    //TODO: null pointer exception checking
    node_t* pos = list->first;

    while(pos->next != NULL){
        remove_pos(pos, list);
        pos = pos->next;
    }
}