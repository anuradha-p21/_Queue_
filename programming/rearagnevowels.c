#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int comp(const void *a , const void *b)
{
    return(*((char*)a) < *((char*)b));
}
void rearangeVolwels( char *S)
{
    int n = strlen(S);
    char v[n];
    int j = 0;
    for(int i = 0; i<n;i++)
    {
         if (S[i] == 'a' || S[i] == 'e'
            || S[i] == 'i' || S[i] == 'o'
            || S[i] == 'u') {
            v[j++] = S[i];
            
        }
    }
    qsort(v, n, sizeof(char), comp); 
    printf("%s", v);
    j = 0;
     for(int i = 0; i<n;i++)
    {
         // is a vowel, and increment j by 1
        if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i'
            || S[i] == 'o' || S[i] == 'u') {
            S[i] = v[j++];
            }
    }





}
int main()
{
    
   char *s;

   s = (char*)malloc(sizeof(char) * 100);
    scanf("%s[^/n]", s); // will now read spaces. except "enter" it will read everything
    rearangeVolwels(s);
    printf("%s", s);

}