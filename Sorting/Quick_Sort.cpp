//http://ideone.com/Go5DBz
//Quick Sort Implementation

#include <iostream>
using namespace std;

void print_array( int* arr , int size ){
 
	for( int i = 0 ; i < size ; i++ )
		cout<<arr[i]<<" ";
	cout<<'\n';
 
}

void swap( int& a , int& b){
	
	int temp = a;
	a = b;
	b = temp;
	
}

int Partition( int* arr , int p , int r ){
	
	int x = arr[r];
	int i = p-1;
	
	for( int j = p ; j < r ; j++ ){
		
		if( arr[j] <= x ){
			
			i++;
			swap( arr[i] , arr[j] );
			
		}
		
	}
	swap( arr[i+1] , arr[r] );

	return i+1;

}

void QuickSort( int* arr , int p , int r ){
	
	if( p < r ){
		
		int q = Partition( arr , p , r );
		QuickSort( arr , p , q-1 );
		QuickSort( arr , q+1 , r );
		
	}
	
}

int main() {
	
	int n;
	int* arr;
	
	cin>>n;
	
	arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
		
	QuickSort(arr,0,n-1);
	
	print_array( arr , n );	
		
	return 0;

}
