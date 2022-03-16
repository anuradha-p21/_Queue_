#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned long stringlen(char * str)
{
    char *end = str;  //assigning a pointer to the start of the string
    while(*++end);   //this is a too smart programming. Here we are pre incrementing the end and then 
                    //dereferencing it. 
                    //if there is a null string then it first increments it and then looks for another NULL. 
    return(end-str);
}
//in the below example we pass a null string expecting lenght wouldbe 0, but it misses that NULL point and then since it
//pre incremented, it probably moves to out next string --> here it is abcd , therefore at the end of abcd
//it encounters a null and then returns the lenght as 5!! instead of 0. 
void testit(char *str)
{
     printf("test\t %s\n", str);
     printf("libc\t %lu\n", strlen(str));
     printf("mine\t%lu\n", stringlen(str));

}
int main()
{

   testit("");
   testit("abcd");
   testit("hello hello");
   testit("this is good");
}