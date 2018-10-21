#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <class T>
class Stack
{
	int size_max, k;
	T* s;
public:
	Stack(int n=4);
	Stack(Stack<T>&);

	~Stack() {if(s) delete[] s; s = 0;}
	
	Stack<T> operator =(Stack<T>&);

	void push(T c)
	{
		if(k == size_max)
			throw "Stack overflow!";
		s[k++] = c;
	}
	bool empty() {return k ? 0 : 1;}
	T pop()
	{
		if(!empty()) return s[--k];
		throw "Stack is empty!";
	}
	T top()
	{
		if(!empty()) return s[k-1];
		throw "Stack is empty!";
	}
	void out()
	{
		for (int i = 0; i < k; ++i)
			cout << s[i] << " ";
		cout << endl;
	}
};

// Реализация

template <class T>
Stack<T>::Stack(int n)
{
	s = new T[size_max=n];
	k = 0;
}

template <class T>
Stack<T>::Stack(Stack<T>& t)
{
	s = new T[size_max=t.size_max];
	k = t.k;
	for (int i = 0; i < k; ++i)
		s[i] = t.s[i];
}

template <class T>
Stack<T> Stack<T>::operator =(Stack<T>& t)
{
	if(this == &t) return *this;
	if(s) delete[] s;
	s = new T[size_max=t.size_max];
	k = t.k;
	for (int i = 0; i < k; ++i)
		s[i] = t.s[i];
	return *this;
}

#endif // STACK_H