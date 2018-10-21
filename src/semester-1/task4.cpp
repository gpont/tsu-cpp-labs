#include <cstdio>

int task4()
{
    const int N = 1000;
    int arr[N];

    for (int i = 0; i < N; ++i)
        arr[i] = i;

    for (int i = 2; i < N; ++i)
        if(arr[i])
            for (int j = i*2; j < N; j += i)
                arr[j] = 0;

    for (int i = 0; i < N; i++)
        if(arr[i])
            printf("%d ", arr[i]);

    return 0;
}
