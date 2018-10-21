#ifndef BOOLV_HPP
#define BOOLV_HPP

#include <sstream>

using namespace std;

typedef unsigned char byte;

class Boolv
{
    byte *b;
    int m, nbit; // m - кол-во байтов под вектор

public:
    Boolv(int nn = 1); // nn - длина вектора
    Boolv(const char*);
    Boolv(const char*, int);
    Boolv(Boolv&);
    ~Boolv() {if(b) {delete[] b; b = 0;}};

    void Set1(int); // установить бит в 1
    void Set0(int); // установить бит в 0

    bool CheckIndex(int k) {return (k < 0 || k >= nbit);};
    int Weight();

    int operator [](int);
    Boolv& operator =(Boolv&);
    bool operator ==(Boolv&);
    Boolv& operator |(Boolv&);
    Boolv& operator &(Boolv&);
    Boolv& operator ^(Boolv&);
    Boolv& operator ~();
    Boolv& operator <<(int);
    Boolv& operator >>(int);

    virtual void Out() // вывод для виртуальной функции
    {
        cout << "Out from Boolv" << endl;
        cout << (*this) << endl;
    }

    friend ostream& operator <<(ostream&, Boolv&);
};

#endif // BOOLV_H