#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

/**
 * Объявляем шаблонный класс Array для использования
 * в объявлении перегрузки потокового в/в
 */
template <class X>
class Array;

/**
 * Объявляем шаблонную перегрузку потокового ввода/вывода
 * для использования в описании Array друзей, порожденных
 * шаблоном, а не всего шаблона потокового в/в
 */
template <class X>
istream& operator >>(istream& r, Array<X>& b);

template <class X>
ostream& operator <<(ostream& r, Array<X>& b);

template <class X>
class Array
{
	int m;
	X *a;
public:
	/**
	 * @param mm - длина массива
	 * @param t: {1 - произвольный., 2 - по возр., 3 - по убыв.}
	 * @param d - диапазон для произвольного массива
	 */
	Array(int mm=1, int t=1, int d=10);
	Array(X*, int);
	Array(Array<X> &);
	~Array() {if(a) delete[] a; a=0;};
	
	bool Test(); // упорядочен ли
	X Max();
	int Length() {return m;}
	
	X& operator[](int);
	Array<X>& operator+(Array<X>&);
	Array<X>& operator=(Array<X>&);
	Array<X>& operator-(int);
	Array<X>& operator()(int k=0);
	bool operator==(Array<X>);

	void swap(int i, int j)
	{
		int buf = a[i];
		a[i] = a[j];
		a[j] = buf;
	}

	void BarrierSort();
	void ShellSort();
	void ShakerSort();

	void HeapInsert(int, int);
	void BuildHeap();
	void HeapSort();

	void QuickSort(int left, int right);
	void RadixSort(int left, int right, int radix);

	friend istream& operator >> <X>(istream& r, Array<X>& b);
	friend ostream& operator << <X>(ostream& r, Array<X>& b);
};

// Реализация

template <class X>
Array<X>::Array(int mm, int t, int d)
{
	a = new X[m=mm];
	switch(t)
	{
		case 1:
			for (int i = 0; i < m; ++i)
				a[i] = rand()%d;
			break;
		case 2:
			a[0] = rand()%5;
			for (int i = 1; i < m; ++i)
				a[i] = a[i-1]+rand()%10;
			break;
		case 3:
			a[m-1] = rand()%5;
			for (int i = m-2; i >= 0; --i)
				a[i] = a[i+1]+rand()%5;
			break;
		default:
			for (int i = 0; i < m; ++i)
				a[i] = 0;
	}
}

template <class X>
Array<X>::Array(X* b, int mm)
{
	a = new X[m=mm];
	for (int i = 0; i < m; ++i)
		a[i] = b[i];
}

template <class X>
Array<X>::Array(Array& b)
{
	a = new X[m=b.m];
	for (int i = 0; i < m; ++i)
		a[i] = b.a[i];
}

template <class X>
bool Array<X>::Test()
{
	for (int i = 0; i < m-1; ++i)
		if (a[i] > a[i+1])
			return false;
	return true;
}

template <class X>
X Array<X>::Max()
{
	X max = a[0];
	for (int i = 1; i < m; ++i)
		if (a[i] > max)
			max = a[i];
	return max;
}

template <class X>
X& Array<X>::operator [](int k)
{
	if (k < 0 || k > m)
		throw "Index error!";
	return a[k];
}

template <class X>
Array<X>& Array<X>::operator +(Array& b)
{
	if (!Test() || !b.Test())
		throw "Array ordering error!";
	Array<X>* c = new Array(m+b.m);
	int i,j,k;
	for (i=0,j=0,k=0; i < m && j < b.m; ++k)
		c->a[k] = a[i] <= b.a[j] ? a[i++] : b.a[j++];
	while (i < m) c->a[k++] = a[i++];
	while (j < b.m) c->a[k++] = b.a[j++];
	return *c;
}

template <class X>
Array<X>& Array<X>::operator =(Array& b)
{
	if(&b == this) return *this;
	if(a) delete[] a;
	a = new X[m=b.m];
	for (int i = 0; i < m; ++i)
		a[i] = b.a[i];
	return *this;
}

