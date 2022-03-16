#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*************************************************
 * count primes till n 
 * ************************************************/
int countPrimes(int n){
  int *arr;
  //take an array of n , fill it with 0
  arr = (int*)calloc(n+1, sizeof(int));
    int i, j , count = 0;
    //since 0 and 1 are prime
    arr[0] = arr[1] = 1;
    for(int i = 2; i<n; i++)
    {
        //loop through from 2 to n 
        if(arr[i] == 0)
        {
            //count the number, suppose 2, 2nd: 3 will be 0 and will be counted
            count++;
            //all multiples of 2 are made 1, 2nd: all multiples of 3 are made  
            for(j = i*2; j<n ; j = j+i)
            {
                arr[j]  = 1;
            }
        }
    }
    return count;
}

void printprimes(int n)
{
    int *arr;
    //arr = (int*)calloc(n+1, sizeof(int)); //why calloc? because i want my array to be 0;
    //instead of calloc memset can be done
    memset(arr, 0, (n+1)*sizeof(arr[0])); 
    int i,j, count =0;
    arr[0] = arr[1] = 1; //0 and 1 are not considered

    for(i=0;i<n;i++)
    {
        if(arr[i] == 0)
        {
           printf("%d ", i);
            for(j=i*2; j<n; j = j+i)
            {
                arr[j] = 1;
            }
        }
    }
    return;
}
int main()
{
     int n = countPrimes(130);
     printf("%d\n", n);
     printprimes(130);

}