
/**
 * @param A – массив
 * @param l, r – левый, правый индексы фрагмента,
 * @param xl, xr – левая, правая границы значений,
 * @param xm – среднее значение, (float)
 * @param i – рабочий индекс, изменяется от l до j с шагом +1
 * @param j – рабочий индекс, изменяется от r до i с шагом -1
 */
void QuickSort_1(int* A, int l, int r, int xl, int xr)
{
	if (l >= r || xl == xr) return;

	int i = l, j = r, xm = (xl+xr)/2;
	
	while(i <= j)
	{
		while(i <= j && A[i] < xm) ++i;
	    while(i <= j && A[j] >= xm) --j;
	    if (i < j) 
		{
			int buf = A[i];
			A[i] = A[j];
			A[j] = buf;
			++i; --j;
		}
	}
	QuickSort_1(A, l, j, xl, xm-0.5);
	QuickSort_1(A, i, r, xm+0.5, xr);
}

void QuickSort_2(int* A, int l, int r)
{
	if (l >= r) return; 

	int i = l+1, j = r, x = A[l];
	
	while(i <= j)
	{
		while(i <= j && A[i] <= x) ++i;
		while(i <= j && A[j] > x) --j;
		if (i < j) 
		{
			int buf = A[i];
			A[i] = A[j];
			A[j] = buf;
			++i; --j;
		}
	}
	int buf = A[l];
	A[l] = A[j];
	A[j] = buf;
	--j;
	QuickSort_2(A, l, j);
	QuickSort_2(A, i, r);
}

void QuickSort_3(int* A, int l, int r)
{
	if (l >= r) return;

	int i = l, j = r, x = A[(l+r)/2];

	while(i <= j)
	{
		while(A[i] < x) ++i;
		while(A[j] > x) --j;
		if (i <= j) 
		{
			int buf = A[i];
			A[i] = A[j];
			A[j] = buf;
			++i; --j;
		}
	}
	QuickSort_2(A, l, j);
	QuickSort_2(A, i, r);
}

int MedianSearch(int* A, int l, int r)
{
	
}