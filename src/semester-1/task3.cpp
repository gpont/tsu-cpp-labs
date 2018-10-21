#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "len.hpp"

int task3()
{
    const int N = 20;
    int arr[N];

    srand(time(NULL));

    for (int i = 0; i < N; ++i)
    {
        arr[i] = rand()%10+1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    int start = 0, end = 0;
    int start_max = 0, end_max = 0;
    bool divider = false;

    for (int i = 1; i < N; ++i)
        if (arr[i] % arr[i-1] == 0)
        {
            if (divider)
            {
                end = i;
            } else
            {
                start = i-1;
                end = i;
                divider = true;
            }
        } else
        {
            if (end-start > end_max-start_max)
            {
                start_max = start;
                end_max = end;
            }
            divider = false;
        }

    if(end_max-start_max > 0)
        for (int i = start_max; i <= end_max; ++i)
            printf("%d ", arr[i]);
    else
        printf("There is no such numbers.");

    return 0;
}
