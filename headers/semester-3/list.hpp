#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

using namespace std;

class List;

class Node
{
	int n;
	Node* next = nullptr;
	Node* prev = nullptr;

	friend class List;
	friend istream & operator >>(istream& r, Node& l);
	friend ostream & operator <<(ostream& r, Node& l);
	friend ostream & operator <<(ostream& r, List& l);
	friend istream & operator >>(istream& r, List& l);

public:
	Node() : n(0) {}
	Node(int k) : n(k) {}
	int& key() {return n;}
};

class List
{
protected:
	Node *beg, *end;
public:
	List()
	{
		beg = new Node, end = new Node;
		beg->next = end;
		end->prev = beg;
	}
	List(int*, int);
	List(List &l);
	virtual ~List();

	bool isEmpty() { return beg->next == end; }
	Node* find(int k);
	
	List& deleteFromMinToMax(); // Удаляет все элементы между минимумом и максимумом

	List& operator =(List&);
	Node& operator [](int k);
	List& operator +=(int); // добавление элемента в хвост
	List& operator +(int); // добавление элемента в голову
	List& operator +(List&);
	List& operator -(int); // убрать все вхождения элемента с заданным ключом
	List& operator -=(int); // убирает элемент с заданным индексом из списка
	bool operator ==(List&); // эквивалентность списков

	friend istream & operator >>(istream& r, List& l);
	friend ostream & operator <<(ostream& r, List& l); 
};

#endif