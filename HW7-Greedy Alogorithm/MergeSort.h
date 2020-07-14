#include<iostream>
#define MAXREAL 99999.0
using namespace std;

void Merge(double **A, int lo, int q, int hi)
{
	int n1 = q - lo + 1 + 1;
	int n2 = hi - q + 1;
	double L[2][500], R[2][500];

	for (int i = 0; i < n1 - 1; i++) {
		L[0][i] = A[0][lo + i];
		L[1][i] = A[1][lo + i];
	}
	for (int i = 0; i < n2 - 1; i++) {
		R[0][i] = A[0][q + 1 + i];
		R[1][i] = A[1][q + 1 + i];
	}

	L[1][n1 - 1] = MAXREAL;
	R[1][n2 - 1] = MAXREAL;
	int i = 0, j = 0;

	for (int k = lo; k <= hi; k++)
	{
		if (L[1][i] < R[1][j])
		{
			A[0][k] = L[0][i];
			A[1][k] = L[1][i];
			i++;
		}
		else
		{
			A[0][k] = R[0][j];
			A[1][k] = R[1][j];
			j++;
		}
	}
}
void MergeSort(double **A, int lo, int hi)
{
	int q;

	if (hi > lo)
	{
		q = (hi + lo) / 2;
		MergeSort(A, lo, q);
		MergeSort(A, q + 1, hi);
		Merge(A, lo, q, hi);
	}


}
