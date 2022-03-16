
#include "scope.h"

void increment( int *c)
{
    (*c)++; //*(c++) -->address
    called++;
    printf( " called  %d\n", called);
   // return c;
}
void  decrement(int *c)
{
    (*c)--;
    called--;
      printf( " called  dec %d\n", called);
   // return c;
}

