#include<iostream>
#include<conio.h>
#include"QuickSort.h"

using namespace std;

int FindMin(double A[][100], int lo, int hi)
{
	double min = A[1][lo];
	int index = lo;
	for (int i = lo + 1; i <= hi; i++)
	{
		if (A[1][i] < A[1][index]) index = i;
	}

	return index;
}

void SkylinePoints(double A[][100], int lo, int &hi)
{
	int mid, j;
	if (hi > lo)
	{
		mid = (hi + lo) / 2;
		j = mid + 1;
		SkylinePoints(A, lo, mid);

		//int index = FindMin(A, lo, mid);
		
		int index = mid;

		int i = mid + 1;

		while (j <= hi)
		{
			if (A[1][j] < A[1][index])
			{
				A[1][i] = A[1][j];
				A[0][i] = A[0][j];
				i++;
			}
			j++;
		}
		

		hi = i-1;
		SkylinePoints(A, mid + 1, hi);
	}
}

int main()
{
	int n = 16;
	int hi = n-1;
	int lo = 0;
	
	double A[100][100] = {{9,1,1,1,1,3,10,8,6,2,2,2,4,11,7,5},{2,10,9,7,8,7,5,5,8,9,4,5,4,7,3,6}};
	//double A[100][100] = { { 3,1,2,6,5 },{ 7,8,5,8,6 } };
	//double A[100][100] = {{9,1,3,10,8,6,2,4,11,7,5},{2,8,7,5,5,8,5,4,7,3,6}};
	for (int i = 0; i<n; i++)
	{
		cout << "(" << A[0][i] << "," << A[1][i] << ")" << " ";
	}

	cout << endl;
	cout <<"Sorting---------" <<endl;

	QuickSort(A, lo, hi);
	cout << "After Sorting--------" << endl;

	for (int i = 0; i<n; i++)
	{
		cout << "(" << A[0][i] << "," << A[1][i] << ")" << " ";
	}
	cout << endl;

	SkylinePoints(A, lo, hi);
	cout <<hi << endl;

	for (int i = 0; i<=hi; i++)
	{
		cout << "(" << A[0][i] << "," << A[1][i] << ")" << " ";
	}
	cout << endl;

	_getch();
	return 0;
}