#include <iostream>
#include "setint.hpp"

SetInt& SetInt::operator -=(SetInt& t)
{
	int i = 0;
	while(!(CheckIndex(i) || t.CheckIndex(i)))
	{
		if(t[i])
			Set0(i);
		++i;
	}
	return *this;
}

SetInt& SetInt::operator +=(int k)
{
	if(CheckIndex(k))
	{
		SetInt new_ins(k+1);
		SetInt* new_set = new SetInt(new_ins | *this);
		*this = *new_set;
	}
	Set1(k);
	return *this;
}

ostream& operator <<(ostream& r, SetInt& s)
{
	int i = 0;
	while(!s.CheckIndex(i))
	{
		if(s[i])
			r << i << " ";
		++i;
	}
	return r;
}