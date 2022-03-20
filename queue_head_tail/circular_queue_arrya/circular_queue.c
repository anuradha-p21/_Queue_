#include "circular_queue.h"

//function to initialise a queue, allocate memory.
queue *initCq()
{
    queue *Q = (queue *)malloc(sizeof(queue));
    Q->front=-1;
    Q->rear = -1;
    Q->size=MAX_SIZE;
    Q->arr = (int *)malloc(Q->size* sizeof(int));
    printf("init Q ");
    return Q;
}
void enQueue(queue *Q, int value){
    //if front = 0 and read is size-1 OR rear = front-1 % size -1 then queue is full
    if ((Q->front == 0 && Q->rear == Q->size-1) ||  
            (Q->rear == (Q->front-1)%(Q->size-1)))
    {
        printf("\nQueue is Full");
        return;
    }
 
 //if front is -1 then it is still the first element . 
    else if (Q->front == -1) /* Insert First Element */
    {
        Q->front = Q->rear = 0;
        Q->arr[Q->rear] = value;
    }
 
 //if front is not 0 and rear is size -1 means space available before front
    else if (Q->rear == Q->size-1 && Q->front != 0)
    {
        Q->rear = 0;
        Q->arr[Q->rear] = value;
    }
 
    else
    {
        Q->rear++;
        Q->arr[Q->rear] = value;
    }
}
int deQueue(queue *Q){
     if (Q->front == -1)
    {
        printf("\nQueue is Empty");
        //return INT_MIN;
        return -1;
    }
 
    int data = Q->arr[Q->front];
    Q->arr[Q->front] = -1;
    if (Q->front == Q->rear)
    {
        Q->front = -1;
        Q->rear = -1;
    }
    else if (Q->front == Q->size-1) //the last element
        Q->front = 0;
    else
        Q->front++;
 
    return data;
}
    void displayQueue(queue *Q){
         if (Q->front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (Q->rear >= Q->front)
    {
        for (int i = Q->front; i <= Q->rear; i++)
            printf("%d ",Q->arr[i]);
    }
    else
    {
        for (int i = Q->front; i < Q->size; i++)
            printf("%d ", Q->arr[i]);
 
        for (int i = 0; i <= Q->rear; i++)
            printf("%d ", Q->arr[i]);
    }
    }
