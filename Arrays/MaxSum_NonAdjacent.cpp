//http://ideone.com/upioM6
//Maximum sum in an array such that no two array elements are adjacent

#include <iostream>
#include <algorithm>

using namespace std;

int maxSum( int *arr, int n ){
	
	int inc = arr[0];
	int exc = 0;
	int exc_new;
	
	for( int i = 1 ; i < n ; i++ ){
		
		exc_new = max( inc , exc );
		inc = exc + arr[i];
		
		exc = exc_new;
		
	}
	
	return max(inc,exc);
}

int main() {

	int n;
	cin>>n;
	
	int *arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	cout<<maxSum(arr,n);	
	
	
	return 0;

}
