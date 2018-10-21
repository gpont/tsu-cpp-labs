#include <iostream>
#include <typeinfo>
#include "string.hpp"

using namespace std;

int main()
{
	char* test = new char[6]{'1','2','3','4','5'};
	String a, b(5), c(test), d(c), e;

	cout << "Enter string: ";
	cin >> e;

	cout << "a: " << a << endl
		 << "b: " << b << endl
		 << "c: " << c << endl
		 << "d: " << d << endl
		 << "e: " << e << endl
		 << "e.Length(): " << e.Length() << endl
		 << "c[4]: " << c[4] << endl
		 << "c == d: " << (c == d) << endl;
	cout << "c += d: " << (c += d) << endl
		 << "c.Length(): " << c.Length() << endl;
	cout << "~c: " << (~c) << endl
		 << "c + d: " << (c + d) << endl;
	cout << "c = d: " << (c = d) << endl;
	cout << "++c: " << (++c) << endl
		 << "(char*)c: " << (char*)c << endl
		 << "typeid((char*)c): " << typeid((char*)c).name() << endl
		 << "typeid((char*)c) == typeid(char*): " << (typeid((char*)c) == typeid(char*)) << endl
		 << "(int)d: " << (int)d << endl
		 << "typeid((int)d): " << typeid((int)d).name() << endl
		 << "typeid((int)d) == typeid(int): " << (typeid((int)d) == typeid(int)) << endl;

	return 0;
}