#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
    int data;
    struct  Node *next;

} node;

node* reverselist( node *head)
{
     node* cur = head;
     node *n = NULL, *prev = NULL; //1->2->3

     while(cur != NULL)
     {
         n = cur->next;
         cur->next = prev;
         prev = cur;
         cur = n;

     }
   head= prev;
     return head;
}

node* insertAthead( node *head, int data)
{
    node *temp = head;
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(head ==NULL)
    {
        head = newnode;
        return head;
    }
    while(temp->next != NULL) //1 2 3 
    {
            temp = temp->next;
    }
    temp->next = newnode;
        return head;
}
void printlist( node *head)
{
    node*temp = head;
    while(temp != NULL){
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

bool detectloop(node *head)
{
    node* fast = head;
    node* slow = head;
    while(slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            printf("%d\n", slow->data);
            return true;
        }
    }
    return false;

}
int main()
{
    node *head = NULL;
  head=  insertAthead(head, 5);
      head = insertAthead(head, 4);
        head = insertAthead(head, 3);
        head =   insertAthead(head, 2);
         head =    insertAthead(head, 1);
           /* Create a loop for testing */ //5 4 3 2 1
    head->next->next->next = head->next;
    //printlist(head);
  //head =  reverselist(head);
    printf("\n");
   // printlist(head);
   printf("%d", detectloop(head));

}