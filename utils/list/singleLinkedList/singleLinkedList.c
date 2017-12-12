#include "singleLinkedList.h"

SNode_t* SList_new_node(){

    SNode_t *Node;

    Node = malloc(sizeof(SNode_t));
    return_null_if(Node == NULL)

    return Node;
}

SList_t* SList_new_singleLinkedList() {

    SList_t *List;

    List = malloc(sizeof(SList_t));
    return_null_if(List == NULL)

    List->first = SList_new_node();
	return_null_and_free(List->first == NULL, List)

    List->last = List->first;

    return List;
}

SList_t* SList_generateInRange(size_t size, type_t min, type_t max){
    SList_t* List = SList_new_singleLinkedList();
    return_null_if(List == NULL)

    size_t i;

    srand(time(NULL));
    for(i = 0; i < size; i++){
        type_t val = min + (rand() % (max - min));
        SList_insert(val, List->last, List);
    }

    return List;
}

void SList_insert(type_t val, SNode_t* pos, SList_t* list){

	return_if(list == NULL)

    SNode_t* newNode = SList_new_node();
	return_if(newNode == NULL)

    newNode->info = val;
    newNode->next = pos->next;
    pos->next = newNode;

    if(pos == list->last) list->last = newNode;
}

SNode_t* SList_seek(type_t val, SList_t* list){

    return_null_if(list == NULL)
    SNode_t* iterator = list->first;
    
    while(iterator->next != NULL){
        if(iterator->next->info == val) return iterator;
		iterator = iterator->next;
    }

    return iterator;
}

void SList_remove(SNode_t* pos, SList_t* list){

    return_if(list == NULL)

    SNode_t* toRemove = pos->next;
    pos->next = toRemove->next;

	if(toRemove == list->last)
		list->last = pos;

    free(toRemove);

}

void SList_clear(SList_t* list){

    return_if(list == NULL)
    SIterator_t it = list->first;

    while(it->next != NULL){
        SList_remove(it, list);        
    }
}

SNode_t* SList_previous(SNode_t* pos, SList_t* list){

	return_null_if(list == NULL)
	SIterator_t it = list->first;

	while(it->next != NULL){
		if(it->next == pos) return it;
		it = it->next;
	}
	
	return it;
}


//Not a generic function, only works with type_t as integers
void SList_print(SList_t* list){

	return_if(list == NULL);
	SIterator_t it = list->first;

	while(it->next != NULL){
		printf("%d\t", it->next->info);
		it = it->next;
	}
	printf("\n");
}
