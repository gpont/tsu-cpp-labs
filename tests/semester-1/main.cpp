#include <cstdio>
#include <unistd.h>
#include "task3.hpp"
#include "task4.hpp"
#include "task5.hpp"
#include "task6.hpp"
#include "task7.hpp"

int input_error()
{
    printf("Usage: index -t task_number\n");
    return 1;
}

int call_task(char in)
{
    switch(in)
    {
        case '3': return task3();
        case '4': return task4();
        case '5': return task5();
        case '6': return task6();
        case '7': return task7();
        default: return input_error();
    }
}

int main(int argc, char const *argv[])
{
    if(argc == 1)
        return input_error();

    int opt;
    while((opt = getopt(argc, (char **)argv, "t:")) != -1)
    {
        switch(opt)
        {
            case 't':
                return call_task(*optarg);
                break;
            case '?':
                return input_error();
                break;
        }
    }

    return 0;
}
