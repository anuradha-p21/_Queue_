#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RLEN 50

/* function which checks if length of resultant string is greater that the input string
returns 1 if res is long
0 if original string is longer*/
int isReslong(char *res , char *s)
{
    return (strlen(res) > strlen(s));
}

/*run lenght encoding */
char * rLencode(char *s)
{
    long long int l = strlen(s);
    char *res = (char*)malloc(sizeof(char)* (2*l) );
    int i, j=0 ,k,  count =0;
    //since count can be multiple digits, we need to convert and store into a char array
    char cnt[MAX_RLEN]; // if it is 78 then cnt[0] = 8 and cnt[1] = 7 ... 

    for(i =0;i<l;i++) //aabbccdd
    {
        count = 0;
        res[j] = s[i]; //first char is saved  'a'
      //  printf("%c ",res[j]);
        j++;
        while(i < l-1 && s[i+1] == s[i])
        {
            count++;
            i++;

        }

        //when the characters are different while breaks
        //copy count to the string
        sprintf( cnt, "%d", count ); // copies int count to a char array cnt
        //copy cnt to destination , since it can have multiple characters 
        //copy it using a loop for lenght of cnt (or till when it is NOT null)
        for(k = 0; cnt[k] != '\0'; j++, k++ ) // or for(j = 0; *(cnt + k); j++, k++ ) both are ways to check if count is null
        {
            res[j] = cnt[k]; //or *(res+j) = *(cnt+k)

        }
     
    }
    res[j] = '\0';
    // return original string if the resultant compressed string is longer
    //because it does not make sense to enlarge a string when the intention is to compress it
    if(isReslong(res, s) == 0)
    return res;
    else 
    return s;
}

int main(){

    
  //char str[] = "geeksforgeeks";
  char *str = (char *)malloc(sizeof(char) * 10);
 // gets(str);
 scanf("%s", str);
    char* res = rLencode(str);
    printf("%s", res);
    getchar();

}