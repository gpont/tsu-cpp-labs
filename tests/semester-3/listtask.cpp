#include <iostream>
#include "list.hpp"

int main()
{
	int* arr = new int[9]{2, 2, 1, 2, 2, 2, 5, 2, 2};
	List a(arr, 9);
	cout << a << endl;
	cout << (a.deleteFromMinToMax()) << endl;

	return 0;
}