#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INT_MAX 2147483647

int strtoint(char * c)
{
   
    int l = strlen(c); //123
    long long int n = 0;
    //printf("%ld\n", sizeof(n));
    for(int i = 0; i<l;i++)
    {
        n =  n*10 + (c[i] - '0'); //1 , 10+ 2 
        //for overflow, we just return NULL
       if(n > INT_MAX /10 || (n == INT_MAX /10 && ((c[i] - '0') > INT_MAX %10 ))) {
           return 0;
       }
    }
 
    return n;
}

char * addStrings(char * num1, char * num2){
    int n1, n2 =0;
     int  l1 = strlen(num1);
   int  l2 = strlen(num2);
   if(l1 == 0 && l2 ==0) return NULL;

    //call helper function to change to number.
    n1 = strtoint(num1);
    n2 = strtoint(num2);
    if(n1 == 0 && n2 ==0) return NULL;
   
   //calculate the sum in integer
    int sum = n1+n2; //134;

    //length of the resultant string will be max l1+l2+1
    int  l = l1+l2;
    char *s = (char*)malloc(sizeof(char) * (l+1));
    int i =0;
    //convert sum from int to string
    while(sum !=0)
    {
        s[i] = (sum % 10 ) + '0'; //4 , 3, 1 
     
        i++;
        sum = sum/10;
    }
    //reverse the string
    int j = 0;
    int k = strlen(s);
    while(j < k)
    {
        char t = s[j]; //0201 
        s[j] = s[k -1 ];
        s[k-1] = t;
        j++;
        k--;
    }
 
    return s;
}

int main(){
    char * res = (char*)malloc(sizeof(char) * 100);
    res = addStrings("2147483647", "21474836479");
    printf("%s", res);
}