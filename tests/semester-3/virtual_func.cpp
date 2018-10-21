#include <cstdlib>
#include <iostream>
#include "boolv.hpp"
#include "setint.hpp"
#include "setchar.hpp"

int main()
{
	Boolv *p, v("110011100001");
	SetInt a(100);
	SetChar s;

	srand(time(0));
	
	for (int i = 0; i < 10; ++i)
	{
		switch(rand()%3)
		{
			case 0:
				cout << "SetInt case" << endl;
				a += rand()%100;
				p = &a;
				break;
			case 1:
				cout << "SetChar case" << endl;
				s += 'a'+(char)rand()%26;
				p = &s;
				break;
			case 2:
				cout << "Boolv case" << endl;
				p = &v;
				break;
		}
		cout << (*p) << endl;
		p->Out();
	}
	cout << a << endl;
	cout << s << endl;
	return 0;
}