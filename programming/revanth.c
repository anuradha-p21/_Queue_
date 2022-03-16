#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverseString(char**s, int sSize){
char *temp = (char*)malloc(sizeof(char)* sSize);
for(int i = 0; i< sSize; i++)
{
    temp[i] = (*s)[sSize-1 -i];
    *(temp+i)= *(*s + sSize -1 + i )
    //*(temp + i) = *(s)[sSize - 1 -i];
}
//strcpy(*s, temp);
*s = temp;
printf("%s\n", *s);
//free(temp);  if you wanna use free here, use strcpy. 
}
int main()
{
   char *s = (char*)malloc(sizeof(char)*10);
   scanf("%s", s);
   reverseString(&s, strlen(s));
   printf("%s hi there", s); //this does not print why ?

    return 0;
}
