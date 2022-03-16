#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
#include<time.h>

int main(int argc, char *argv[])
{
    int fd[2];
    if(pipe(fd) == -1)return 1;
    int pid = fork();
    if(pid < 0) return 2;

    if(pid ==0)
    {
        //the child writes into the pipe
        char str[200];
        close(fd[0]);
        printf("input string :\n ");
        //fgets reads into string, 200 is size of buffer from stdin.
        fgets(str, 200, stdin); 
        str[strlen(str) -1] = '\0'; // we need to remove the /n that we gets from fgets
        int n = strlen(str) + 1 ; // send the lenhth of string first. 
            if(write(fd[1], &n, sizeof(int))<0)return 3;
            if(write(fd[1], str, strlen(str)+1 )<0) return4;
        close(fd[1]);
    }
    else{
        close(fd[1]);
        char str[200];
        int n;
       if( read(fd[0], &n, sizeof(int))< 0 ) return 4; // first read the length of the string recieved
        // we need length to be passed first because otherwise we cannot use read functions here.
        // the read function needs length or it cannot read the data
        // therefore since the str[200] are local to the processes we cannot use strlen here
        int n;
       if( read(fd[0], str, sizeof(char)*n)) return 5; 
       close(fd[0]);
    }