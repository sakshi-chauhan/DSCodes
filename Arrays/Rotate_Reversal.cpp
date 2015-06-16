//http://ideone.com/LKSDEP
//Reversal algorithm for array rotation

#include <iostream>

using namespace std;

void reverse( int *arr , int start , int end );
void leftRotate( int *arr , int n , int d );
void print_array( int * arr , int size );

void print_array( int *arr, int size ){
	
	for( int i = 0 ; i < size ; i++ )
		cout<<arr[i]<<" ";
	cout<<'\n';
	
}

void reverse( int *arr , int start , int end ){
	
	int temp;
	
	while( start < end ){
		
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		
		start++;
		end--;
		
	}
	
}

void leftRotate( int *arr , int n , int d ){
	
	reverse( arr , 0 , d-1 );
	reverse( arr , d , n-1 );
	reverse( arr , 0 , n-1 );
	
}


int main() {
	// your code goes here
	
	int n,d;
	cin>>n>>d;
	
	int *arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	/*print_array(arr,n);	
	reverse( arr, 0 , 2 );
	print_array(arr,n);*/	
	leftRotate(arr,n,d);	
	print_array(arr,n);	
	
	
	return 0;

}
