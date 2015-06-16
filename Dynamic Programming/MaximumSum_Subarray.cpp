/*
Dynamic Programming - 1
Largest sum contiguous subarray
find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.
*/

#include <iostream>
#include <algorithm>

using namespace std;

void print_array( float* arr , int size ){
 
	for( int i = 0 ; i < size ; i++ )
		cout<<arr[i]<<" ";
	cout<<'\n';
 
}

int MaximumSubarraySum( int* arr , int n ){
	
	int cur_max = arr[0];
	int max_so_far = arr[0];
	
	for( int i = 1 ; i < n ; i++ ){
		
		cur_max = max( arr[i] , arr[i]+cur_max);
		max_so_far = max( max_so_far , cur_max );
	
	}
	
	return max_so_far;
	
}

int main() {

	int n;
	int* arr;
	
	cin>>n;
	arr = new int [n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	cout<<MaximumSubarraySum(arr,n);	
	
	return 0;

}
