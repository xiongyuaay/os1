#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int counter = 0;
 
void *thread1_f()
{
    for(int i=0;i<100000;i++)
    {
        counter += 100;
    }
    pthread_exit(NULL);
}
void *thread2_f()
{
    for(int i=0;i<100000;i++)
    {
        counter -= 100;
    }
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
    printf("variable result: %d", counter);
    return 0;
}