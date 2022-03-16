#include<stdio.h>
#include<stdlib.h>
#include<string.h>


///abc -> ace means a = a + 0
// b = b+1 , c = c+2 .....
void encodeAlpha_plus_Ascii( char *s)
{
    int l = strlen(s);
    int d;
    for(int i =0; i<l; i++)
    {
        //97 - 115
        d = s[i] - 'a'; // a = 0
         //printf("%c -> ",s[i]);
        if(d + (s[i] - 'a') > 26){  
        d = (d + (s[i] - 'a')) % 26;
        s[i] = 'a' + d ; 
        printf("%c -> ",s[i]);
        }
         else{
             s[i] = s[i] + d;
              // printf("%c -> ",s[i]);
         }
       
    }
}
int main()
{
     char *s;

   s = (char*)malloc(sizeof(char) * 100);
    scanf("%s[^/n]", s); // will now read spaces. except "enter" it will read everything
    encodeAlpha_plus_Ascii(s);
    printf("%s", s);
}