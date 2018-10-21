/**
 * Инвертировать главную диагональ булевой матрицы
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "boolm.hpp"

const int N = 4;

int main()
{
	BoolM matrix(N, N);
	srand(time(0));

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if(rand()%2)
				matrix[i].Set1(j);
			else
				matrix[i].Set0(j);

	cout << matrix << endl;

	for (int i = 0; i < N; ++i)
		if(matrix[i][i])
			matrix[i].Set0(i);
		else
			matrix[i].Set1(i);
	
	cout << matrix << endl;

	return 0;
}