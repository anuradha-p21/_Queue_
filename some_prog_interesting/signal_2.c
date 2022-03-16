#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h> //for wait
#include<signal.h>

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
        int t;
        do {

        }while(t >0)
        kill(pid, SIGSTOP);  /* kill will not actually kill it, it just signals the process with pid
                       in our case the child, to do something. The something here is STOP */
        sleep(2);
        kill(pid, SIGCONT);
        sleep(2);
        kill(pid, SIGKILL);  
        wait(0);
       
    }
    return 0;
}