template <class X>
Array<X>& Array<X>::operator-(int k)
{
	for (int i = 0; i < m;)
		if (a[i] == k)
		{
			for(int j = i+1; j < m; ++j)
				a[j-1] = a[j];
			--m;
		}
		else ++i;
	return *this;
}

template <class X>
Array<X>& Array<X>::operator()(int k)
{
	for (int i = 0; i < m; ++i)
		a[i] = k;
	return *this;
}

template <class X>
bool Array<X>::operator==(Array b)
{
	Array<X> buf(*this);
	if (m != b.m)
		return false;

	for (int i = 0; i < buf.m; ++i)
	{
		int c = buf[i];
		if ((buf-c).m != (b-c).m)
			return false;
	}
	return true;
}

template <class X>
void Array<X>::BarrierSort()
{
	int* c = new int[m+1];
	for (int i = 0; i < m; ++i)
		c[i+1] = a[i];

	for (int i = 1; i < m+1; ++i) 
	{
		int j;
		c[0] = c[i];
		for (j = i-1; c[0] < c[j]; --j)
			c[j+1] = c[j];
		
		c[j+1] = c[0];
	}

	for (int i = 0; i < m; ++i)
		a[i] = c[i+1];
	delete[] c;
}

template <class X>
void Array<X>::ShellSort()
{
	int buf;
	for (int k = m/2; k > 0; k /= 2)
		for (int i = k; i < m; ++i)
		{
			buf = a[i];
			int j;
			for (j = i; j >= k && buf < a[j-k]; j -= k)
				a[j] = a[j-k];
			
			a[j] = buf;
		}
}

template <class X>
void Array<X>::HeapInsert(int i, int n)
{
	int buf = a[i];
	while (2*i+1 < n)
	{
		int left = 2*i+1;
		int right = 2*i+2;
		int j = left;
		if (right < n && a[right] > a[left])
			j = right;

		if (buf >= a[j]) break;
		a[i] = a[j];
		i = j;
	}
	a[i] = buf;
}

template <class X>
void Array<X>::BuildHeap()
{
	for (int i = (m-1)/2; i >= 0; --i)
		HeapInsert(i, m);
}

template <class X>
void Array<X>::HeapSort()
{
	BuildHeap();
	for (int i = m-1; i > 0; --i)
	{
		swap(i, 0);
		HeapInsert(0, i);
	}
}

template <class X>
void Array<X>::ShakerSort()
{
	for (int left = 0, right = m-1; left < right;)
	{
		int buf;
		for (int i = left; i < right; ++i)
			if (a[i+1] < a[i])
				swap(i, buf=(i+1));
		
		right = buf;

		for (int i = right; i > left; --i)
			if (a[i-1] > a[i])
				swap(buf=(i-1), i);
		
		left = buf;
	}
}

template <class X>
void Array<X>::QuickSort(int left, int right)
{
	int i = left, j = right;
	int pivot = a[(left + right) / 2];

	// partition
	while (i <= j) {
		while (a[i] < pivot) ++i;
		while (a[j] > pivot) --j;
		if (i <= j)
			swap(i++, j--);
	};

	// recursion
	if (left < j) QuickSort(left, j);
	if (i < right) QuickSort(i, right);
}

template <class X>
void Array<X>::RadixSort(int left, int right, int radix)
{
	if (left >= right || radix < 0) return;
	int mask = 1 << radix, i = left, j = right;

	// partition
	while (i <= j) {
		while (i <= j && !(a[i] & mask)) ++i;
		while (i <= j && (a[j] & mask)) --j;
		if (i < j)
			swap(i++, j--);
	};

	// recursion
	if (left < j) RadixSort(left, j, radix-1);
	if (i < right) RadixSort(i, right, radix-1);
}

template <class X>
istream& operator>>(istream& r, Array<X>& b)
{
	for (int i = 0; i < b.m; ++i)
		r >> b[i];
	return r;
}

template <class X>
ostream& operator<<(ostream& r, Array<X>& b)
{
	for (int i = 0; i < b.m; ++i)
		r << b[i] << " ";
	r << endl;
	return r;
}

#endif // ARRAY_HPP