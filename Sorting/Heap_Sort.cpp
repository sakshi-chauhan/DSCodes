//http://ideone.com/zBrTkB
//heap Sort - Implementation

#include <iostream>

#define LEFT(i) (i<<1)+1
#define RIGHT(i) (i<<1)+2

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

void MaxHeapify( int* arr , int i , int size ){
	
	int l = LEFT(i);
	int r = RIGHT(i);
	int large;
	
	if( l > size )
		return;
	
	if( l <= size && arr[l] > arr[i] )
		large = l;
	
	else
		large = i;
		
	if( r <= size && arr[r] > arr[large] )
		large = r;
	
	if( large != i ){
		
		swap( arr[i] , arr[large] );
		MaxHeapify( arr , large , size );
	
	}	
}

void BuildMaxHeap( int* arr , int size ){
	
	for( int i = size/2-1 ; i >= 0 ; i-- )
		
		MaxHeapify( arr , i , size );
	
}

void HeapSort( int* arr , int size ){
	
	BuildMaxHeap( arr , size );
	
	for( int i = size ; i >= 0 ; i-- ){
		
		swap( arr[0],arr[i] );
		size--;
		MaxHeapify( arr , 0 , size );
		
	}
	
}

int main() {
	
	int n;
	int* arr;
	
	cin>>n;
	
	arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
		
	HeapSort(arr,n-1);
	
	print_array( arr , n );	
	
	return 0;

}
