 /**
 * Задать слово q в предложени s,
 * вывести для каждого слова в предложении буквы,
 * которых нет в q
 */
#include <iostream>
#include "string.hpp"
#include "set.hpp"

using namespace std;

Set<char>& SetInput()
{
	Set<char>* ret = new Set<char>();
	String buf;
	cin >> buf;
	for (int i = 0; i < buf.Length(); ++i)
		*ret += buf[i];
	return *ret;
}

int main()
{
	const int n = 5;
	Set<char> q = SetInput();
	//cout << q;

	for (int i = 0; i < n; ++i)
	{
		Set<char> s = SetInput();
		s -= q;
		cout << s; 
	}

	return 0;
}