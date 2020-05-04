#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

// void *thread(void *arg)
// {
//     //wait
//     sem_wait(&mutex);
//     printf("\nEntered..\n");

//     //critical section
//     sleep(4);

//     //signal
//     printf("\nJust Exiting...\n");
//     sem_post(&mutex);
// }

int main()
{
    // int c = 0;
    // int *c1 = &c;
    // int b = *c1;

    // c++;
    // printf("%d %d %d\n", c, *c1, b);

    // int counter = 0;
    // while (0)
    // {
    //     counter++;
    //     printf("Hello\n");
    //     if (counter > 2)
    //     {
    //         break;
    //     }
    // }

    printf("%d\n", '0');
    return 0;
}
