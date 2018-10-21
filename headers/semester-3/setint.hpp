#ifndef SETINT_HPP
#define SETINT_HPP

#include <iostream>
#include "boolv.hpp"

class SetInt : public Boolv
{
public:
	SetInt(int n=256) : Boolv(n) {}
	SetInt(const char* s) : Boolv(s) {}
	SetInt(Boolv& v) : Boolv(v) {}

	SetInt& operator +=(int c); // Добавление элемента
	SetInt& operator -=(SetInt& c); // Разность множеств

	int size() {return Weight();}
	bool empty() {return !Weight();}

	void Out()
	{
        cout << "Out from SetInt" << endl;
		cout << (*this) << endl;
	}

	friend ostream& operator << (ostream& r, SetInt& s);
};

#endif // SETINT_HPP