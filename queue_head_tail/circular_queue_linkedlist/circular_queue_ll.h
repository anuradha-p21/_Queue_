#include<stdio.h>
#include<stdlib.h>

typedef struct item_t
{
    struct item_t *next;
    int data;
} item;
typedef struct queue {
     item *head;
     item *tail;
}q;