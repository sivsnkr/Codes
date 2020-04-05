// in this programme, producer will add to a variable and
// consumer will read that value and substract to that value

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

#define maxSize 9
sem_t mutex;
int size = 0;
int value = 0;

void *producer(void *args)
{
    while (1)
    {
        if (size < maxSize)
        {
            sem_wait(&mutex);
            value += 1;
            size += 1;
            printf("Producer produces: %d\n", value);
            sem_post(&mutex);
            sleep(1);
        }
    }
}

void *consumer(void *args)
{
    while (1)
    {
        if (size > 0)
        {
            sem_wait(&mutex);
            value--;
            size--;
            printf("Consumer consumes: %d\n", value);
            sem_post(&mutex);
            sleep(1);
        }
    }
}

int main()
{
    sem_init(&mutex, 0, 1);
    pthread_t tidp, tidc;
    pthread_create(&tidp, NULL, producer, NULL);
    pthread_create(&tidc, NULL, consumer, NULL);

    pthread_join(tidp, NULL);
    pthread_join(tidc, NULL);
}