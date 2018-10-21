#ifndef MULTIPATH_SORTING_HPP
#define MULTIPATH_SORTING_HPP

#include <iostream>
#include <fstream>

#define MULTIPATH_SORTING_DEBUG
#ifdef MULTIPATH_SORTING_DEBUG
	#define DEBUG(x) x
#else
	#define DEBUG(x)
#endif

namespace mps
{
	/**
	 * Distributing files function for Extern Multipath Merge Sorting on N buffer files
	 */
	void fdistributing(std::string finput, std::string fnames[], int N);

	/**
	 * Merging files function for Extern Multipath Merge Sorting on N buffer files
	 */
	void fmerging(std::string ifnames[], std::string ofnames[], int N);

	/**
	 * Extern Multipath Merge Sorting on N buffer files
	 */
	void multipath_sorting(std::string, std::string, int N);
}



#endif // MULTIPATH_SORTING_HPP
