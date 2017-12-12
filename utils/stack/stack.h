#ifndef __STACK_H
#define __STACK_H

#include "../list/singleLinkedList/singleLinkedList.h"

#define TRUE 1
#define FALSE 0
typedef short bool;

typedef struct stack {
	SNode_t* top;
	SList_t* list;
} Stack_t;

Stack_t* new_Stack();

#define Stack_top(stack)			stack->top

void Stack_remove(Stack s);

void Stack_push(type_t val, Stack s);

type_t Stack_pull(Stack s);

bool isEmpty(Stack s);

#endif
