#ifndef FILES_ARR_LIB_HPP
#define FILES_ARR_LIB_HPP

namespace farr_lib
{
	void gen_random_arr_file(std::string, int);
	void print_file(std::string);

	/**
	 * Testing sorting
	 * 
	 * @param1 initital file name
	 * @param2 sorted file name
	 */
	void test_sort_files(std::string, std::string);

	// template < typename T >
	// void swap(T &a, T &b);

	/**
	 * Find empty file in array
	 * 
	 * @return empty file index in fnames array
	 * @return -1 if emty file not found
	 */
	int find_empty_file(std::string[], const int);

	bool is_file_empty(std::string);

	/**
	 * Copy file from source to destination
	 * 
	 * @param fname1 destination
	 * @param fname2 source
	 */
	void file_copy(std::string fname1, std::string fname2);
}

#endif // FILES_ARR_LIB_HPP
