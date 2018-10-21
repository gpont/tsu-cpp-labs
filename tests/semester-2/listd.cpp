#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node
{
	struct Node *last = NULL;
    struct Node *next = NULL;
    char *s;
};

void print_list(struct Node *p)
{
	printf("List: ");
    struct Node *l=p;
    while(l)
    {
        printf("%s ", l->s);
        l = l->next;
    }
    putchar('\n');
}
 
int main()
{
	struct Node *st = 0;
	char *s = new char[100];
	fgets(s, 100, stdin);
	s[strlen(s)-1] = '\0';

	while(strcmp(s, "q"))
	{
		//print_list(st);

		bool in_list = false;
		struct Node *l = st;
	    while(l)
	    {
	    	struct Node *l_next = l->next;
	    	if(strcmp(s, l->s) == 0)
	    	{
	    		in_list = true;
	    		if(l->last != NULL)
	    			l->last->next = l->next;
	    		else
	    			st = l_next;
	    		
	    		if(l->next != NULL)
	    			l->next->last = l->last;
	        	delete l->s;
	        	delete l;
	        	break;
	    	}
	        l = l_next;
	    }
	    
	    if(!in_list)
	    {
	    	struct Node *el = new Node;
	    	el->s = new char[100];
	    	strcpy(el->s, s);
	    	el->next = st;
	    	if(st)
	    		st->last = el;
	    	st = el;
	    }

	    print_list(st);
	    fgets(s, 100, stdin);
	    s[strlen(s)-1] = '\0';
	}

	return 0;
}