int main()
{
    queue *q = (queue*)malloc(sizeof(queue));
    int i[5] = {5, 6, 7, 8 , 10 };
    int *deq = (int*)malloc(sizeof(int));
    int *temp =deq;
    for(int n = 0; n<5 ; n++)
    {
        enqueue(q, &(i[n]));
    }
     printQ(q);
    dequeue(q, deq);
   // dequeue(q, (deq));
    printf("%d\n", (*deq));
    
   // printf("%p\n", deq);
    printQ(q);
}