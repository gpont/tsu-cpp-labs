#include <iostream>
#include "boolm.hpp"

using namespace std;

BoolM::BoolM(int k, int l)
{
	v = new Boolv[m=k];
	Boolv w(n=l);
	for (int i = 0; i < m; ++i)
		v[i] = w;
}

BoolM::BoolM(BoolM& w)
{
	m = w.m; n = w.n;
	v = new Boolv[m];
	for (int i = 0; i < m; ++i)
		v[i] = w[i];
}

BoolM BoolM::operator=(BoolM w)
{
	if(this == &w) return *this;
	if(v) delete[]v;
	v = new Boolv[m=w.m];
	for (int i = 0; i < m; ++i)
		v[i] = w[i];
	return *this;
}

ostream & operator<<(ostream& r, BoolM& M)
{
	for (int i = 0; i < M.m; ++i)
		cout << M[i] << endl;
	return r;
}