#include<stdio.h>
#include<stdlib.h>

typedef struct queue_t{
   struct item_t *head;
    struct item_t *tail;
} queue;
typedef struct item_t {
    int data;
     struct item_t *next; 
}item;

void dequeue( queue  *queue, int *data);
void enqueue( queue *queue , int data);
void printQ( queue * queue);