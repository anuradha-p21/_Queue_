#include<stdio.h>
#include<stdlib.h>

#define INT_MIN 32768
int find2max( int *a, int n)
{
    int max1;
    int max2;
    if(a[0] > a[1]){
    max1 = a[0];
    max2 = a[1];
    }
    else if( a[0] < a[1]){
        max1 = a[1];
        max2 = a[0];
    }
    else { // both equal
         max1 = a[1];
        max2 = INT_MIN;
    }
    //now iterate through i = 2
    for(int i = 2; i<n; i++)
    {
        if(a[i] > max1)
        {
            max2 = max1;
            max1 = a[i];
        }
        else if( a[i] < max1 && a[i] > max2)
        {
            max2 = a[i];
        }
        else{}

    }
    return max2;
}

int main()
{
    
    int m;
    printf( " enter number of elements in array \n");
    scanf("%d", &m);
    int *a = (int*)malloc(sizeof(int) * m);
    for(int i= 0; i<m; i++)
    {
        scanf("%d", &a[i]);
        
    }
   
    int n = find2max(a, m);
    printf("%d\n", n);
    
}