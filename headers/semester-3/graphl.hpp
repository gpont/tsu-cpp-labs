#ifndef GRAPHL_HPP
#define GRAPHL_HPP

#include <vector>
#include <iostream>

class TopList;
class Leader;

class Trailer
{
	Leader *ld;
	Trailer *next;

public:
	Trailer(Leader* l = NULL, Trailer* t = NULL)
	{
		ld = l;
		next = t;
	}

	friend class TopList;
	friend std::ostream& operator <<(std::ostream &, Leader&);
};

class Leader
{
	int key;
	int count;

	Leader* next;
	Trailer* tr;

	friend class TopList;

public:
	Leader(int k = 0,Leader* p = NULL)
	{
		key = k;
		count = 0;
		next = p;
		tr = NULL;
	}

	void operator ++() // инфиксный инкремент
	{
		++count;
	}

	void operator +=(Leader* l)
	{
		tr = new Trailer(l, tr);
	}

	friend std::ostream& operator <<(std::ostream&, Leader&);
	friend std::ostream& operator <<(std::ostream&, TopList&);
};

class TopList
{
	Leader* head;

public:
	TopList()
	{
		head = NULL;
	}
	~TopList();

	Leader* operator +(int);

	TopList& TopSort();
	void ReadList(char const*);
	void ShowKey();

	friend std::ostream& operator <<(std::ostream&, TopList&);
};

#endif
