#include <stdio.h>
#include <stdlib.h>
void push(void *data);
void * pop();
void display();
struct node
{
void *data;
struct node *next;
};
struct node *head;

void main ()
{
    int choice=0;
    char *name;
    printf("\n*********Stack operations using linked list*********\n");
    printf("\n----------------------------------------------\n");
    while(choice != 4)
    {
        printf("\n\nChose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {   name = (char *)malloc(sizeof(char)*10);
                printf("enter name: ");
                scanf("%s", name);
                push( (void *) name);
                break;
            }
            case 2:
            {
                char *str = (char *)pop();
                printf("poped: %s", str);
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("Exiting....");
                break;
            }
            default:
            {
                printf("Please Enter valid choice ");
            }
    };
}
}
void push (void * s)
{

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("not able to push the element");
    }
    else
    {
        newnode->data = s;  //data is void * and also s
        if(head==NULL)
        {
           newnode -> next = NULL;
            head=newnode;
        }
        else
        {
            newnode->next = head;
            head=newnode;

        }
        printf("Item pushed");

    }
}

void * pop()
{
    void * item= NULL;
    struct node *ptr;
    if (head == NULL)
    {
        printf("Underflow");
    }
    else
    {
        item = head->data;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item popped");

    }
    return item;
}
void display()
{
    int i;
    struct node *ptr;
    ptr=head;
    if(ptr == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Printing Stack elements \n");
        while(ptr!=NULL)
        {
            printf("%s\n",(char *)ptr->data);
            ptr = ptr->next;
        }
    }
}