#include <iostream>
#include "stack.hpp"
#include "hanoi_towers.hpp"

using namespace std;

void hanoi_towers(Stack<int>* s, int n, int from, int to, int help)
{
	if(n == 1)
	{
		s[to].push(s[from].pop());
		cout << "******" << endl;
		for (int i = 0; i < 3; ++i)
		{
			cout << (i+1) << ": ";
			s[i].out();
		}
	}
	else
	{
		hanoi_towers(s, n-1, from, help, to  );
		hanoi_towers(s, 1,   from, to,   help);
		hanoi_towers(s, n-1, help, to,   from);
	}
}