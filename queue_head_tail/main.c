//#include "queue_head_tail.h"
#include "circular_queue.h"
int main()
{
   /* int num, data;
    int *p = (int*)malloc(sizeof(int));
    queue *q;
    q->head = NULL;
    q->tail = NULL;
   // p = &data;
   while(1){
        printf("-----------------\n");
    printf("select an option\n 1. enqueue\n2.dequeue\n3.print\n");
  
    scanf("%d", &num);
   if(num == 1)
    {
        printf("enter element\n");
        scanf("%d", &data);
        enqueue(q, data);
            printf("enqueue : %d\n",data);
        
    }
   else if(num ==3)
    {
        printf("printing queue...\n");
        printQ(q);
    }
    
    else if(num ==2)
    {
        dequeue(q,p);
        if((*p) >=0){
        printf("dequeue : %d\n", *p);
        }
        else {
              printf("queue is empty\n");
        }
    }
    else {}
     printf("-----------------\n");
   }*/
    printf("circular Q ");
    queue *q=initCq();

    // Inserting elements in Circular Queue
    enQueue(q,14);
    enQueue(q,22);
    enQueue(q, 13);
    enQueue(q, -6);
 
    // Display elements present in Circular Queue
    displayQueue(q);
 
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", deQueue(q));
    printf("\nDeleted value = %d", deQueue(q));
 
    displayQueue(q);
 
    enQueue(q,9);
    enQueue(q, 20);
    displayQueue(q);
     return 0;
}