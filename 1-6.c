#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>


int counter = 0;
sem_t mutex;

void *thread1_f()
{
  for(int i=0;i<100000;i++)
  {
    sem_wait(&mutex);
    counter += 100;
    sem_post(&mutex);
  }
  pthread_exit(NULL);
}

void *thread2_f()
{
  for(int i=0;i<100000;i++)
  {
    sem_wait(&mutex);
    counter -= 100;
    sem_post(&mutex);
  }
  pthread_exit(NULL);
}

int main()
{

    pthread_t thread1, thread2;
    sem_init(&mutex, 0, 1);
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
    sem_destroy(&mutex);
    printf("variable result: %d", counter);
    return 0;
}
