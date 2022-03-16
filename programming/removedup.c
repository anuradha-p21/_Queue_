#include<stdio.h>
#include<stdlib.h>


/*void removedup( int *a, int n)
{
    int i = 0;
    int j;
    j = i+1;
    printf("hi");
   for(i =0; i<n-1;i++)
    {
        if(a[i] != a[j] && j < n)
        {
            //i++;
            j++;
            
        }
        else{
        while(a[i] == a[j] && j <n)
        {
            if(a[j] == a[j+1])
            j++;
        }
        a[i+1] = a[j+1]; 
        j++;
    }
    }
    for(int k = 0; k < 2; k++){
    printf("%d" , a[k]);
    }
}*/
int main()
{
    int a[5] = { 1, 2, 2, 3, 3};
    
    for(int k = 0; k < 5; k++){
    printf("%d" , a[k]);
    }
   // removedup(a, 5);
int i = 0;
    int j;
    j = i+1;
    int n = 5;
    printf("hi\n");
   for(i =0; i<n && j < n;i++)
    {
        // printf("%d\n", i);
        if(a[i] != a[j])
        {
            //i++;
            j++;
           //  printf("%d\n", i);
            
        }
        else{
        while(a[i] == a[j] )
        {
                        // printf("%d\n", i);
            // printf("%d\n", j);

            if(a[j] == a[j+1])
            j++;
            else{
                a[i+1] = a[j+1]; 
                j++;
            }
        }
        
    }
    }
    for(int k = 0; k < 3; k++){
    printf("%d" , a[k]);
    }
    return 0;
}