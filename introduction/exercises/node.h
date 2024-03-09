#ifndef NODE_H
#define NODE_H

typedef struct Node Node;
struct Node {
    char* val;
    Node* next;
    Node* prev;
};

#endif