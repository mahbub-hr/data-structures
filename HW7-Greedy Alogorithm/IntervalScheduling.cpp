#include<iostream>
#include"MergeSort.h"

using namespace std;
int length =1;

void intervalScheduling(double **interval,int *result,int lo, int hi)
{
	
	int i = 1;
	int k = lo+1;
	
	while(k <= hi)
	{
		if(interval[0][k] >= interval[1][lo])
		{
			lo = k;
			result[i++] = k++;
			length++;
		}
		else k++;
	}
}

int main(void)
{
	int n;
	cin >> n;
	double **interval = new double*[2];
	
	interval[0] = new double[n];
	interval[1] = new double[n];
	int *result = new int[n];
	
	for(int i =0 ; i<n; i++)
	{
		cin >> interval[0][i] ; 
		cin >> interval[1][i];
	}
	cout << endl;
	
	MergeSort(interval,0,n-1);
	
	for(int i =0 ; i<n; i++)
	{
		cout << interval[0][i] << " " << interval[1][i] << endl ; 
	}

	result[0] = 0;
	
	intervalScheduling(interval,result,0,n-1);
	
	cout << endl << "Result: "<< endl;
	
	cout << length<<endl;
	
	for(int i = 0; i<length; i++)
		cout << interval[0][result[i]] << " " << interval[1][result[i]] << endl ;
	
	if(interval[0]) delete[]interval[0];
	if(interval[1]) delete[]interval[1];
	if(interval) delete[]interval;
	if(result) delete[]result;
	
	return 0;
}