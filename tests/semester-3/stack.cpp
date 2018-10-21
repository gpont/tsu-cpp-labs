#include "stack.hpp"

int main()
{
	const int n = 4;
	Stack<int> a(n);
	for (int i = 0; i < n; ++i)
		a.push(i);
	a.out();
	return 0;
}