#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <set>
#include "files_arr_lib.hpp"

void farr_lib::gen_random_arr_file(std::string name, int len)
{
	std::fstream f(name, std::fstream::in | std::fstream::out | std::fstream::trunc);
	std::srand(std::time(nullptr));
	f << std::rand()%100;
	for (int i = 1; i < len; ++i)
		f << " " << std::rand()%100;

	f.close();
}

void farr_lib::print_file(std::string name)
{
	std::ifstream f(name);
	int buff;
	while(f >> buff)
		std::cout << buff << " ";
	
	std::cout << std::endl;
	f.close();
}

// template < typename T >
// void farr_lib::swap(T &a, T &b)
// {
// 	T c = a;
// 	a = b;
// 	b = c;
// }

void farr_lib::test_sort_files(std::string initital_file_name, std::string output_file_name)
{
	std::set<int> s1, s2;
	std::fstream f1(initital_file_name),
				 f2(output_file_name);
	int buff, count1 = 0, count2 = 0;

	while(f1 >> buff)
	{
		s1.insert(buff);
		++count1;
	}
	
	bool nondecreasing = true;
	f2 >> buff;
	int buff_prev = buff;
	s2.insert(buff);
	++count2;
	
	while(f2 >> buff)
	{
		s2.insert(buff);
		++count2;
		if(buff < buff_prev)
			nondecreasing = false;
		buff_prev = buff;
	}
	std::cout << "Length test: " << (count1==count2) << std::endl;

	bool set_test = true;
	for (std::set<int>::iterator p1 = s1.begin(), p2 = s2.begin();
		 p1 != s1.end() && p2 != s2.end(); ++p1, ++p2)
		if(*p1 != *p2)
		{
			set_test = false;
			break;
		}
	std::cout << "Set test: " << set_test << std::endl;
	std::cout << "Nondecreasing test: " << nondecreasing << std::endl;
}

bool farr_lib::is_file_empty(std::string str)
{
	std::ifstream f(str);
	bool ret = f.peek() == std::fstream::traits_type::eof();
	f.close();
	return ret;
}

int farr_lib::find_empty_file(std::string fnames[], const int N)
{
	int i = 0;
	while(i < N && is_file_empty(fnames[i])) ++i;
	return (i == N ? -1 : i);
}

void farr_lib::file_copy(std::string fname1, std::string fname2)
{
	int buff;
	std::ofstream f1(fname1);
	std::ifstream f2(fname2);

	while(f2 >> buff)
		f1 << buff << " ";
	
	f1.close();
	f2.close();
}
