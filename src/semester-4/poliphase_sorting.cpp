#include <iostream>
#include <fstream>
#include <utility>
#include "files_arr_lib.hpp"
#include "poliphase_sorting.hpp"

void pfs::recalc_pfstable(int *a, int *d, int N)
{
	int tmp = a[0];
	for (int i = 1; i < N; ++i)
	{
		tmp += a[i];
		a[i] = a[i-1];
	}
	a[N-1] = tmp;

	int tmpa = a[1], tmpd = d[0];
	for (int i = 1; i < N; ++i)
	{
		int buff = a[i];
		a[i] = a[i-1] + a[i];
		d[i] = a[i] - buff;
	}
	a[0] = tmpa; d[0] = a[0] - tmpd;
}

void pfs::fdistributing(std::string ifname, std::string *ofnames, const int N)
{
	std::ifstream f(ifname);
	std::ofstream *ofs = new std::ofstream[N];
	for (int i = 0; i < N; ++i)
		ofs[i] = std::ofstream(ofnames[i]);

	int *a = new int[N], *d = new int[N];
	for (int i = 0; i < N; ++i)
		a[i] = d[i] = 1;

	int last_buff, buff, i = 0; f >> buff;
	while(f.good())
	{
		int count = d[i]; // counts segments for writing in curr file
		while(count)
		{
			// write segment to current file
			if(f.good())
				do
				{
					DEBUG(std::cout << buff << " ";)
					ofs[i] << buff << ' ' DEBUG( << std::flush);
					last_buff = buff;
					f >> buff;
				}
				while(last_buff <= buff && f.good());
			ofs[i] << -1 << ' ' DEBUG( << std::flush);
			DEBUG(std::cout << -1 << std::endl);

			--count;
		}
		// Move to next file
		++i;
		if(i == N)
		{
			i = 0;
			recalc_pfstable(a, d, N);
		}
	}

	f.close();
	for (int i = 0; i < N; ++i)
		ofs[i].close();
	delete[] ofs;
}

int pfs::fmerging(std::string *fnames, const int N)
{
	std::ofstream f(fnames[N-1]);
	std::ifstream *ifs = new std::ifstream[N-1];
	for (int i = 0; i < N-1; ++i)
		ifs[i] = std::ifstream(fnames[i]);

	// fill arr from files
	int *arr = new int[N-1], mini = 0;
	for (int i = 0; i < N-1; ++i)
	{
		ifs[i] >> arr[i];
		if(arr[mini] < arr[i])
			mini = i;
	}

	int count = 0; // counter of numbers
	while(arr[mini] != -1)
	{
		f << arr[mini] << ' ' DEBUG( << std::flush);
		++count;
		ifs[mini] >> arr[mini];
		// find min
		mini = 0;
		for (int i = 0; i < N; ++i)
			if(arr[mini] < arr[i])
				mini = i;
	}
	f << -1 << ' ' DEBUG( << std::flush);
	
	f.close();
	for (int i = 0; i < N; ++i)
		ifs[i].close();
	delete ifs;

	return count;
}

void pfs::poliphase_sorting(std::string ifname, std::string ofname, const int N, const int ifsize)
{
	std::string *fnames = new std::string[N];
	for (int i = 0; i < N; ++i)
		fnames[i] = "./binary/"+std::to_string(i);

	pfs::fdistributing(ifname, fnames, N-1);
	int count = pfs::fmerging(fnames, N);
	
	while(count < ifsize)
	{
		std::swap(fnames[farr_lib::find_empty_file(fnames, N)], fnames[N-1]);
		count += pfs::fmerging(fnames, N);
		DEBUG(std::cout << count << ": ";)
		farr_lib::print_file(fnames[N-1]);
		DEBUG(std::cout << std::endl;)
	}
	farr_lib::file_copy(ofname, fnames[N-1]);

	for (int i = 0; i < N; ++i)
		std::remove(fnames[i].c_str());
}