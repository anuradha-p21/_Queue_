#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    struct node *next;
    void *data;
} Node;
/************************************************
 *      APPEND NODE AT GIVEN INDEX
 * *********************************************/
void insertAtindex( Node **last, int index, void *data)
{
    
    if(last == NULL) return;
    int i = index-1;
    Node *temp = *last;
    Node *newnode = (Node*)malloc(sizeof(Node*));
     if(newnode == NULL)
    {
        printf("not able to push the element"); return;
    }
    newnode->data  = data;
    newnode->next= NULL;
    if(index <= 0) return; 
    if(index == 1)
    {
        if((*last) == NULL)
        {
            (*last) = newnode;
            newnode->next = (*last);
          //  printf("%d->", (int*)data);
            return;
        }
        //insert at begin of list . 
        newnode->next = (*last)->next; 
        (*last)->next = newnode;
        // printf("%d->", (int*)data);
        return;
    }
    if(index >1 && (*last) != NULL){
    Node *head = (*last)->next;
    Node *temp = (*last)->next;
    Node *prev = (*last)->next;
    while(i && temp->next != head)
    {
        i--;
        prev = temp;
        temp = temp->next;  //temp will go until last and then while will break
    }
    //if we come here we are supposed to insert at the end of the list
    //->1->2->3->4->5 and i said insert at 6 , should work
    //by end of whie  i = 1 and temp->next = head, so now insert after temp
    if(i ==1 && temp->next == head)
    {
        newnode->next = temp->next; //or last->next 
        temp->next = newnode;
        (*last) = newnode;
        // printf("%d->", (int*)data);
        return;
    }
    //if we have ->1->2->3->4->5 and i say insert at 10 , should not happen 
    //by end of while we have 5 in i and so we wont insert
    //now for general insertion in between the list >1->2->3->4->5 index =3
    //by end of while loop i = 0 and temp is at 3. 
    //we need to insert before 3. we need a prev.

else if (i == 0 && temp->next != head)
{
    newnode->next = prev->next;
prev->next =newnode;
 //printf("%d->", (int*)data);
}

return;
}
return;
}


/************************************************
 *      DELETE NODE AT GIVEN INDEX
 * *********************************************/
void Deleteatindex( Node **last, int index)
{
    //corner cases - if we pass NULL for &list in main, program crashes, therefore, check 
    if(last == NULL) return;
    //index is +ve and greater than 0
    if(index <= 0) return;
    //if only one node is present but requested index is >1 return
    if((*last) == NULL && index >=1) return;
    //delete the only present node
    if((*last)->next == (*last) && index ==1)
    {
        //only one node is present, delete it.
        
        last = NULL;
        free(*last);
        return; 
    }
      if((*last) != NULL && index ==1)
    {
        //delete at begin many nodes are present.
        Node *temp = (*last)->next;
        (*last)->next = temp->next;
        temp->next = NULL;
        return;
    }
    int i = index-1;
    if(index > 1 && (*last) != NULL)
    {
        Node *head = (*last)->next;
        Node *temp = (*last)->next;
        Node *prev = (*last)->next;
        while(i && temp->next != head)
        {
            prev= temp;
            temp = temp->next;
            i--;
        }
        if(i==0 && temp->next!= head)
        {
            //->1->2->3->4->5, and we say delete at 3
            //->1->2->4->5 shd be there
            // then i = 0 and temp will come at 3 and therefore the if will be satisfied
            //prev is at 2
            prev->next = temp->next;
            temp->next = NULL;
            return;
        }
        else if(i==0 && temp->next == head)
        {
            //the last node is getting deleted 
            //->1->2->3->4->5, and we say delete at 5
            //->1->2->3->4-> shd be there
            // then i = 0 and temp will come at 5 and therefore the if will be satisfied
            //prev is at 4
            prev->next = temp->next;
            temp->next = NULL;
            (*last) = prev;
            return;
        }
        else {
            //index is way greater than length do nothing
        }
        return;

    }
    return;
    
}

/************************************************
 *      PRINT LIST
 * *********************************************/
void printlist(Node* last)
{
	 /*Node *p;
 
    // If list is empty, return.
    if (last == NULL)
    {
        printf("empty\n");
        return;
    }
 
    // Pointing to first Node of the list.
    p = last -> next;
        if(p->next==p)
        {
            printf("%d",p->data); return;
        }
 
    // Traversing the list.
   
    while(p != last->next){
        printf("%d",p->data);
        p = p -> next;
    }*/
     Node *p;
 
    // If list is empty, return.
    if (last == NULL)
    {
      
        return;
    }
 
    // Pointing to first Node of the list.
    p = last->next;
 
    // Traversing the list.
    do
    {
         printf("%d ",p->data);
        p = p -> next;
 
    }
    while(p != last->next);
}

int main()
{
  
    Node *head; // = (Node*)malloc(sizeof(Node*));
    head = NULL;
    printf("\n");
       insertAtindex(&head, 1,(void*)6);
         insertAtindex(&head, 1,(void*)5);
            printlist(head);
    printf("\n");
          insertAtindex(&head, 1,(void*)7);
         insertAtindex(&head, 1,(void*)4);
          insertAtindex(&head, 1,(void*)8);
             printlist(head);
    printf("\n");
           insertAtindex(&head, 3,(void*)9);
            

       printlist(head);
    printf("\n");
    Deleteatindex(&head, 1);
         printlist(head);
    printf("\n");
     Deleteatindex(&head, 10);
         printlist(head);
    printf("\n");
  Deleteatindex(&head, 5);
         printlist(head);
    printf("\n");
    Deleteatindex(&head, 2);
         printlist(head);
    printf("\n");
     Deleteatindex(&head, 1);
         printlist(head);
    printf("\n");
     Deleteatindex(&head, 1);
         printlist(head);
    printf("\n");
   
    

}