#ifndef LIST_H
#define LIST_H

// ...insert, find (contains?), and delete items...
#include "node.h"

typedef struct {
    Node* head;
    Node* tail;
    int len;
} List;

void init(List* list);
void del(List* list, char* str);
void insert(List* list, char* str, int index);
int contains(List* list, char* str);
void print(List* list);

#endif