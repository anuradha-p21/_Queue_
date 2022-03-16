#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p = (int*)malloc(sizeof(int)*5);
    for(int i = 0; i<5; i++)
    {
        p[i] = 2*i;
    }
     for(int i = 0; i<5; i++)
    {
        printf("%d  ", p[i] );
    }
    printf("\n");
    p = (int*)realloc(p, sizeof(int)*10);
      for(int i = 0; i<10; i++)
    {
        p[i] = 2*i;
    }
    for(int i = 0; i<10; i++)
    {
        printf("%d  ", p[i] );
    }

    return 0;

}