#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "stack.cpp"

inline void str_append(char *s, char c, int n)
{
	s[n] = c;
	s[n+1] = '\0';
}

inline bool is_num(char c)
{
	return (c >= '0' && c <= '9');
}

inline bool is_var(char c)
{
	return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
}

inline bool is_func(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int order(char c)
{
	switch(c)
	{
		case '(': return 0;
		case ')': return 0;
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
	}
}

char *decrypt(char *s, int *table)
{
	struct Node *st = 0;
	bool table_b[256] = {0};

	char *out = new char[100];
	out[0] = '\0';

	for (int i = 0; i < strlen(s); ++i)
    {
        if(is_num(s[i]))
        	str_append(out, s[i], strlen(out));

        if(is_var(s[i]))
        {
        	if(!table_b[s[i]])
        	{
				printf("%c: ", s[i]);
        		scanf("%d", &table[s[i]]);
        		table_b[s[i]] = true;
        	}
        	str_append(out, s[i], strlen(out));
        }

        if(s[i] == '(')
        	st = push(st, (int)s[i]);

        if(s[i] == ')')
        {
        	++i;
        	while((char)top(st) != '(')
        	{
        		str_append(out, (char)top(st), strlen(out));
        		st = pop(st);
        	}
        	st = pop(st);
        }

        if(is_func(s[i]))
        {
        	while(order(s[i]) <= order(top(st)))
        	{
        		str_append(out, top(st), strlen(out));
        		st = pop(st);
        	}
        	st = push(st, (int)s[i]);
        }
        //printf("%2d: %c|%8s|", i, s[i], out);
        //print_list(st);
    }

    while(st != NULL)
    {
        str_append(out, top(st), strlen(out));
        st = pop(st);
    }
    printf("%s\n", out);
    return out;
}

int calc(char *s, int *table)
{
	int i = 0;
	struct Node *st = 0;

	int ax, bx;

	while(s[i] != '\0')
	{
		if(is_num(s[i]))
			st = push(st, (int)(s[i]-'0'));

		if(is_var(s[i]))
			st = push(st, table[s[i]]);

		if(is_func(s[i]))
		{
			ax = top(st);
			st = pop(st);
			bx = top(st);
			st = pop(st);
			switch(s[i])
			{
				case '+': st = push(st, bx+ax); break;
				case '-': st = push(st, bx-ax); break;
				case '*': st = push(st, bx*ax); break;
				case '/': st = push(st, bx/ax);
			}
		}
		//printf("%2d: ", i);
        //print_list(st);
		++i;
	}
	return top(st);
}

int main()
{
	char *s = new char[100];
	fgets(s, 100, stdin);
	int *table = new int[256];

	printf("%d\n", calc(decrypt(s, table), table));

	return 0;
}