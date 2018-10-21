#ifndef BOOLM_HPP
#define BOOLM_HPP

#include <iostream>
#include "boolv.hpp"

using namespace std;

class BoolM
{
	Boolv *v;
	int m,n;
public:
	BoolM(int k, int l);
	BoolM(BoolM&);

	~BoolM() {if(v) delete[] v; v=0;}
	Boolv& operator[](int l)
	{
		if(l < 0 || l >= m) throw "Index error";
		return v[l];
	}
	BoolM operator=(BoolM);
	friend ostream & operator<<(ostream&, BoolM&);
};

#endif // BOOLM_HPP