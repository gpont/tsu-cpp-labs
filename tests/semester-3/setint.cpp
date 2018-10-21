#include <iostream>
#include "boolv.hpp"
#include "setint.hpp"

int main()
{
	try
	{
		SetInt N1(100), N2(30);

		(N1 += 45) += 150;
		cout << "N1: " << N1 << endl;
	
		(N2 += 45) += 18;
		cout << "N2: " << N2 << endl;
	
		cout << "N1 & N2: " << *(new SetInt(N1 & N2)) << endl
			 << "N1 | N2: " << *(new SetInt(N1 | N2)) << endl;
		cout << "N1 -= N2: " << (N1 -= N2) << endl;
		cout << (N1 == N2 ? "N1 == N2" : "N1 != N2") << endl
			 << "N1: " << N1 << endl
			 << "N2: " << N2 << endl
			 << (N1[150] ? "150 in N1" : "150 not in N1") << endl
			 << (N1[10] ? "10 in N1" : "10 not in N1") << endl;
	}
	catch(string s)
	{
		cout << s;
	}
	return 0;
}