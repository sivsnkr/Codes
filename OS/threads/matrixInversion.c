#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // for gettimeofday()

#include <pthread.h>
#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC

/* MATRIX PACKAGE (parallel)
	i. Determinant Value
	ii. Transpose
	iii. Inverse
	iv. Magic Square Checking
*/

#define N 5

int adj[N][N];
float inv[N][N];
int A[N][N];

struct DT
{
    int i;
    int j;
};

void cofactor(int mat[N][N], int temp[N][N], int p, int q, int n)
{

    int i = 0, j = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int mat[N][N], int n)
{

    int D = 0;

    if (n == 1)
        return mat[0][0];

    int temp[N][N];
    int sign = 1;

    for (int f = 0; f < n; f++)
    {
        cofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinant(temp, n - 1);

        sign = -sign;
    }
    return D;
}

void *runnercofacval(void *param)
{

    int temp[N][N];
    int sign = 1;

    struct DT *data = (struct DT *)param;
    cofactor(A, temp, data->i, data->j, N);
    sign = ((data->i + data->j) % 2 == 0) ? 1 : -1;
    adj[data->j][data->i] = sign * (determinant(temp, N - 1));

    pthread_exit(0);
}

int main()
{
    srand(time(NULL));

    struct timeval start, end;
    gettimeofday(&start, NULL);

    int sum[20];

    printf("Enter the %d x %d matrix:\n", N, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = 1 + rand() % 10;
        }
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    printf("\nTranspose:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", A[j][i]);
        printf("\n");
    }

    for (int i = 0; i < N; i++) //Diagonal 1
        sum[0] = sum[0] + A[i][i];

    for (int i = 0; i < N; i++) //Diagonal 2;
        sum[1] = sum[1] + A[i][N - 1 - i];

    if (sum[0] != sum[1])
        printf("\nNot a magic square.");
    else
    {
        int flag = 0;
        //Row Check
        for (int i = 0; i < N; i++)
        {
            int rowSum = 0;
            for (int j = 0; j < N; j++)
                rowSum += A[i][j];

            if (rowSum != sum[0])
                flag = 1;
            ;
        }

        //Column Check
        for (int i = 0; i < N; i++)
        {
            int colSum = 0;
            for (int j = 0; j < N; j++)
                colSum += A[j][i];

            if (colSum != sum[0])
                flag = 1;
            ;
        }

        if (flag == 1)
            printf("\nNot a magic square.");
        else
            printf("\nIt is a magic square with sum %d.", sum[0]);
    }

    pthread_t tid[N * N];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    if (N == 1)
    {
        adj[0][0] = 1;
    }
    else
    {

        int k = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                struct DT *data = (struct DT *)malloc(sizeof(struct DT));

                data->i = i;
                data->j = j;

                pthread_create(&tid[k], &attr, runnercofacval, data);
                k++;
            }
        }
        for (int i = 0; i < k; i++)
            pthread_join(tid[i], NULL);
    }

    /*
	printf("\nAdjoint:\n");
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}
	*/

    int det = determinant(A, N);

    printf("\nDeterminant: %d ", det);

    if (det == 0)
    {
        printf("\nInverse doesn't exist\n");
        return 0;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            inv[i][j] = adj[i][j] / ((float)det);

    printf("\n\nInverse:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%f ", inv[i][j]);
        printf("\n");
    }

    gettimeofday(&end, NULL);

    long seconds = (end.tv_sec - start.tv_sec);
    long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

    printf("Time elpased is %d seconds and %d micros\n", seconds, micros);

    return 0;
}
