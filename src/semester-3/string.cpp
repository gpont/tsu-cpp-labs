#include <iostream>
#include <string.h>
#include "string.hpp"

using namespace std;

String::String(String &s)
{
	line = new char[s.len+1];
	strcpy(line, s.line);
	len = s.len;
}

String::String(const char *s)
{
	len = strlen(s);
	line = new char[len+1];
	strcpy(line, s);
}

char& String::operator [](int i)
{
	if((i < 0)||(i > len)) throw "Index Error";
	return line[i];
}

String& String::operator +=(String& s2)
{
	char *s = new char[len];
	strcpy(s, line);
	delete[] line;
	line = new char[len+=(s2.len+1)];
	strcpy(line, s);
	strcat(line, s2.line);
	delete[] s;
	return *this;
}

String& String::operator ~()
{
	for(int i=0; i<len/2; ++i)
	{
		char b = line[i];
		line[i] = line[len-i-2];
		line[len-i-2] = b;
	}
	return *this;
}

String& String::operator +(String& s)
{
	String* a = new String(len+s.len);
	strcpy(a->line, strcat(line, s.line));
	return *a;
}

String& String::operator =(String& s)
{
	if(*this == s) return *this;
	delete[]line;
	line = new char[(len=s.len)+1];
	strcpy(line, s.line);
	return *this;
}

String::operator int()
{
	int ret=0;
	for(int i=0;i<len;i++)
		ret=ret*10+line[i]-'0';
	return ret;
}

String& String::operator ++()
{
	for(int i=0;i<len;i++)
		++line[i];
	return *this;
}

ostream& operator <<(ostream& r, const String& s)
{
	return (r << s.line);
}

istream& operator >>(istream& r, String& s)
{
	char buf[256];
	r >> buf;
	String q(buf);
	s = q;
	return r;
}