#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "len.hpp"

void bubbleSort(int *a, int n)
{
    for(int i = 0; i < n-1; ++i)
       for(int j = 0 ; j < n-i-1; ++j)
           if(a[j] > a[j+1])
           {
               int tmp = a[j];
               a[j] = a[j+1];
               a[j+1] = tmp;
           }
}

void insertSort(int *a, int n)
{
    int x, j;
    for (int i = 0; i < n; ++i)
    {
        x = a[i];
        for (j = i-1; j >= 0 && a[j] > x; --j)
            a[j+1] = a[j];
        a[j+1] = x;
    }
}

void selectSort(int *a, int n)
{
    for (int i = 0; i < n-1; ++i)
    {
        int min_i = i;

    	for (int j = i+1; j < n; ++j)
    		if (a[j] < a[min_i])
    			min_i = j;

    	int tmp = a[i];
    	a[i] = a[min_i];
    	a[min_i] = tmp;
    }
}

int task7()
{
    const int N = 10000;
    int a[N], b[N], c[N];
    clock_t startTime, bubbleTime, insertTime, selectTime;

    srand(time(NULL));

    for(int i = 0; i < len(a); ++i)
        a[i] = b[i] = c[i] = rand() % 1000 + 1;

    startTime = clock();
    bubbleSort(a, len(a));
    bubbleTime = clock()-startTime;

    startTime = clock();
    insertSort(b, len(b));
    insertTime = clock()-startTime;

    startTime = clock();
    selectSort(c, len(c));
    selectTime = clock()-startTime;

    printf("Bubble sort: %fs.\nInsert sort: %fs.\nSelect sort: %fs.\n", ((float)bubbleTime)/CLOCKS_PER_SEC, ((float)insertTime)/CLOCKS_PER_SEC, ((float)selectTime)/CLOCKS_PER_SEC);

    return 0;
}
