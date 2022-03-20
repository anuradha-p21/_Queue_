#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 6

typedef struct Cqueue
{
    int *arr;
    int front, rear, size;
}queue;

queue * initCq();
void enQueue(queue *Q, int value);
    int deQueue(queue *Q);
    void displayQueue(queue *Q);