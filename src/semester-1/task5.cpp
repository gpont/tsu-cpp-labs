#include <cstdio>
#include "len.hpp"

int task5()
{
    int x[8] = {1,2,5,6,7,10,15,16};
    int y[5] = {2,3,7,10,15};

    int i = 0, j = 0;
    while (i < len(x) && j < len(y)-1)
    {
        if (x[i] <= y[j])
            ++i;
        else if (j >= len(y) || x[i] >= y[j+1])
            ++j;
        else
            printf("%d ", x[i++]);
    }

    return 0;
}
