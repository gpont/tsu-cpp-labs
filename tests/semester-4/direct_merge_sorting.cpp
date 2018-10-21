#include <iostream>
#include "files_arr_lib.hpp"
#include "direct_merge_sorting.hpp"

int main()
{
	const std::string input_file_name = "./binary/test_input.txt";
	const std::string output_file_name = "./binary/test_output.txt";
	const int N = 15;

	farr_lib::gen_random_arr_file(input_file_name, N);
	dms::direct_merge_sort(input_file_name, output_file_name);

	std::cout << "Input file: ";
	farr_lib::print_file(input_file_name);
		
	std::cout << "Output file: ";
	farr_lib::print_file(output_file_name);
		
	farr_lib::test_sort_files(input_file_name, output_file_name);

	std::remove(input_file_name.c_str());
	std::remove(output_file_name.c_str());

	return 0;
}