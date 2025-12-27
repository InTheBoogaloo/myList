#include <stdio.h>
#include "list.c"

int main(){
    List* l=list_create(sizeof(int));
    int x = 10;
    printf("%i\n",list_push_back(l, &x));
    x = 20;
    printf("%i\n",list_push_back(l, &x));
    printf(" lo que estaba guardado dentro del ultimo nodo:%i \n", *(int*)list_pop_back(l));
    printf(" lo que estaba guardado dentro del ultimo nodo:%i \n", *(int*)list_pop_back(l));
    list_destroy(l);
    return 0;
}




// List* list_create(size_t elem_size);

// void  list_destroy(List* list);

// int  list_push_back(List* list, void* value);

// void*  list_pop_back(List* list);

// size_t list_size(const List* list);
