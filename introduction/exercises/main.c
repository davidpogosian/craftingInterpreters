/*
To get some practice with pointers, define a doubly linked list of heap-allocated strings. 
Write functions to insert, find (?contains), and delete items from it. Test them.
*/

// compile with: gcc main.c list.c 

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    List myList;
    init(&myList);
    char* str1 = (char*) malloc(6*sizeof(char));
    str1 = "item0";
    insert(&myList, str1, 0);
    insert(&myList, "item2", 1);
    insert(&myList, "item4", 2);
    insert(&myList, "item1", 1);
    insert(&myList, "item3", 3);
    print(&myList);

    printf("Is item5 in the list? %d \n", contains(&myList, "item5"));
    printf("Is item4 in the list? %d \n", contains(&myList, "item4"));
    printf("Is item3 in the list? %d \n", contains(&myList, "item3"));
    printf("Is item0 in the list? %d \n", contains(&myList, "item0"));

    printf("deleting item3 \n");
    del(&myList, "item3");
    print(&myList);

    printf("deleting item1 \n");
    del(&myList, "item1");
    print(&myList);

    printf("deleting item4 \n");
    del(&myList, "item4");
    print(&myList);

    printf("deleting item0 \n");
    del(&myList, "item0");
    print(&myList);

    insert(&myList, "item3", 1);
    print(&myList);
    return 0;
}