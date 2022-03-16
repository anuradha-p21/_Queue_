#include"scope.h"

extern int called;
int main()
{
    int *p;
    p = &called;
    for(int i = 0 ; i < 20 ; i++)
    {
        increment(p);
    }
    printf(" count val :%d", *p);
     for(int i = 0 ; i < 20 ; i++)
    {
        decrement(p);
    }
    printf(" count val :%d", *p);

}