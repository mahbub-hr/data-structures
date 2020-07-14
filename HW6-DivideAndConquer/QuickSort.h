#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

void MySwap(double &x, double &y)
{
	double temp = x;
	x = y;
	y = temp;
}
int generateRandom(int lo, int hi)
{
	srand(time(NULL));
	return rand()%(hi-lo+1)+lo;
}
int myPartition(double A[][100],int lo,int hi)
{
	int index = generateRandom(lo,hi);
	
	MySwap(A[0][index],A[0][hi]);
	MySwap(A[1][index],A[1][hi]);
	
	double pivot = A[0][hi];
	int l =lo;
	int h = hi-1;
	  
	while( l < h )
	{
		while( A[0][l] < pivot ) l++;
		while( A[0][h] > pivot ) h--;
		
		if( l < h )
		{
			MySwap(A[0][l],A[0][h]);
			MySwap(A[1][l],A[1][h]);
		}
	}	
	
	if (A[0][l] > A[0][hi]) 
	{
		MySwap(A[0][l],A[0][hi]);
		MySwap(A[1][l],A[1][hi]);
	}
	return l;
}

int QuickSort(double A[][100],int lo,int hi)
{
	int p;

	
	if (lo < hi)
	{
		p = myPartition(A,lo,hi);
		QuickSort(A,lo,p-1);
		QuickSort(A,p+1,hi);
	} 
		
	return p;
	
}

// int main()
// {
	// int n = 6;
	//double A[n] = {5,60,23,78,70,30,11,65,20,50};
	// double A[100] = {2,-1,2,3,4,-5};
	// int index[100];
	// for(int i=0; i<n;i++)
	// {
		// cout<<A[i]<<" ";
		// index[i] = i;
	//	cout<< index[i];
	// }
	// cout<<endl;
	
	// cout<< QuickSort(A,index,0,n-1)<<endl;
	
	// for(int i=0; i<n;i++)
		// cout<<A[i]<<" ";
	// cout<<endl;
	
	// for(int i=0; i<n;i++)
		// cout<<index[i]<<" ";
	
	// cout<<endl;
	
	
// }