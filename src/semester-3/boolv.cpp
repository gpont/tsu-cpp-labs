#include <iostream>
#include <cstring>
#include <iostream> 
#include <cmath>
#include "boolv.hpp"

using namespace std;

Boolv::Boolv(int nn)
{
    b = new byte[m=((nbit=nn)-1)/8+1]{0};
}

Boolv::Boolv(const char *s)
{
    b = new byte[m=((nbit=strlen(s))-1)/8+1]{0};

    for(int i = 0; i < nbit; ++i)
        if(s[i] == '1')
            Set1(i);
}

Boolv::Boolv(const char *s, int nn)
{
    int i;
    b = new byte[m=((nbit=nn)-1)/8+1]{0};

    for(i = 0; (unsigned int)i < (strlen(s) < (unsigned int)nbit ? strlen(s) : nbit); ++i)
        if(s[i] == '1')
            Set1(i);
}

Boolv::Boolv(Boolv &v)
{
    nbit = v.nbit;
    b = new byte[m=v.m];

    for(int i = 0; i < m; ++i)
        b[i] = v.b[i];
}

void Boolv::Set1(int k)
{
    if(CheckIndex(k))
        throw "Wrong index(from Boolv::Set1): "+to_string(k);

    int i = k / 8;

    b[i] = b[i] | (1 << (k % 8));
}

void Boolv::Set0(int k)
{
    if(CheckIndex(k))
        throw "Wrong index(from Boolv::Set0): "+to_string(k);

    int i = k / 8;

    b[i] = b[i] & ~(1 << (k % 8));
}

int Boolv::Weight()
{
    int k = 0;
    for(int i = 0; i < nbit; ++i)
        k += (*this)[i];

    return k;
}

int Boolv::operator [](int k)
{
    // cout << *this << endl;
    if(CheckIndex(k))
        throw "Wrong index(from Boolv::operator[]): "+to_string(k);

    int i = k / 8;
    return (b[i] & (1 << (k % 8))) ? 1 : 0;
}

Boolv& Boolv::operator =(Boolv &v)
{
    if(this == &v) return *this;
    if(b) delete []b;

    nbit = v.nbit;
    b = new byte[m=v.m];

    for(int i = 0; i < m; ++i)
        b[i] = v.b[i];

    return *this;
}

bool Boolv::operator ==(Boolv &v)
{
    int i;
    if(nbit == v.nbit)
    {
        for(i = 0; i < m && b[i] == v.b[i]; ++i);
        if(i == m)
            return true;
    }
    return false;
}

Boolv& Boolv::operator |(Boolv &v)
{
    Boolv* g = nbit > v.nbit ? new Boolv(*this) : new Boolv(v);

    for(int i = 0; i < (m > v.m ? m : v.m); ++i)
        g->b[i] = b[i] | v.b[i];

    return *g;
}

Boolv& Boolv::operator &(Boolv &v)
{
    Boolv* g = nbit > v.nbit ? new Boolv(*this) : new Boolv(v);

    for(int i = 0; i < (m > v.m ? m : v.m); ++i)
        g->b[i] = b[i] & v.b[i];

    return *g;
}

Boolv& Boolv::operator ^(Boolv &v)
{
    Boolv* g = nbit > v.nbit ? this : new Boolv(v);

    for(int i = 0; i < (m > v.m ? m : v.m); ++i)
        g->b[i] = b[i] ^ v.b[i];

    return *g;
}

Boolv& Boolv::operator ~()
{
    Boolv* g = new Boolv(*this);

    for(int i = 0; i < g->m; ++i)
        g->b[i] = ~g->b[i];

    if (g->nbit % 8)
    {
        byte mask = (1<<(g->nbit%8))-1;
        g->b[m+1] = g->b[m-1] & mask;
    }

    return *g;
}

Boolv& Boolv::operator >>(int k)
{
    Boolv* v = new Boolv(nbit);

    for(int i = k; i < nbit; ++i)
        if((*this)[i-k])
            v->Set1(i);
        else
            v->Set0(i);

    for(int i = 0; i < k; ++i)
        v->Set0(i);

    return *v;
}

Boolv& Boolv::operator <<(int k)
{
    Boolv* v = new Boolv(nbit);

    for(int i = 0; i < (nbit - k); ++i)
        if((*this)[i+k])
            v->Set1(i);
        else
            v->Set0(i);

    for(int i = nbit - k; i < nbit; ++i)
        v->Set0(i);

    return *v;
}

ostream& operator <<(ostream &r, Boolv &v)
{
    for(int i = 0; i < v.nbit; ++i)
        r << v[i];

    return r;
}