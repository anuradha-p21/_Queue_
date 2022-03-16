#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    void *first = sbrk(0);
    void *second = sbrk(4096);
    void * third = sbrk(0);

    //sbrk returns the previous program break location
    //line 6 will give at 0, since it was at 0 even before calling sbrk(0)
    // line 7 will give at 0 , since before sbrk(10) was called ,it was at 0
    // line 8 will give at 10, since before calling 0 ut was at 10.
 int *ptr = (int*) third +1 ;
 *ptr = 0xDEAD; // trying to save something after program break
 //leads to seg fault
    printf(" first : %p\n", first);
    printf(" second : %p\n", second);
    printf(" third: %p\n", third);
}