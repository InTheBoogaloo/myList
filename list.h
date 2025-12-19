#ifndef LIST_H
#define LIST_H

typedef struct List List;
typedef struct Node Node; 


List* list_create(void);
void  list_destroy(List* list);

void  list_push_back(List* list, int value);
int  list_pop_back(List* list);

size_t list_size(const List* list);

#endif
