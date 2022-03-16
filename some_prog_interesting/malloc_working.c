#include<stdio.h>
#include<stdlib.h>

int main()
{
    for(int i = 0; i <5; i++){
    char *p = malloc(50000);
    printf(" got memory address = %p\n", p);
    }
}