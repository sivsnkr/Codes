#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pthread.h>
struct Data
{
	int *a;
	int beg, end, n;
};

int tmin, min, q1, median, q2, max, tmax, iqr;

void *medianq2Func(void *par)
{
	struct Data *d = par;
	int size = d->end - d->beg + 1;
	int data[size];
	for (int i = d->beg; i <= d->end; i++)
	{
		data[i - d->beg] = d->a[i];
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", data[i]);
	}
	//int median;
	if (size % 2 != 0)
	{
		q2 = data[size / 2];
	}
	else
	{
		q2 = (data[size / 2 - 1] + data[size / 2]) / 2;
	}
}

void *medianq1Func(void *par)
{
	struct Data *d = par;
	int size = d->end - d->beg + 1;
	int data[size];
	for (int i = d->beg; i <= d->end; i++)
	{
		data[i - d->beg] = d->a[i];
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", data[i]);
	}
	//int median;
	if (size % 2 != 0)
	{
		q1 = data[size / 2];
	}
	else
	{
		q1 = (data[size / 2 - 1] + data[size / 2]) / 2;
	}
}

void *medianFunc(void *par)
{
	struct Data *d = par;
	int size = d->end - d->beg + 1;
	int data[size];
	for (int i = d->beg; i <= d->end; i++)
	{
		data[i - d->beg] = d->a[i];
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d ", data[i]);
	}
	//int median;
	if (size % 2 != 0)
	{
		median = data[size / 2];
	}
	else
	{
		median = (data[size / 2 - 1] + data[size / 2]) / 2;
	}
}

int main()
{
	int n = 100;
	// scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++)
	{
		//scanf("%d", &a[i]);
		a[i] = rand() % 100;
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	tmin = a[0];
	tmax = a[n - 1];
	//for(int i=0;i<n;i++)
	//	printf("%d ",a[i]);
	struct Data d;
	d.a = a;
	d.n = n;
	d.beg = 0;
	d.end = n - 1;
	pthread_t t1;
	pthread_create(&t1, NULL, medianFunc, &d);

	//int med=median;

	pthread_t tid[2];

	struct Data d1;
	d1.a = a;
	d1.n = n;
	d1.beg = 0;
	d1.end = n / 2;

	pthread_create(&tid[0], NULL, medianq1Func, &d1);

	//q1=median;

	struct Data d2;
	d2.a = a;
	d2.n = n;
	d2.beg = n / 2 + 1;
	d2.end = n - 1;

	pthread_create(&tid[1], NULL, medianq2Func, &d2);
	//q2=median;
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	pthread_join(t1, NULL);

	iqr = abs(q1 - q2);
	printf("iqr:%d", iqr);
	min = q1 - 1.5 * iqr;
	max = q2 + 1.5 * iqr;
	if (tmin > min)
		min = tmin;
	if (tmax < max)
		max = tmax;
	printf("\nmin: %d\nq1:%d\nmed:%d\nq2:%d\nmax:%d\n", min, q1, median, q2, max);
	return 0;
}
