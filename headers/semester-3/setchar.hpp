#ifndef SETCHAR_HPP
#define SETCHAR_HPP

#include <iostream>
#include "boolv.hpp"

class SetChar : public Boolv
{
public:
	SetChar(int n=256) : Boolv(n) {}
	SetChar(const char* s) : Boolv(s) {}
	SetChar& operator +=(char c) // Добавление элемента
	{
		Set1((int)c);
		return *this;
	}
	
	SetChar& operator -=(SetChar& c); // Разность множеств

	int size() {return Weight();}
	bool empty() {return !Weight();}

	void Out()
	{
        cout << "Out from SetChar" << endl;
		cout << (*this) << endl;
	}

	friend istream& operator >> (istream& r, SetChar& s);
	friend ostream& operator << (ostream& r, SetChar& s);
};

#endif // SETCHAR_HPP