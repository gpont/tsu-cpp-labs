#include <iostream>
#include "setchar.hpp"

SetChar& SetChar::operator -=(SetChar& t)
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

ostream& operator <<(ostream& r, SetChar& s)
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