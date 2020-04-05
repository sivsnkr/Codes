#include <stdio.h>
#include <pthread.h>

#define MAX_SIZE 9
int size = 0;
int value = 0;
int cThreadEntry = 0;
int pThreadEntry = 0;
int favouredEntery = 2;

void *cThread(void *args)
{
    while (1)
    {
        while (size > 0)
        {
            cThreadEntry = 1;
            while (pThreadEntry)
            {
                if (favouredEntery == 2)
                {
                    cThreadEntry = 0;
                    while (favouredEntery == 2)
                        ;
                    cThreadEntry = 1;
                }
            }
            value--;
            size--;
            printf("Value in cThread: %d\n", value);
            cThreadEntry = 0;
            favouredEntery = 2;
            sleep(1);
        }
    }
    return NULL;
}

void *pThread(void *args)
{
    while (1)
    {
        while (size <= MAX_SIZE)
        {
            pThreadEntry = 1;
            while (cThreadEntry)
            {
                if (favouredEntery == 1)
                {
                    pThreadEntry = 0;
                    while (favouredEntery == 1)
                        ;
                    pThreadEntry = 1;
                }
            }
            value++;
            size++;
            printf("Value in pThread: %d\n", value);
            pThreadEntry = 0;
            favouredEntery = 1;
            sleep(1);
        }
    }
    return NULL;
}

int main(void)
{
    pthread_t ctid, ptid;
    pthread_create(&ptid, NULL, pThread, NULL);
    pthread_create(&ctid, NULL, cThread, NULL);

    pthread_join(ctid, NULL);
    pthread_join(ptid, NULL);
    return 0;
}