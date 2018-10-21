#include <iostream>
#include <fstream>
#include <vector>
#include "graphl.hpp"

using namespace std;

Leader* TopList::operator +(int k)
{
	Leader* r = head;

	while(r && r->key != k)
		r = r->next;

	if(r) return r;

	r = new Leader(k, head);
	head = r;

	return r;
}

void TopList::ShowKey()
{
	Leader* p = head;

	while(p)
	{
		cout << p->key << ' ';
		p = p->next;
	}
}

TopList::~TopList()
{
	Leader* p = head;
	Leader* q = p;
	Trailer* t;
	Trailer* r;

	while(p)
	{
		p = p->next;
		t = q->tr;

		delete q;

		q = p;
		r = t;

		while (t)
		{
			t = t->next;
			delete r;
			r = t;
		}
	}
}

TopList& TopList::TopSort()
{
    Leader* curr; // текущий элемент из главного списка
    Leader* buff; // выдергиваемый элемент из главного списка
    Leader* fictHeadCurr = new Leader; // фиктивная голова текущего списка
    Leader* endLDnew; // хвост LDnew
    TopList* LDnew = new TopList; // новый список
    Trailer* trailerCurr; // указатель на трейлер текущего элемента
 
    fictHeadCurr->next = head;
    LDnew->head = new Leader; // задаем фиктивную голову для нового списка
    LDnew->head->next = NULL;
    endLDnew = LDnew->head;
 
    while(fictHeadCurr->next) // пока в исходном списке есть элементы
    {
        curr = fictHeadCurr; // начинаем с начала
 
        while(curr->next) // пока не пустой 
            if(curr->next->count)
                curr = curr->next;
            else // если нет входящих дуг
            {
                // выдергиваем элемент из списка и заносим в buff
                buff = curr->next;
                curr->next = buff->next;
                trailerCurr = buff->tr;
 
                // уменьшаем count у всего трейлера
                while(trailerCurr)
                {
                    trailerCurr->ld->count--;
                    trailerCurr = trailerCurr->next;
                }
 
                // добавление выдернутого элемента в конец LDnew
                endLDnew->next = buff;
                buff->next = NULL;
                endLDnew = endLDnew->next;
            }
    }

    // удаляем фиктивную голову у LDnew
    endLDnew = LDnew->head;
    LDnew->head = LDnew->head->next;
    head = NULL;

    delete fictHeadCurr;
    delete endLDnew;
 
    return *LDnew;
}

void TopList::ReadList(char const* fname)
{
	ifstream f(fname);
	if(!f) throw "Failed to read file";

	int buff1;
	int buff2;

	Leader* pa;
	Leader* pb;

	f >> buff1 >> buff2;

	while(buff1 && buff2)
	{
		pa = (*this) + buff1;
		pb = (*this) + buff2;
		++(*pb);
		*pa += pb;
		f >> buff1 >> buff2;
	}

	f.close();
}

ostream& operator <<(ostream& r, Leader& p)
{
	r << p.key << '\t' << p.count << '\t';
	Trailer* t = p.tr;

	while (t)
	{
		r << t->ld->key << '\t';
		t = t->next;
	}

	return r;
}

ostream& operator <<(ostream& r, TopList& t)
{
	Leader* s = t.head;

	r << "key\tcount\ttrailer:";

	while (s)
	{
		r << endl;
		r << *s;
		s = s->next;
	}

	return r;
}

