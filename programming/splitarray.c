#include<stdio.h>
#include<stdlib.h>

int splitarray(int *a, int n)
{
    int leftsum = 0;
    int rightsum = 0;
     int i;
    for(int i = 0; i < n; i++)
    {
        leftsum = leftsum+ a[i];
    }
    for(i = n-1; i >= 0; i--)
    {
        rightsum = rightsum + a[i];
        leftsum = leftsum - a[i];
        if(leftsum == rightsum)
            return i ; 
    
    }
    return -1;
}
void printarray(int *a , int m)
{
    int n = splitarray(a, m);
    for(int i =0; i <n; i++)
    {
        printf("%d", a[i]);
    }
      printf("\n");
    for(int i = n; i < m;i++)
    {
         printf("%d", a[i]);
    }
    return;
}
int main()
{
    
    int m;
    printf( " enter number of elements in array \n");
    scanf("%d", &m);
    int *a = (int*)malloc(sizeof(int) * m);
    for(int i= 0; i<m; i++)
    {
        scanf("%d", &a[i]);
        
    }
   
    printarray(a, m);
    
}