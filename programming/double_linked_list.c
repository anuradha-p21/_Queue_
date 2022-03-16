#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    struct node *next;
    struct node *prev;
    void *data;
} Node;
/*****************************************************
 * insert at head 
 * **************************************************/
void insertAthead( Node** head, void *data)
{
    Node *newnode = (Node*)malloc(sizeof(Node*));
     if(newnode == NULL)
    {
        printf("not able to push the element"); return;
    }
    newnode->data  = data;
    if(head == NULL) return;
    if (*head == NULL) {
        newnode->prev = NULL;
        *head= newnode;
        return;
    }
    
    newnode->next = (*head);
    newnode->prev = NULL;
    (*head)->prev = newnode;
    (*head) = newnode;


}

/************************************************
 *      APPEND NODE AT GIVEN INDEX
 * *********************************************/
void AppendatIndex(Node **head, int index, void *data)
{
   
    if(head == NULL) return;
    int i = index-1;
    Node *temp = *head;
    Node *newnode = (Node*)malloc(sizeof(Node*));
     if(newnode == NULL)
    {
        printf("not able to push the element"); return;
    }
    newnode->data  = data;
    if(index == 0) return; 
    if(index != 0)
    {
    if((*head) == NULL) return;
    while((i-1) && temp!=NULL)
    {
        i--;
        temp = temp->next;
    }
    if(temp != NULL)
    {
        //first connect node , only then rejoin the prev and next ones
        newnode->prev = temp;
        newnode->next = temp->next;
        if(temp->next != NULL)
        temp->next->prev = newnode;
        temp->next = newnode;
        return;
    }
    }
    return;    
}
/************************************************
 *      DELETE AT INDEX
 * *********************************************/
void deleteatIndex(Node **head, int index)
{
    if(head == NULL) return; // if we pass NULL from main program will crash, so check for this.
    if(index <=0) return;   // if we pass -ve index or 0 just return;
    Node* temp = *head;
    if((*head) == NULL) return; // no nodes to remove. 
    //if index is 1
    int i = index -1;
    if(index == 1)
    {
        (*head) = (*head)->next;
        (*head)->prev = NULL;
        temp->next = NULL;
        free(temp);
        return;
    }
    while(i && temp->next!= NULL)
    {
        i--;
        temp = temp->next;
        //printf("%d", i);
    }
    if(temp != NULL && (i == 0))  
    {
        temp->prev->next = temp->next;
        if(temp->next!= NULL)
        temp->next->prev = temp->prev;
         //free(temp);
         return;
    }
    return;

}
/*******************************************
 *      ADD AT END OF LIST
 * *****************************************/

void InsertAtEnd(Node **head, void *data)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    Node *temp = *head;
    if(head == NULL) return;
    if((*head) == NULL) //means there is no node until now
    {
        //end node is the first node
        (*head) = newnode;
        return;
        
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;

}

/***********************************************
 * rotate list by n times
 * ********************************************/
void rotatelist(Node **head, int count)
{
    if(head == NULL || *head == NULL) return;
    if(count == 0) return;
    Node *temp = *head;
    //find last node , also count num of nodes
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
   //make the list circular
   temp->next = *head;
   (*head)->prev = temp;

   //move the head and temp by given position
   int pos = 1;
   while(pos<=count)
   {
       (*head) = (*head)->next;
       temp = temp->next;
       pos++;
   }
   //now make it un circular

   temp->next = NULL;
   (*head)->prev = NULL;

}

/************************************************
 *      PRINT LIST
 * *********************************************/
void printlist(Node* head)
{
	Node* n;
	n = head;
	while (n != NULL)
	{
		printf("%d ->", (int*)n->data);
		n = n->next;

	}
}

int main()
{
    Node *head ; // (Node*)malloc(sizeof(Node*));
    head = NULL;
    insertAthead(&head, (void*)5);
       insertAthead(&head, (void*)6);
          insertAthead(&head, (void*)7);
             insertAthead(&head, (void*)8);
 insertAthead(NULL, (void*)8);
    printlist(head);
    printf("\n");
 AppendatIndex(&head, 5, (void*)90);
 printlist(head);
  printf("\n");
 AppendatIndex(&head, 0, (void*)1);
 printlist(head);
  printf("\n");
  AppendatIndex(&head, 3, (void*)3);
  printlist(head);
  printf("\n");
   //AppendatIndex(NULL, 3, (void*)3);

   //deleteatIndex(NULL, 0);
  deleteatIndex(&head, 1);
  printlist(head);
  printf("\n");
   deleteatIndex(&head, 10);
  printlist(head);
    printf("\n");
    
    rotatelist(&head, 3);
       printlist(head);
    printf("\n");
InsertAtEnd(&head, (void*)89);
 printlist(head);
  printf("\n");
 InsertAtEnd(&head,(void*)65);
 printlist(head);
  printf("\n");
  InsertAtEnd(&head, (void*)35);
  printlist(head);
  printf("\n");

  


    
}