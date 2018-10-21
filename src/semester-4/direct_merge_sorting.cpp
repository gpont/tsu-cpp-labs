#include <iostream>
#include <fstream>
#include <utility>
#include <cmath>
#include <set>
#include "files_arr_lib.hpp"
#include "direct_merge_sorting.hpp"

int dms::fdistributing(std::string finput, std::string fname1, std::string fname2)
{
	std::ifstream f(finput);
	std::ofstream fa(fname1, std::fstream::out | std::fstream::trunc),
				  fb(fname2, std::fstream::out | std::fstream::trunc);

	int buff, count = 0;

	while(f >> buff)
	{
		fa << buff << " ";
		std::swap<std::ofstream>(fa, fb);
		++count;
	}
	
	f.close();
	fa.close();
	fb.close();

	return count;
}

void dms::fmerging(std::string fname1, std::string fname2, std::string fname3, std::string fname4, int p)
{
	std::ifstream fa(fname1),
				  fb(fname2);
	std::ofstream fc(fname3, std::fstream::out | std::fstream::trunc),
				  fd(fname4, std::fstream::out | std::fstream::trunc);
	
	int buff1, buff2;
	
	fa >> buff1;
	fb >> buff2;
	int i1 = 0, i2 = 0;
	while(fa.good() && fb.good())
	{
    	i1 = 0, i2 = 0;
		while(i1 < p && i2 < p && fa.good() && fb.good())
			if(buff1 < buff2)
			{
				fc << buff1 << " ";
				fa >> buff1;
				++i1;
			}
			else
			{
				fc << buff2 << " ";
				fb >> buff2;
				++i2;
			}

		while(i1 < p && fa.good())
		{
			fc << buff1 << " ";
			++i1;
			fa >> buff1;
		}

		while(i2 < p && fb.good())
		{
			fc << buff2 << " ";
			++i2;
			fb >> buff2;
		}
		std::swap<std::ofstream>(fc, fd);
	}

	while(fa.good())
	{
		fc << buff1 << " ";
		fa >> buff1;
	}

	while(fb.good())
	{
		fc << buff2 << " ";
		fb >> buff2;
	}

	fa.close();
	fb.close();
	fc.close();
	fd.close();
}

void dms::direct_merge_sort(std::string ifname, std::string ofname)
{
	std::string fnames[] = {
		"./binary/fa",
		"./binary/fb",
		"./binary/fc",
		"./binary/fd"
	};

	// distribution
	int count = fdistributing(ifname, fnames[0], fnames[1]);

	// merging
	int max_p = (int)std::pow(2, std::round(std::log(count)+0.5));
	for (int p = 1; p <= max_p; p *= 2)
	{
		#ifdef DIRECT_MERGE_SORTING_DEBUG
			std::cout << "p = " << p << ": " << std::endl;

			std::cout << "\tfa: "; print_file(fnames[0]);
			std::cout << "\tfb: "; print_file(fnames[1]);
		#endif

		fmerging(fnames[0], fnames[1], fnames[2], fnames[3], p);
	
		#ifdef DIRECT_MERGE_SORTING_DEBUG
			std::cout << "\tfc: "; print_file(fnames[2]);
			std::cout << "\tfd: "; print_file(fnames[3]);
		#endif

		// fa <-> fc, fb <-> fd
		std::swap<std::string>(fnames[0], fnames[2]);
		std::swap<std::string>(fnames[1], fnames[3]);
	}

	int k = (farr_lib::is_file_empty(fnames[0]) ? 1 :
				(farr_lib::is_file_empty(fnames[1]) ? 0 :
					(farr_lib::is_file_empty(fnames[2]) ? 3 : 2)));

	farr_lib::file_copy(ofname, fnames[k]);

	for (int i = 0; i < 4; ++i)
		std::remove(fnames[i].c_str());
}
