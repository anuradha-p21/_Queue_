
//Fibonacci Series using Recursion
#include<stdio.h>
#include<iostream>
using namespace std;
int fib(int n)
{
   if (n <= 2)
      return 1;
   return fib(n-1) + fib(n-2);
}
  
int main ()
{
  int n = 9;
  printf("%d", fib(n));
  getchar();
  return 0;
}