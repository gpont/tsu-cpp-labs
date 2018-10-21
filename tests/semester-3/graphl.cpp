#include <iostream>
#include <vector>
#include "graphl.hpp"

int main()
{
	TopList Top;
	TopList Top1;

	Top.ReadList("graph.txt");

	std::cout << Top << std::endl;
	Top1 = Top.TopSort();
	Top1.ShowKey();
	std::cout << std::endl;

	return 0;
}
