/* being sneaky with malloc 
allocating BLOCKS of mem
then using them*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ONEGB (1 << 30)
#define N 10000L
int main()
{ 
    int count =0;
    int *blocks[N];
    for(int i = 0; i <N ; i++) 
    {
         //OS is going to let us have as many as possible
         blocks[i] = malloc(ONEGB);
         if(blocks[i] == NULL)
         {
             printf("done at %i\n", i);
             return 0;
         }
    }

    for(int i = 0; i <N ; i++) 
    {
        memset(blocks[i], 2, ONEGB);
        printf("Wrote to %i gigs\n", i);
    }


    
      return 0;
}