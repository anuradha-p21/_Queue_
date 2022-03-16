#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int countPrimes(int n){
    if(n<=2 )
    {
        return 0;
    }
    int i = 0, count = 2, flag =0;
  while(i < n) //10
    {
        int s = sqrt(i);
      
        for(int j = 2; j<= s; j++) // 
        {
            if(i % j ==0)
            {
               flag = 1;
                break;
            }  
        }
      if(flag ==0 && i >=2)
      {
          count++;
      }
      i++;
    }
    return count;

}
int main()
{
    int n = countPrimes(10); 
    printf(" %d\n", n);
    return 0;

}