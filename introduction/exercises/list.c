#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void init(List* list) {
    list->len = 0;
}

void print(List* list) {
    printf("~ \n");
    Node* cursor = list->head;
    for (int i = 0; i < list->len; i++) {
        printf("%s \n", cursor->val);
        cursor = cursor->next;
    }
    printf("~ \n");
    return;
}

void del(List* list, char* str) {
    Node* cursor = list->head;
    for (int i = 0; i < list->len; i++) {
        if (cursor->val == str) {
            if (i == 0) {
                list->head = cursor->next;
                /*
                    should I free cursor->val? I never allocated it but
                    if I comment out the line above, old value is still around...
                */
            }
            if (i == (list->len)-1) {
                list->tail = cursor->prev;
            }
            if (cursor->prev != NULL) {
                cursor->prev->next = cursor->next;
            }
            if (cursor->next != NULL) {
                cursor->next->prev = cursor->prev;
            }
            free(cursor);
            break;
        }
        cursor = cursor->next;
    }
    list->len -= 1;
    return;
}

void insert(List* list, char* str, int index) {
    if (index > list->len || index < 0) {
        printf("Out of bounds. can't insert \"%s\" into index %d \n", str, index);
        return;
    }
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->val = str;
    newNode->next = NULL;
    newNode->prev = NULL;
    //printf("ab to insert into %d %s \n", index, str);
    if (index == 0) {
        //printf("in \"insert into 0\" branch \n");
        if (list->len == 0) {
            list->head = newNode;
            list->tail = newNode;
        } else {
            list->head->prev = newNode;
            newNode->next = list->head;
            list->head = newNode;
        }
    } else if (index == list->len) {
        //printf("in \"insert into end\" branch \n");
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    } else {
        //printf("in \"insert into middle\" branch \n");
        int cursorIndex = 0;
        Node* cursor = list->head;
        while (cursorIndex != index - 1) {
            cursor = cursor->next;
            cursorIndex += 1;
        }
        cursor->next->prev = newNode;
        newNode->next = cursor->next;
        newNode->prev = cursor;
        cursor->next = newNode;
    }
    list->len += 1;
    return;
}

int contains(List* list, char* str) {
    Node* cursor = list->head;
    for (int i = 0; i < list->len; i++) {
        if (cursor->val == str) {
            return 1;
        }
        cursor = cursor->next;
    }
    return 0;
}