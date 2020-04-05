#include <iostream>
#include <thread>
#include <mutex>
#define INTERVAL 100
int circle_points = 0;
using namespace std;
mutex mtx;

void *generateRandom(void *params)
{
    mtx.lock();
    int i;
    double rand_x, rand_y, origin_dist;
    rand_x = double(rand() % (INTERVAL + 1)) / INTERVAL;
    rand_y = double(rand() % (INTERVAL + 1)) / INTERVAL;

    origin_dist = rand_x * rand_x + rand_y * rand_y;

    if (origin_dist <= 1)
        circle_points++;

    mtx.unlock();
    return &circle_points;
}

int main()
{
    int interval, i;
    //interval = srand() % 100;
    srand(time(NULL));
    pthread_t arr[INTERVAL * INTERVAL];
    int error;
    for (i = 0; i < (INTERVAL * INTERVAL); i++)
    {
        error = pthread_create(&arr[i], NULL, generateRandom, NULL);
        if (error < 0)
        {
            printf("The is error in creating thread\n");
            exit(2);
        }
    }
    for (i = 0; i < (INTERVAL * INTERVAL); i++)
    {
        pthread_join(arr[i], NULL);
    }
    double pi;
    pi = double(4 * circle_points) / 10000;

    cout << "Estimation of Pi = " << pi << endl;

    return 0;
}
