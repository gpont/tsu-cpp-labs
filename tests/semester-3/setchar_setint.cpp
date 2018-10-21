#include <iostream>
#include "boolv.hpp"
#include "setchar.hpp"
#include "setint.hpp"

Boolv* Enter(Boolv& B, SetChar& S, SetInt& A)
{
	char s[256];
	int n;
	Boolv* p;
	cout << "Введите булев вектор: ";
	fflush(stdin);
	cin >> s;
	cout << "Введите интерпретацию: \n0 - булев вектор\n1 - множество символов\n2 - множество целых чисел" << endl;
	cin >> n;
	switch(n)
	{
		case 0:
		{
			B = Boolv(s); p = &B;
			break;
		}
		case 1:
		{
			S = SetChar(s); p = &S;
			break;
		}
		case 2:
		{
			A = SetInt(s); p = &A;
			break;
		}
	}
	return p;
}

int main()
{
	Boolv* p, B;
	SetChar S;
	SetInt A;
	int f = 1;
	while(f)
	{
		p = Enter(B, S, A);
		p->Out();
		cout << "Продолжить? <1/0>: ";
		cin >> f;
	}
	return 0;
}