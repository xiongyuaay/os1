#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = getpid();
    printf("system_call pid: %d\n", pid);
    return 0;
}