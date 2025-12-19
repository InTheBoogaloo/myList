#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node{
    Node* next;
    Node* prev;
    int value;
};

struct List{
    Node* head;
    Node* tail;
    size_t size;
};

Node* create_node();

Node* create_node(int value){
    Node*  n;
    n=malloc(sizeof(Node));
    n->next=NULL;
    n->prev=NULL;
    n->value=value;
    return n;
}

List* list_create(void){
    List* l=malloc(sizeof(List));
    if(!l) return NULL;
    l->head=NULL;
    l->tail=NULL;
    l->size=0;
    return l;
}

void list_push_back(List* list, int value){
    if(!list) return;
    if(!list->head){
        list->head=create_node(value);
        list->tail=list->head;
        list->size++;
        return;
    }else{
        Node* tmp=list->head;
        while(tmp->next){
            tmp=tmp->next;
        }
        tmp->next=create_node(value);
        list->size++;
        tmp->next->prev=tmp;
        list->tail=tmp->next;
        return;
    }
}

size_t list_size(const List* list){
    if(!list) return 0;
    return list->size;
}

int list_pop_back(List* list){
    if(!list || !list->tail)return -66; 
    Node* tmp=list->tail;
    int value;
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
