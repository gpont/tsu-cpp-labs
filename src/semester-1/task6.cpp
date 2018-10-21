#include <cstdio>
#include <vector>
#include "len.hpp"

using namespace std;

int task6()
{
    int arr[] = {1,2,4,2,4,4,2,3};
    vector<int> buf;

    int max = arr[0];

    for (int i = 0; i < len(arr); ++i)
        if (arr[i] > max)
        {
            max = arr[i];
            buf.clear();
            buf.push_back(i);
        }
        else if (arr[i] == max)
            buf.push_back(i);

    for(vector<int>::iterator it = buf.begin(); it != buf.end(); printf("%d ", *(it++)));

    return 0;
}
