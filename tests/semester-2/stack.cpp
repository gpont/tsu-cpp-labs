#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <assert.h>

struct Node
{
    struct Node *next = NULL;
    int k;
};


int top(struct Node *s)
{
    if (s)
        return s->k;
    else
        return 0;
}

struct Node* pop(struct Node *s)
{
    int k;
    if(s)
    {
        struct Node *el = s->next;
        delete s;
        return el;
    }
    return NULL;
}

struct Node* push(struct Node *s, int k)
{
    struct Node *el = new Node;
    el->k = k;
    el->next = s;
    return el;
}

void print_list(struct Node *p)
{
    struct Node *l=p;
    while(l)
    {
        printf("%d ", top(l));
        l = l->next;
    }
    putchar('\n');
}

struct Node* random_list(int n)
{
    struct Node *list = 0, *p;
    for(int i = 0; i < n; ++i)
        list = push(list, rand()%30);

    return list;
}

/*
int main()
{
    const int n = 10;
    struct Node *s = 0, *s1 = 0, *s2 = 0;
    int k;

    srand(time(0));
    s = random_list(n);
    print_list(s);

    while(s != NULL)
    {
        k = top(s);
        if(k != 0)
            if(k % 2 == 0)
                s1 = push(s1, k);
            else
                s2 = push(s2, k);
        s = pop(s);
    }

    print_list(s1);
    print_list(s2);

    return 0;
}
*/
