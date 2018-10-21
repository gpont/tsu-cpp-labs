#include <iostream>
#include <fstream>
#include <cmath>
#include "multipath_sorting.hpp"

void mps::fdistributing(std::string finput, std::string fnames[], int N)
{
	std::ifstream f(finput);
	std::ofstream fout[N];
	for (int i = 0; i < N; ++i)
		fout[i] = std::ofstream(fnames[i], std::fstream::out | std::fstream::trunc);
	
	int buff1, buff2, curr = 0;
	f >> buff1 >> buff2;
	fout[curr] << buff1 << ' ' DEBUG( << std::flush);
	while(f.good())
	{
		// writing segment into current file
		while(f.good() && buff2 >= buff1)
		{
			fout[curr] << buff2 << ' ' DEBUG( << std::flush);
			buff1 = buff2;
			f >> buff2;
		}
		if(f.good()) // goto next file
			curr = (curr+1 == N ? 0 : curr+1);
		fout[curr] << buff2 << ' ' DEBUG( << std::flush);
		buff1 = buff2;
		f >> buff2;
	}
	
	f.close();
	for (int i = 0; i < N; ++i)
		fout[i].close();
}

void mps::fmerging(std::string ifnames[], std::string ofnames[], int N)
{

}

void mps::multipath_sorting(std::string ifname, std::string ofname, int N)
{
	std::string ifnames[N], ofnames[N];
	for (int i = 0; i < N; ++i)
	{
		ifnames[i] = "./binary/f"+std::to_string(i);
		ofnames[i] = "./binary/g"+std::to_string(i);
	}

	fdistributing(ifname, ifnames, N);

	while()

	for (int i = 0; i < N; ++i)
	{
		ifnames[i].close();
		ofnames[i].close();
	}
}
