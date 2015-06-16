//http://ideone.com/5U3Cqd
//Implementation of Comb Sort Algorithm
 
#include <iostream>
using namespace std;
 
void swap( int &a , int &b ){
 
	int temp = a ;
	a = b; 
	b = temp;
 
}
 
void print_array( int* arr , int size ){
 
	for( int i = 0 ; i < size ; i++ )
		cout<<arr[i]<<" ";
	cout<<'\n';
 
}
 
void CombSort( int* arr , int n ){
 
	int step,k,i,j;
	step = n;
 
	while( step = (int)(step/1.3) > 1 ){
 
		for( j = n-1 ; j>= step ; j-- ){
 
			k = j - step;
 
			if( arr[j] < arr[k] )
				swap( arr[j] , arr[k] );
 
		}
	}
 
	bool again = true;
 
	for( i = 0 ; i < n && again ; i++ ){
 
		for( j = n-1 , again = false ; j > i ; j-- ){
 
			if( arr[j] < arr[j-1] ){
 
				swap( arr[j] , arr[j-1] );
				again = true;
 
			}
 
		}
 
	}
}
 
int main() {
	// your code goes here
 
	int n;
	int* arr;
 
	cin>>n;
	arr = new int[n];
 
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
 
	CombSort(arr,n);
 
	print_array(arr,n);
 
	return 0;
 
}
