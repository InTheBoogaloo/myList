#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef enum ListResults{
    LR_SUCCESS=1,
    LR_LIST_NULL=-1
}LR;

struct Node{
    Node* next;
    Node* prev;
    void*  value;
};

struct List{
    Node* head;
    Node* tail;
    size_t size;
    size_t elem_size;
};

Node* create_node();

Node* create_node(void* value){
    Node*  n;
    n=malloc(sizeof(Node));
    if(!n) return NULL;
    n->next=NULL;
    n->prev=NULL;
    n->value=value;
    return n;
}

List* list_create(size_t elem_size){
    List* l=malloc(sizeof(List));
    if(!l) return NULL;
    l->head=NULL;
    l->tail=NULL;
    l->size=0;
    l->elem_size=elem_size;
    return l;
}

LR list_push_back(List* list, void* value){
    if(!list) return LR_LIST_NULL;
    if(!list->head){
        list->head=create_node(value);
        list->tail=list->head;
        list->size++;
        return  LR_SUCCESS;
    }else{
        Node* tmp=list->tail;
        tmp->next=create_node(value);
        list->size++;
        tmp->next->prev=tmp;
        list->tail=tmp->next;
        return LR_SUCCESS;
    }
}

size_t list_size(const List* list){
    if(!list) return 0;
    return list->size;
}

void* list_pop_back(List* list){
    if(!list || !list->tail)return NULL; 
    Node* tmp=list->tail;
    void* value;
    if(!tmp->prev && !tmp->next){
        value=list->tail->value;
        free(list->tail);
        list->tail=NULL;
        list->head=NULL;
        list->size=0;
        return value;
    }
    else{
        value=tmp->value;
        tmp->prev->next=NULL;
        list->tail=tmp->prev;
        free(tmp);
        list->size--;
        return value;
    }
}

void list_destroy(List* list){
    if(!list) return;
    Node* aux=list->head;
    while(aux){
        Node* next=aux->next;
        free(aux);
        aux=next;
    }
    free(list);
}
