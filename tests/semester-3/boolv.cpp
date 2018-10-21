#include <iostream>
#include "boolm.hpp"
#include "boolv.hpp"

using namespace std;

int main()
{
	Boolv a(19), b("011010"), c(b), d(9), e, f("101110"), g("11001100", 12);
	
	d.Set1(3); d.Set1(4); d.Set0(4);

	cout << "a: " << a << endl
		 << "b: " << b << endl
		 << "c: " << c << endl
		 << "d: " << d << endl
		 << "e: " << e << endl
		 << "f: " << f << endl;
	cout << "d.CheckIndex(8): " << d.CheckIndex(8) << endl
		 << "d.CheckIndex(47): " << d.CheckIndex(47) << endl
		 << "b.Weight(): " << b.Weight() << endl
		 << "b[2]: " << b[2] << endl
		 << "e=d: " << (e=d) << endl
		 << "b==c: " << (b==c) << endl
		 << "b==d: " << (b==d) << endl
		 << "b|f: " << (b|f) << endl
		 << "b&f: " << (b&f) << endl
		 << "b^f: " << (b^f) << endl
		 << "~b: " << (~b) << endl
		 << "d<<1: " << (d<<1) << endl
		 << "d>>4: " << (d>>4) << endl;

	return 0;
}