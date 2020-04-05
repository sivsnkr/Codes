#include <iostream> // std::cout
#include <thread>   // std::thread
#include <mutex>
#define INTERVAL 100
using namespace std;
mutex mtx;

void *generateRandom(void *params)
{
    int circle_points = 0;
    mtx.lock();
    int i;
    double rand_x, rand_y, origin_dist;
    rand_x = double(rand() % (INTERVAL + 1)) / INTERVAL;
    rand_y = double(rand() % (INTERVAL + 1)) / INTERVAL;

    origin_dist = rand_x * rand_x + rand_y * rand_y;

    if (origin_dist <= 1)
        circle_points++;

    mtx.unlock();
    void *crcpnt = &circle_points;
    pthread_exit(crcpnt);
}

int main()
{
    int interval, i;
    int circle_points = 0, square_points = 0;
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
        void *circpnt = NULL;
        pthread_join(arr[i], &circpnt);
        int *cir = (int *)&circpnt;
        if (cir != NULL)
        {
            circle_points += *cir;
        }
    }
    cout << circle_points << " " << square_points;
    double pi;
    pi = double(4 * circle_points) / 10000;

    cout << "Estimation of Pi = " << pi << endl;

    return 0;
}
