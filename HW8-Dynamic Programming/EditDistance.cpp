#include<iostream>
#include<algorithm>
using namespace std;

struct index{
	int x, y;
	index(){
		x=0;
		y=0;
	}
};


// int getMin (int x, int y, int z)
// {
	// return min(min(x,y),z);
// }

int EDist(string s, string t)
{
	int m = s.length();
	int n = t.length();
	int diff;
	int **E = new int*[m+1];
	for(int i =0; i<= m; i++) E[i] = new int[n+1];
	
	struct index **BT = new struct index*[m+1];
	for(int i =0; i<= m; i++) BT[i] = new struct index[n+1];
	
	for(int i =0 ; i <= m ; i++) E[i][0] = i;
	for(int i = 0; i <= n; i++) E[0][i] = i;
	
	for( int i = 1; i <= m; i++){
		
		for(int j = 1; j <= n; j++){
			
			if (s[i-1] == t[j-1]) diff = 0;
			else diff = 1;
			
			if ( E[i-1][j]+1 < E[i][j-1]+1 && E[i-1][j]+1 < E[i-1][j-1] + diff ){
				
				E[i][j] = E[i-1][j]+1;
				struct index idx;
				idx.x = i-1;
				idx.y = j;
				BT[i][j] = idx;
			}
			else if( E[i][j-1]+1 < E[i-1][j]+1 && E[i][j-1]+1 < E[i-1][j-1] + diff ){
				
				E[i][j] = E[i][j-1]+1;
				struct index idx;
				idx.x = i;
				idx.y = j-1;
				BT[i][j] = idx;
			}
			else{
				
				E[i][j] = E[i-1][j-1] + diff;
				struct index idx;
				idx.x = i-1;
				idx.y = j-1;
				BT[i][j] = idx;
			}
			//E[i][j] = getMin(E[i-1][j]+1, E[i][j-1]+1, E[i-1][j-1] + diff);
		}
	}
	
	
	for(int i =0; i<= m; i++) {
		if(E[i]) delete []E[i]; 
	}
	
	if(E) delete []E;
	return E[m][n];
}


// printAlign(string s, string t){
	// int m = s.
	
// }

int main(void)
{
	char  s[100],t[100];
	cin >> s;
	cin >> t;
	
	string src(s);
	string tar(t);
	cout << EDist(src, tar);
	return 0;
	
}