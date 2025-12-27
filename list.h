#ifndef LIST_H
#define LIST_H
#include <stddef.h>

typedef struct List List;
typedef struct Node Node; 


List* list_create(size_t elem_size);

void  list_destroy(List* list);

int  list_push_back(List* list, void* value);

void*  list_pop_back(List* list);

size_t list_size(const List* list);

#endif
