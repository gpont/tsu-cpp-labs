#include <iostream>

using namespace std;

const int N = 4;

inline void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

/**
 * Алгоритм Дейкстры
 */
int D_algo(int* per)
{
	int i,j,k,min,obr[N];
	bool flag = false;
	
	for (i = N-2; i >= 0 && !flag; --i)
		if (per[i] < per[i + 1])
			flag = true;
		
	++i;
	if (flag == false)
		return -1;

	min = i+1;
	for (j = N-1; j > i && per[i] >= per[j]; --j);
	
	min = j;

	swap(per[i], per[min]);
	for (j = i+1; j < N; ++j)
		obr[j] = per[j];
		
	j = i+1;
	for (k = N-1; k >= i+1; --k)
		per[j++] = obr[k];
	
	return 0;
}

int main()
{
	int h, min, min_h, curr, a[N];
	int c[N][N];
	int per[255][N];

	for (int i = 0; i < N; ++i)
	{
		a[i] = i+1;
		for (int j = 0; j < N; ++j)
			cin >> c[i][j];
	}

	min = 255;
	min_h = 0;
	h = 0;
	do
	{
		curr = 0;
		for (int i = 1; i < N; ++i)
			curr += c[a[i-1]-1][a[i]-1];
		curr += c[a[N-1]-1][a[0]-1];

		if(curr < min)
		{
			min = curr;
			min_h = h;
		}

		cout << "a(" << curr << "): ";
		for (int i = 0; i < N; ++i)
		{
			per[h][i] = a[i]; 
			cout << a[i] << " ";
		}
		cout << endl;
		++h;
	}
	while(D_algo(a) == 0);
	
	for (int i = 0; i < N; ++i)
		cout << per[min_h][i] << " ";
	cout << endl;

	return 0;
}