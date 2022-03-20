#include "queue_head_tail.h"

void enqueue( queue *queue , int data)
{
    item *newnode = (item *)malloc(sizeof(item));
    newnode->next = NULL;
    newnode->data = data;
    if(queue->head == NULL && queue->tail == NULL)
    {
        queue->head = newnode;
        queue->tail = newnode;
        return;
    }
    queue->tail->next = newnode;
    queue -> tail = newnode;
}

void dequeue( queue  *queue, int *data)
{
    if(queue->head == NULL && queue->tail == NULL)
    {
        *data = -1; //if queue is empty put -1;
        return;
        
    }
     //printf("%p\n", data);
     //data = (queue->head->data);
    *data = queue->head->data;
    if(queue->head == queue->tail)
    {
    queue->head = NULL;
    queue->tail = NULL;
    return;
    }
    queue->head = queue->head->next;
}
void printQ( queue * queue)
{
   struct item_t *temp;
    temp = (queue->head);
    while(temp!= NULL)
    {
     printf("%d ->", (temp->data));
     temp = temp->next;       
    }
      printf("\n");
    
}

int main()
{
    int num, data;
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
   }
    
}