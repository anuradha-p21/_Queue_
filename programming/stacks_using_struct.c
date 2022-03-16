#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


/* structure for stack */
typedef struct stack {
    int data;
    struct stack *next;
} MyStack;

/* making top global to make it available throughout all functions without passing its refrence **top */
MyStack *top = NULL;

/* this function creates an object */
MyStack* myStackCreate() {
    MyStack *obj = (MyStack*)malloc(sizeof(MyStack));
    obj->next = NULL;
    obj->data = 0;
    return obj;
}

/* frees the memory allocated for obj*/
void myStackFree(MyStack* obj) {
   
    free(obj);
}

/* pushes the element into the stack, pushes at top(head) */
void myStackPush(MyStack* obj, int x) {
    obj->data = x;
    if(top == NULL)
    {
         top = obj;
        return;
    }
    obj->next = top;
    top=obj;
}

/* pops from the head of the stack */
int myStackPop(MyStack* obj) {
    int x;
    if(top == NULL)
        return -1;
    x = top->data;
    top = (top->next != NULL)?top->next: NULL;
    return x;
}

/* returns the data from the top */
int myStackTop(MyStack* obj) {
    if(top == NULL)return -1;
    return top->data;
  
}

/* returns if the stack is empty or not */
bool myStackEmpty(MyStack* obj) {
    if(top == NULL) return true;
    else return false;
  
}
void printStack(MyStack *top)
{
    MyStack *temp = top;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
}

int main(){
    MyStack* obj = myStackCreate();
    MyStack* obj2 = myStackCreate();
  
    int x = 10;
    int y = 11;
    myStackPush(obj, x);
    myStackPush(obj2, y);
    printStack(top);
 
    int param_2 = myStackPop(obj);
    printf("element popped : %d\n", param_2);
    int param_3 = myStackTop(obj);
     printf("element top : %d\n", param_3);
    bool param_4 = myStackEmpty(obj);
    printf("stack is empty? %d \n", param_4);
    printStack(top);
     param_2 = myStackPop(obj);
    printf("element popped : %d\n", param_2);
     param_2 = myStackPop(obj);
    printf("element popped : %d\n", param_2);
     param_4 = myStackEmpty(obj);
    printf("stack is empty? %d \n", param_4);
     printStack(top);


    return 0;

}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/