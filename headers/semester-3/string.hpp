#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string.h>

using namespace std;

class String
{
	char *line;
	int len;
public:
	String(int l=80)
	{
		line = new char[l];
		len = 0;
		line[0] = '\0';
	}
	String(const char*);
	String(String&);
	~String() {delete[]line;}
	
	int Length() {return len;}
	
	char& operator [](int i);
	String& operator +=(String& s2);
	bool operator ==(const String& s) {return !strcmp(line,s.line);}
	bool operator !=(const String& s) {return strcmp(line,s.line) ? 0 : 1;}
	String& operator ~();
	String& operator +(String& s);
	String& operator =(String& s);
	String& operator ++();
	
	operator char*() {return line;}
	operator int();

	friend ostream& operator<<(ostream& r, const String& s);
	friend istream& operator>>(istream& r, String& s);
};

#endif // STRING_H