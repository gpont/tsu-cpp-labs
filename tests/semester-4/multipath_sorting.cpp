#include <iostream>
#include "multipath_sorting.hpp"
#include "files_arr_lib.hpp"

int main()
{
	const std::string INPUT_FILE_NAME = "./binary/test_input.txt";
	const std::string OUTPUT_FILE_NAME = "./binary/test_output.txt";
	const int BUFFER_FILES_COUNTS = 3;
	const int NUMBERS_COUNT = 20;
	
	farr_lib::gen_random_arr_file(INPUT_FILE_NAME, NUMBERS_COUNT);
	pfs::multipath_sorting(INPUT_FILE_NAME, OUTPUT_FILE_NAME, BUFFER_FILES_COUNTS);

	std::cout << "Input file: ";
	farr_lib::print_file(INPUT_FILE_NAME);
	
	std::cout << "Output file: ";
	farr_lib::print_file(OUTPUT_FILE_NAME);
	
	farr_lib::test_sort_files(INPUT_FILE_NAME, OUTPUT_FILE_NAME);

	std::remove(INPUT_FILE_NAME.c_str());
	std::remove(OUTPUT_FILE_NAME.c_str());

	return 0;
}