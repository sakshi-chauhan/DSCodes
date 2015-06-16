//http://ideone.com/RNhzAa
//Longest Increasing Subsequence - O(n^2)

#include <iostream>
#include <algorithm>

using namespace std;

int LongestIncreasingSubsequence( int * arr , int n ){
	
	int* L = new int[n];
	L[0] = 1;
	
	for( int i = 1 ; i < n ; i++ ){
		L[i] = 0;
		for( int j = 0 ; j < i ; j++ ){
			
			if( arr[j] < arr[i] )
				L[i] = max( L[i] , L[j] + 1 );
		
			else
				L[i] = L[j];
				
		}
	}
	
	return L[n-1];
	
}

int main() {
	
	int n;
	int* arr;
	
	cin >> n;
	
	arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
		
	cout << LongestIncreasingSubsequence(arr,n);
	return 0;

}
