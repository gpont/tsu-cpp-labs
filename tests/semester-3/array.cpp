#include <iostream>
#include "array.hpp"

using namespace std;

int main()
{
	int* test_arr = new int[10]{1,2,1,2,1,2,1,2,1,2};
	int* h1 = new int[4]{1,2,2,3};
	int* h2 = new int[4]{1,2,3,3};
	Array<int> a(10), b(10, 2), c(10, 3), d(test_arr, 10), e(a), f(10), g(8), h1_array(h1, 4), h2_array(h2, 4);

	//g = h1_array+h2_array;

	e.BarrierSort();

	cout << "a: " << a
		 << "b: " << b
		 << "c: " << c
		 << "d: " << d
		 << "e: " << e
		 << "a.Max(): " << a.Max() << endl
		 << "a.Test(): " << a.Test() << endl
		 << "b.Test(): " << b.Test() << endl
		 << "a[5]: " << a[5] << endl;
	//	 << "g: " << g;
	cout << "b=b: " << (b=b);
	cout << "b=c: " << (b=c);
	cout << "a-a[0]: " << a-a[0]
		 << "c(): " << c()
		 << "h1_array==h2_array: " << (h1_array==h2_array) << endl
		 << "a==e: " << (a==e) << endl
		 << "a==d: " << (a==d) << endl
		 << "Enter f: ";
	cin >> f;
	cout << "f: " << f;

	return 0;
}