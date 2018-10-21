#include <cstdio>
#include <cmath>
#include <iostream>
#include "list.hpp"
#include "set.hpp"

List::List(int* arr, int len)
{
	beg = new Node, end = new Node;
	beg->next = end;
	end->prev = beg;
	for (int i = 0; i < len; ++i)
		*this += arr[i];
}

List::List(List &l)
{
	beg = new Node, end = new Node;
	beg->next = end;
	end->prev = beg;
	for (Node* p = l.beg->next; p != l.end; p = p->next)
		*this += p->key();
}

List::~List()
{
	Node* buf;
	for (Node* p = beg->next; p != end; p = p->next, delete buf)
		buf = p;
}

Node* List::find(int k)
{
	Node* p = beg;
	while(p->key() != k && p != end)
		p = p->next;
	return p != end ? p : nullptr;
}

List& List::deleteFromMinToMax()
{
	if(isEmpty()) throw "List is empty!";

	bool isMinFirst = false;
	Node *minNode = beg->next, *maxNode = beg->next;
	for (Node* p = beg->next; p != end; p = p->next)
	{
		if(p->key() > maxNode->key())
		{
			maxNode = p;
			isMinFirst = true;
		}
		if(p->key() < minNode->key())
		{
			minNode = p;
			isMinFirst = false;
		}
	}

	Node *buf, *from = (isMinFirst ? minNode : maxNode),
		 *to = (isMinFirst ? maxNode : minNode);

	for (Node* p = from->next; p != to; p = p->next, delete buf)
	{
		buf = p;
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
	return *this;
}

List& List::operator =(List &l)
{
	if(this == &l)
		return *this;
	this->~List();
	List* new_list = new List(l);
	beg = new_list->beg;
	end = new_list->end;
	return *this;
}

Node& List::operator [](int k)
{
	Node* p = beg->next;
	for (int i = 0; i < k; ++i)
		p = p == end ? beg->next : p->next;
	return *p;
}

List& List::operator +=(int k)
{
	Node* p = new Node(k);
	p->next = end;
	p->prev = end->prev;
	p->prev->next = p;
	end->prev = p;
	return *this;
}

List& List::operator +(int k)
{
	List* l = new List(*this);
	l += k;
	return *this;
}

List& List::operator +(List& l)
{
	List* ret = new List(*this);

	for (Node* p = l.beg->next; p != l.end; p = p->next)
		*ret += p->key();

	return *ret;
}

List& List::operator -(int k)
{
	List* l = new List(*this);
	Node* p;
	while((p = l->find(k)))
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
	}
	return *l;
}

List& List::operator -=(int k)
{
	// Поиск элемента с индексом k
	Node* p; int i;
	for (p=beg->next, i=0; p!=end && i<k; p=p->next, ++i);

	if(i < k) throw "Index error"; // Элемент не найден
	
	// Удаление элемента
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	return *this;
}

bool List::operator ==(List& l)
{
	Set<int> s1, s2;
	for (Node *p1 = beg->next; p1 != end; p1 = p1->next)
		s1 += p1->key();

	for (Node *p2 = l.beg->next; p2 != l.end; p2 = p2->next)
		s2 += p2->key();
	
	return (s1 == s2);
}


istream & operator >>(istream& r, Node& l)
{
	return (r >> l.n);
}

ostream & operator <<(ostream& r, Node& l)
{
	return (r << l.n);
}

istream & operator >>(istream& r, List& l)
{
	int k;
	for (Node* p = l.beg->next; p != l.end; p = p->next)
	{
		r >> k;
		l += k;
	}
	return r;
}

ostream & operator <<(ostream& r, List& l)
{
	for (Node* p = l.beg->next; p != l.end; p = p->next)
		r << *p << " ";
	return r;
}
