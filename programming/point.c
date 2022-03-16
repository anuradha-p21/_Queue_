#include<stdio.h>
#include<stdlib.h>

void copyarray( int *arr)
{
    //int *arr2  = (int*)malloc( sizeof(int) * 5);
    for(int i = 0; i <5; i++)
    {
         arr[i] = 2*arr[i];
    }
    //return arr2;
}

int main()
{
int *p = (int*)malloc( sizeof(int) * 5); // -> allocate 10 places for int
int *q = (int*)malloc( sizeof(int) * 5); // -> allocate 10 places for int

int a  =10;

;
printf("%p\n", p);
printf("%p\n", p+1);
for(int i = 0; i < 5; i++)
{
    //*(p+i) = i;
    p[i] = i;
    
}

for(int i = 0; i < 5; i++)
{
    printf("before double : %d     ", *(p+i));
}

 copyarray(p);
// printf("before double : %d     ", k);

for(int i = 0; i < 5; i++)
{
    printf("after double : %d     ", *(p+i));
}

}