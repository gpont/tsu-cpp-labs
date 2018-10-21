/**
 * Задать слово q в предложени s,
 * вывести для каждого слова в предложении буквы,
 * которых нет в q
 */
#include <iostream>
#include "string.hpp"
#include "setchar.hpp"

using namespace std;

SetChar& SetCharInput()
{
	SetChar* ret = new SetChar();
	String buf;
	cin >> buf;
	for (int i = 0; i < buf.Length(); ++i)
		*ret += buf[i];
	return *ret;
}

int main()
{
	const int n = 5;
	SetChar q = SetCharInput();
	//cout << q;

	for (int i = 0; i < n; ++i)
	{
		SetChar s = SetCharInput();
		s -= q;
		cout << s << endl;
	}

	return 0;
}