#ifndef DIRECT_MERGE_SORTING_HPP
#define DIRECT_MERGE_SORTING_HPP

#include <iostream>
#include <fstream>

// Define DIRECT_MERGE_SORTING_DEBUG const for debug output turn on

namespace dms
{
	/**
	 * Distributing files function for Extern Direct Merge Sorting on 4 buffer files
	 * 
	 * @return count of numbers
	 */
	int fdistributing(std::string finput, std::string fname1, std::string fname2);

	/**
	 * Merging files function for Extern Direct Merge Sorting on 4 buffer files
	 */
	void fmerging(std::string fname1, std::string fname2, std::string fname3, std::string fname4, int p);

	/**
	 * Extern Direct Merge Sorting on 4 buffer files
	 */
	void direct_merge_sort(std::string, std::string);
}

#endif // DIRECT_MERGE_SORTING_HPP
