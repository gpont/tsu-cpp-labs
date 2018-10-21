#ifndef POLIPHASE_SORTING_HPP
#define POLIPHASE_SORTING_HPP

#define POLIPHASE_SORTING_DEBUG
#ifdef POLIPHASE_SORTING_DEBUG
	#define DEBUG(x) x
#else
	#define DEBUG(x)
#endif

#include <iostream>
#include <fstream>

// TODO: rewrite fib gen to N nums

namespace pfs
{
	/**
	 * Recalculate a-d (Fibonacci) table
	 */
	void recalc_pfstable(int*, int*, int);

	/**
	 * Distributing segments function for External Poliphase Merging Sorting
	 */
	void fdistributing(std::string, std::string*, const int);

	/**
	 * Merging files function for External Poliphase Merging Sorting
	 * @param *fnames:
	 *     fnames[0:N-2] - input files
	 *     fnames[N-1] - output file
	 * @return count of numbers in segments
	 */
	int fmerging(std::string*, const int);

	/**
	 * External Poliphase Merging Sorting with N buffer files
	 * @details [long description]
	 * 
	 * @param ifname: input file name
	 * @param ofname: output file name
	 * @param N: count buffer files
	 */
	void poliphase_sorting(std::string, std::string, const int, const int);
}

#endif // POLIPHASE_SORTING_HPP
