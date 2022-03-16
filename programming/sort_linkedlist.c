#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;



//get mid of list
//a function to merge the list
//sort the list

node* getmid(node *head)
{
    node *midprev = NULL;
    //fast and slow pointer 1 7 8 3 4 
    while(head != NULL && head->next != NULL){
    midprev = (midprev == NULL) ? head : midprev->next;
    head = head->next->next; //fast 
    }
    node *mid = midprev->next; 
    midprev->next  = NULL; //1->7->null
    return mid; //8 is returned , position of 8.

}


node* merge( node * list1, node *list2)
{
    node dummy;
    dummy.data = 0;
    node *ptr = &dummy;
    node *prev = NULL;
    while(list1 != NULL && list2 !=NULL)
    {
        if(list1->data < list2->data)
        {
            ptr->next = list1;
            list1 = list1->next;
           
        }
        else {
            ptr->next = list2; 
            list2 = list2->next;
            
        }
        ptr = ptr->next;
    }
    if(list1 != NULL) ptr->next = list1;
    else ptr->next = list2;
    return dummy.next; // address of head is returned. 
}


node * sortList( node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    //list to be split and sorted 
    node *mid = getmid(head);
    node *left = sortList(head);
    node *right = sortList(mid);
    return merge(left, right);

}

void append( node **head, int data)
{
    node *newnode = (node*)malloc(sizeof(node));
    node *t;
    t=  *head;
    newnode->next = NULL;
    newnode->data = data;
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    while(t->next != NULL)
    {
        t = t->next;
    }
    t->next = newnode;
    return;
}
 void printlist( node *head)
 {
     node* n;
	n = head;
	while (n != NULL)
	{
		printf("%d ->", n->data);
		n = n->next;

	}
    printf("\n");
 }
 void deletelist( node ** head)
 {
     node *prev = (*head);
     while((*head) != NULL)
     {
         (*head) = (*head)->next;
         printf("deleting %d\n", prev->data);
         free(prev);
         prev = (*head);
     }
 }
int main()
{
    node *head = NULL;
    node *ret = NULL;
    node *t = head;
    append(&head, 5);
    append(&head, 4);
    append(&head, 3);
    append(&head, 10);
    append(&head, 1);
    printlist(head);
   ret = sortList(head);
    printlist(ret);
    printlist(head);
  deletelist(&ret);

   
    

}