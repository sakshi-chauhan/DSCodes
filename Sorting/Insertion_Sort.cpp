//http://ideone.com/8k9Xze
//Insertion sort

#include <iostream>

using namespace std;

void InsertionSort( int* arr , int size ){
	
	int i,j,key;
	
	for( j = 1 ; j < size ; j++ ){
		
		key = arr[j];
		
		i = j-1;
		
		while( i >= 0 && arr[i] > key ){
			
			arr[i+1] = arr[i];
			i--;
			
		}
		
		arr[i+1] = key;
	}
	
}

void print_array( int* arr , int size ){
	
	for( int i = 0 ; i < size ; i++ )
		cout<<arr[i]<<" ";
	cout<<'\n';
	
}

int main() {
	// your code goes here
	
	int n;
	int* arr;
	
	cin>>n;
	arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	InsertionSort(arr,n);
	print_array(arr,n);
	
	//delete(arr);
	
	return 0;

}
