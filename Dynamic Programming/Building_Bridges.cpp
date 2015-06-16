//http://ideone.com/L2i45A
//Building bridge problem in dynamic programming

#include <iostream>
#include <algorithm>
using namespace std;

struct city{
	
	int x,y;
	
};

bool cmp( city a , city b ){
	
	return a.x < b.x;
	
}

int LongestIncreasingSubsequence( city arr[] , int n ){
	
	int* L = new int[n];
	L[0] = 1;
	
	for( int i = 1 ; i < n ; i++ ){
		L[i] = 0;
		for( int j = 0 ; j < i ; j++ ){
			
			if( arr[j].y < arr[i].y )
				L[i] = max( L[i] , L[j] + 1 );
		
			else
				L[i] = L[j];
				
		}
	}
	
	return L[n-1];
	
}

int main() {

	int n;
	cin>>n;
	
	city c[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>c[i].x>>c[i].y;

	sort(c,c+n,cmp);

	cout<<LongestIncreasingSubsequence(c,n);
	
	return 0;

}
