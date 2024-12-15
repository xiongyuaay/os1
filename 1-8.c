#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>


void *thread1_f()
{
  pid_t tid = syscall(SYS_gettid);
  pid_t pid = getpid();
  printf("thread1 tid: %d, pid: %d\n", tid, pid);
  system("./system_call");
  printf("thread1 systemcall return\n");
  pthread_exit(NULL);
}

void *thread2_f()
{
  pid_t tid = syscall(SYS_gettid);
  pid_t pid = getpid();
  printf("thread1 tid: %d, pid: %d\n", tid, pid);
  system("./system_call");
  printf("thread2 systemcall return\n");
  pthread_exit(NULL);
}

int main()
{

    pthread_t thread1, thread2;
    if(!pthread_create(&thread1, NULL, thread1_f, NULL))
    {
        printf("threaad1 create success\n");
    }

    if(!pthread_create(&thread2, NULL, thread2_f, NULL))
    {
        printf("threaad2 create success\n");
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
