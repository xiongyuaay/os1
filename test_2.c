#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int value = 0;

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
        printf("child: pid = %d\n", pid);
        printf("child: pid1 = %d\n", pid1);    
        value++;
        printf("child value: %d", value);
    }
    else
    {
        pid1 = getpid();
        printf("parent: pid = %d\n", pid);
        printf("parent: pid1 = %d\n", pid1);
        wait(NULL);
        value--;
        printf("parent value: %d", value);
    }

    return 0;
}