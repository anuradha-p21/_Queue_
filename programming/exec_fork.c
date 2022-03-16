#include<stdio.h>
#include<stdlib.h>

int main()
{
    if(fork() == 0)
    {
        printf("I am child\n");
        execlp( "ls", "ls", "-al", NULL);
        printf("");

    }
    else
    {
        printf("I am parent %d\n", getpid());
    }
}