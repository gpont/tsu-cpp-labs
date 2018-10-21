#include <iostream>
#include "stack.hpp"
#include "hanoi_towers.hpp"

int main()
{
	const int n = 4;
	Stack<int> a[3];
	
	for(int i=0; i<n; ++i)
		a[0].push(n-i);

	hanoi_towers(a, n, 0, 1, 2);

	return 0;
}