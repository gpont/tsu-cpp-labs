#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
	double Im, Re;
public:
	Complex(int im = 0, int re = 0)
	{
		Im = im;
		Re = re;
	}

	double getReal()
	{
		return Re;
	}

	double getImage()
	{
		return Im;
	}

	void setImage(double im)
	{
		Im = im;
	}

	void setReal(double re)
	{
		Re = re;
	}

	void Display()
	{
		cout << Re << "+" << Im << "i" << endl;
	}

	bool Equal(Complex b)
	{
		return Im == b.Im && Re == b.Re;
	}

	void Add(Complex b)
	{
		Im += b.Im;
		Re += b.Re;
	}

	void Sub(Complex b)
	{
		Im -= b.Im;
		Re -= b.Re;
	}

	double Module()
	{
		return sqrt(Re*Re+Im*Im);
	}
};

#endif // COMPLEX_HPP