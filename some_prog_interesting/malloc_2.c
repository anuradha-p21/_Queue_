/* this program is to test how much memory a malloc will allocate . 
1) will it be equal to my physical memory - say 8GB?
2) will it be some limited memory set according to OS?
3) will it be physical + virtual memory 2^64 since we use Virtual memory


when we just allocate using malloc and not actually use the value , it allocates 13TB!! memory, that is just the 
impression our OS gives us, like sure , lets see what you do with it
But when i actually used memset which sets the memory to 1 , which means its being used. It fails after 8GB!
I am pretty sure that even though it shows 8gb it is not completely allocating it on RAM and pushing some to 
the drive 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ONEGB (1 << 30)
int main()
{ 
    int count =0;
    while(1){
    int *p = (int*)malloc(ONEGB);
    if(p == NULL)
    {
        printf( " memory refused after %d", count);
        return 0;
    }
    
    memset(p, 1, ONEGB);
    printf(" got  %p %d GB\n" ,p , ++count);

    }
      return 0;
}