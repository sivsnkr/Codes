#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <fcntl.h>

sem_t agent, tobacco, paper, match;
int isTobacco = 0, isPaper = 0, isMatch = 0;

void *agent1(void *args)
{
    //printf("Agent1 has entered\n");
    while (1)
    {
        sem_wait(agent);
        sem_post(tobacco);
        sem_post(paper);
        isTobacco++;
        isPaper++;
        printf("agent1 isTobacco: %d, isMatch: %d, isPaper: %d\n", isTobacco, isMatch, isPaper);
        sleep(1);
    }
}

void *agent2(void *args)
{
    //printf("Agent2 has entered\n");
    while (1)
    {
        sem_wait(agent);
        sem_post(tobacco);
        sem_post(match);
        isTobacco++;
        isMatch++;
        printf("agent2 isTobacco: %d, isMatch: %d, isPaper: %d\n", isTobacco, isMatch, isPaper);
        sleep(1);
    }
}

void *agent3(void *args)
{
    //printf("Agent3 has entered\n");
    while (1)
    {
        sem_wait(agent);
        sem_post(match);
        sem_post(paper);
        isMatch++;
        isPaper++;
        printf("agent3 isTobacco: %d, isMatch: %d, isPaper: %d\n", isTobacco, isMatch, isPaper);
        sleep(1);
    }
}

void *smoker1(void *args)
{
    //printf("Smoker1 has entered\n");
    while (1)
    {
        // printf("Somkers1 isTobacco: %d, isMatch: %d, isPaper: %d\n", isTobacco, isMatch, isPaper);
        if (isTobacco && isMatch)
        {
            sem_wait(tobacco);
            sem_wait(match);
            isTobacco = 0;
            isMatch = 0;
            printf("Paper has it\n");
            sem_post(agent);
        }
        //sleep(1);
    }
}

void *smoker2(void *args)
{
    //printf("Smoker2 has entered\n");
    while (1)
    {
        // printf("Somkers2 isTobacco: %d, isMatch: %d, isPaper: %d\n", isTobacco, isMatch, isPaper);
        if (isTobacco && isPaper)
        {
            sem_wait(tobacco);
            sem_wait(paper);
            isTobacco = 0;
            isPaper = 0;
            printf("Match has it\n");
            sem_post(agent);
        }
        //sleep(1);
    }
}

void *smoker3(void *args)
{
    //printf("Smoker3 has entered\n");
    while (1)
    {
        // printf("Somkers3 isTobacco: %d, isMatch: %d, isPaper: %d\n", isTobacco, isMatch, isPaper);
        if (isPaper && isMatch)
        {
            sem_wait(paper);
            sem_wait(match);
            isMatch = 0;
            isPaper = 0;
            printf("Tobacco has it\n");
            sem_post(agent);
        }
        //sleep(1);
    }
}

int main(void)
{
    sem_init(&agent, 0, 1);
    sem_post(&agent);
    sem_init(&tobacco, 0, 0);
    sem_init(&paper, 0, 0);
    sem_init(&match, 0, 0);

    // if ((agent = sem_open("/semaphore", O_CREAT, 0644, 1)) == SEM_FAILED)
    // {
    //     perror("sem_open");
    //     exit(1);
    // }
    // if ((tobacco = sem_open("/semaphore", O_CREAT, 0644, 0)) == SEM_FAILED)
    // {
    //     perror("sem_open");
    //     exit(1);
    // }
    // if ((paper = sem_open("/semaphore", O_CREAT, 0644, 0)) == SEM_FAILED)
    // {
    //     perror("sem_open");
    //     exit(1);
    // }
    // if ((match = sem_open("/semaphore", O_CREAT, 0644, 0)) == SEM_FAILED)
    // {
    //     perror("sem_open");
    //     exit(1);
    // }
    // agent = sem_open("/mysemaphore",
    //                  O_CREAT, 0644, 1);
    // tobacco = sem_open("/mysemaphore",
    //                    O_CREAT, 0644, 0);
    // paper = sem_open("/mysemaphore",
    //                  O_CREAT, 0644, 0);
    // match = sem_open("/mysemaphore",
    //                  O_CREAT, 0644, 0);

    pthread_t tid[6];
    pthread_create(&tid[0], NULL, agent1, NULL);
    pthread_create(&tid[1], NULL, agent2, NULL);
    pthread_create(&tid[2], NULL, agent3, NULL);
    pthread_create(&tid[3], NULL, smoker1, NULL);
    pthread_create(&tid[4], NULL, smoker2, NULL);
    pthread_create(&tid[5], NULL, smoker3, NULL);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[3], NULL);
    pthread_join(tid[4], NULL);
    pthread_join(tid[5], NULL);
    return 0;
}