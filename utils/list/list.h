#ifndef __LIST_H
#define __LIST_H

#include<stdlib.h>                

typedef int type_t;  //<-- Type is as default an int, I would want to make it generic tho...
typedef void* list_t; //<-- Type for the list
typedef void* pos_t; //<-- The position macro, can be and integer(arrays) or a type pointer(linked lists).

/** Inserts in the position marked by @pos the value @val
 *  in the list @list.
 */
void insert(type_t val, pos_t pos, list_t list);

/** Returns the position of the first instance of the value
 *  @val in the list @list.
 */
pos_t seek(type_t val, list_t list);

/** Returns the value of the position @pos in the list @list
 */
type_t get(pos_t pos, list_t list);

/** Removes the position @pos from the list*/
void remove(pos_t pos, list_t list);

/** Clears all the list*/
void clear(list_t list);

/** Returns the first position of the list*/
pos_t first(list_t list);

/** Returns the end of the list*/
pos_t end(list_t list);

#endif