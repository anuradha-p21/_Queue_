#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h> //for wait
#include<signal.h>

int main()
{
    int pid = fork();
    if(pid == -1)
    {
        return 1;
    }
    if(pid ==0)
    {
        while(1){             /*even if the child has a loop of 1, it terminates after 2 seconds because in parent
                                we call the kill signal */
        printf("hello\n");
        usleep(50000);
        }
            
    }
    else{
        sleep(2);
        kill(pid, SIGKILL);   /* kill will not actually kill it, it just signals the process with pid
                                in our case the child, to do something. The something here is KILL */
        wait(0);
       
    }
    return 0;
}
