#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid, pid1;

    /* fork a child process */
    pid = fork();
    
    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0)
    {
        pid1 = getpid();
        printf("child: pid1 = %d\n", pid1);  
        if(execl("./system_call", "system_call", NULL) == -1)
        {
            perror("execl failed");
            exit(1);
        }
    }
    else
    {
        pid1 = getpid();
        printf("parent: pid1 = %d\n", pid1);
        wait(NULL);
    }

    return 0;
}