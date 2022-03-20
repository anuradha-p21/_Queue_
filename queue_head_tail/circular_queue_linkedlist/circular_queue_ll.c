#include"circular_queue_ll.h"


void enqueue(q *queue, int data)
{
    item *new = (item*)malloc(sizeof(item));
    new->next = NULL;
    new->data = data;
    if(queue->head == NULL && queue->tail == NULL) //queue is empty
    {
        queue->head = new;
        queue->tail = new;
        new->next = new;
        return;

    }
    //new is appended after tail node
    new->next = queue->head; 
    queue->tail->next = new;
    //move last to our new last node
    queue->tail = new;
    return;

}

int dequeue( q*queue)
{
    int val;
    if(queue->head == NULL && queue->tail == NULL) return -1; //empty queue.
    //if queue has only 1 node
    if(queue->head == queue->tail) {
    val = queue->head->data;
    queue->head = NULL;
    queue->tail = NULL;
    return val;
    }
    else{
        struct item_t *temp;
        temp = queue->head;
        val = temp->data;
        queue->head  = queue->head->next;
        free(temp);
        return val;
    }

}

void printq(q *queue)
{
    if(queue->head == NULL) {
        printf("queue is empty....\n");
        return;
    }
    struct item_t *temp;
    printf("printing queue \n");
    temp = (queue->head);
    while(temp->next != (queue->head))
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data); //for last ndoe;
}

int main()
{
    q *queue =(q*)malloc(sizeof(q));
    queue->head = NULL;
    queue->tail = NULL;

    enqueue(queue, 14);
printq(queue);
    enqueue(queue, 22);
    enqueue(queue, 56);
    printq(queue);
     printf("\nDeleted value = %d", dequeue(queue));
    printf("\nDeleted value = %d", dequeue(queue));
 printf("\nDeleted value = %d", dequeue(queue));
    printf("\nDeleted value = %d", dequeue(queue));
    printq(queue);
}