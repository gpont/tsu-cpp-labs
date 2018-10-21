#ifndef SET_H
#define SET_H

#include <iostream>
#include "boolv.hpp"

/**
 * Объявляем шаблонный класс Set для использования
 * в объявлении перегрузки потокового в/в
 */
template <class X>
class Set;

/**
 * Объявляем шаблонную перегрузку потокового ввода/вывода
 * для использования в описании Array друзей, порожденных
 * шаблоном, а не всего шаблона потокового в/в
 */
template <class X>
istream& operator >>(istream& r, Set<X>& b);

template <class X>
ostream& operator <<(ostream& r, Set<X>& b);

/**
 * Объекты класса - множества, представленные булевыми векторами.
 * Элементы множества могут быть char и int, корректность остальных типов не проверена
 */
template <class X>
class Set
{
	Boolv v;
	int m; // Размер булевого вектора - максимальный диапазон значений
public:
	Set(int n=256) : v(n), m(n) {}
	Set(Set<X>& a) : v(a.v), m(a.m) {}

	Set<X>& operator &(Set<X>&); // Пересечение множеств
	Set<X>& operator |(Set<X>&); // Объединение множеств
	Set<X>& operator +=(X c); // Добавление элемента
	Set<X>& operator -=(Set<X>& c); // Разность множеств
	bool operator ==(Set<X> t) {return v == t.v;}

	int size() {return v.Weight();}
	bool empty() {return !v.Weight();}

	friend istream& operator >> <X>(istream& r, Set<X>& s);
	friend ostream& operator << <X>(ostream& r, Set<X>& s);
};

// Реализация

template <class X>
Set<X>& Set<X>::operator &(Set<X>& t)
{
	if(m == t.m)
	{
		Set<X>* r = new Set<X>(m > t.m ? m : t.m);
		r->v = v & t.v;
		return *r;
	}
	int k = m < t.m ? m : t.m;
	Set<X>* r = new Set(k);
	for (int i = 0; i < k; ++i)
		if(v[i] & t.v[i])
			r->v.Set1(i);
	return *r;
}

template <class X>
Set<X>& Set<X>::operator  |(Set<X> &t)
{
	Set<X>* r = new Set<X>(m > t.m ? m : t.m);
	r->v = v | t.v;
	return *r;
}

template <class X>
Set<X>& Set<X>::operator +=(X c)
{
	int k = (int)(sizeof(c) == sizeof(char) ? byte(c) : c);

	if(k < m)
		v.Set1(k);
	else
	{
		Set<X> d(k+1);
		*this = d | *this;
	}
	return *this;
}

template <class X>
Set<X>& Set<X>::operator -=(Set<X>& t)
{
	int k = m < t.m ? m : t.m;
	for (int i = 0; i < k; ++i)
		if(t.v[i])
			this->v.Set0(i);
	return *this;
}

template <class X>
istream& operator >>(istream& r, Set<X>& s)
{
	X buf;
	r >> buf;
	while(buf != (X)'q')
	{
		s += buf;
		r >> buf;
	}
	return r;
}

template <class X>
ostream& operator <<(ostream& r, Set<X>& s)
{
	for (int i = 0; i < s.m; ++i)
		if(s.v[i])
			r << (X)i << " ";
	r << endl;
	return r;
}

#endif // SET_H