#include <iostream>
#include "complex.hpp"

using namespace std;

int main()
{
	Complex a(1,1);
	Complex b(3,3);

	cout << "a = "; a.Display();
	cout << "b = "; b.Display();

	cout << "Im(a) = " << a.getImage() << endl;
	cout << "Re(a) = " << a.getReal() << endl;
	a.setImage(2);
	a.setReal(2);
	cout << "a.setImage(2), a.setReal(2): a = ";
	a.Display();

	cout << "Equal(a, b) = " << a.Equal(b) << endl;
	cout << "Equal(a, a) = " << a.Equal(a) << endl;

	cout << "a + b = ";
	a.Add(b);
	a.Display();

	cout << "a = "; a.Display();
	cout << "a - b = ";
	a.Sub(b);
	a.Display();

	cout << "|b| = " << b.Module() << endl;
	
	return 0;
}