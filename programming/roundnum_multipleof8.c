// CPP program to find smallest greater multiple
// of 8 for a given number
#include<stdio.h>
#include<stdlib.h>

 /* A naive approach to solve this problem using arithmetic operators is : 
Let x be the number then, 
x = x – (x % 8) 
This will round down x to the next smaller multiple of 8. But we are not allowed to use arithmetic operators.
Solution 2: An efficient approach to solve this problem using bitwise AND operation is: x = x & (-8) 
*/
// Returns next greater multiple of 8
int RoundUp(int x)
{
    return ((x + 7) & (-8));
}
 //returns nearest multiple of 8

 int Roundoff(int x)
 {
     return (x & (-8));
 }
 int findones(int x)
 {
     int c =0;
     while(x > 0)
     {
         if(x & 1) 
         { 
             c++;
         }
         x = x >>1;

     }
     return c;
 }
int main()
{
    int x = 255;
   printf("%d", RoundUp(x));
   printf("  %d", Roundoff(x));
     printf("  %d", findones(x));
    return 0;
}