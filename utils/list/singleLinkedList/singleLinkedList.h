#ifndef __SINGLE_LINKED_LIST_H
#define __SINGLE_LINKED_LIST_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define return_if(expr)						if(expr) return;
#define return_val_if(expr, val)			if(expr) return val;
#define return_null_if(expr)     			return_val_if(expr, NULL)
#define return_null_and_free(expr, toFree)								\
	if(expr){															\
		free(toFree);													\
		return NULL;													\
	}	
		

typedef int type_t;
typedef struct node SNode_t;

struct node{
    type_t info;
    SNode_t* next; 
};

typedef struct slList {
    SNode_t* first;
    SNode_t* last;
} SList_t;

typedef SNode_t* SIterator_t;

SList_t* SList_generateInRange(size_t size, type_t min, type_t max);

SList_t* SList_new_singleLinkedList();

SNode_t* SList_new_node();

void SList_insert(type_t val, SNode_t* pos, SList_t* list);

SNode_t* SList_seek(type_t val, SList_t* list);

void SList_remove(SNode_t* pos, SList_t* list);

void SList_clear(SList_t* list);

SNode_t* SList_previous(SNode_t* pos, SList_t* list);

#define SList_get(pos)			pos->next->info

#define SList_first(list)		list->first

#define SList_last(list)		list->last

#define SList_next(pos)			pos->next

#define SList_add(val, list)	SList_insert(val, list->last, list)

void SList_print(SList_t* list);	

#endif
