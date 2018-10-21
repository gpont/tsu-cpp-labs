#include <iostream>
#include "array.hpp"

using namespace std;

int main()
{
	srand(time(0));

	Array<int> a1(500, 1, 100), b1(500, 1, 100), c1(500, 1, 100), d1(500, 1, 100), e1(500, 1, 100),
			   a2(a1), b2(b1), c2(c1), d2(d1), e2(e1);

	cout << "Before sorting: " << endl;
	cout << "a1: " << a1 << endl;
	cout << "b1: " << b1 << endl;
	cout << "c1: " << c1 << endl;
	cout << "d1: " << d1 << endl;
	cout << "e1: " << e1 << endl;

	a1.HeapSort();
	b1.ShellSort();
	c1.ShakerSort();
	d1.QuickSort(0, d1.Length()-1);
	e1.RadixSort(0, e1.Length()-1, 6);

	cout << "After sorting: " << endl;
	cout << "a1: " << a1 << endl;
	cout << "b1: " << b1 << endl;
	cout << "c1: " << c1 << endl;
	cout << "d1: " << d1 << endl;
	cout << "e1: " << e1 << endl;
	
	cout << "Test: " << a1.Test() << ", Equal: " << (a1 == a2) << " (HeapSort)" << endl;
	cout << "Test: " << b1.Test() << ", Equal: " << (b1 == b2) << " (ShellSort)" << endl;
	cout << "Test: " << c1.Test() << ", Equal: " << (c1 == c2) << " (ShakerSort)" << endl;
	cout << "Test: " << d1.Test() << ", Equal: " << (d1 == d2) << " (QuickSort)" << endl;	
	cout << "Test: " << e1.Test() << ", Equal: " << (e1 == e2) << " (RadixSort)" << endl;

	return 0;
}
