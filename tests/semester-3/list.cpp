#include <iostream>
#include "list.hpp"

int main()
{
	int* arr = new int[5]{5,4,3,2,1};
	Node* buf = new Node;
	List a, b(arr, 5), c(b), d(b);

	cout << "a: " << a << endl
		 << "b: " << b << endl
		 << "c: " << c << endl
		 << "d: " << d << endl
		 << "b.find(3): " << *(buf = b.find(3)) << endl
		 << "b[2]: " << b[2] << endl;
	cout << "b += 6: " << (b += 6) << endl
		 << "b + 6: " << (b + 6) << endl
		 << "b + c: " << (b + c) << endl
		 << "b - 6: " << (b - 6) << endl;
	cout << "b -= 2: " << (b -= 2) << endl
		 << "c == d: " << (c == d) << endl
		 << "c == a: " << (c == a) << endl;

	return 0;
}