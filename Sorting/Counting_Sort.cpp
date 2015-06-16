//http://ideone.com/ygV3ad
//Counting Sort Implementation

#include <iostream>
using namespace std;

void print_array( int* arr , int size ){
 
	for( int i = 0 ; i < size ; i++ )
		cout<<arr[i]<<" ";
	cout<<'\n';
 
}

void CountingSort( int* A , int* B , int n , int k ){
	
	int* C = new int[k+1];
	
	for( int i = 0 ; i <= k ; i++ )
		C[i] = 0;
	
	//print_array( C , k+1 );	
	
	for( int i = 0 ; i < n ; i++ )
		C[A[i]] = C[A[i]]+1;
	
	//print_array( C , k+1 );
	
	for( int i = 1 ; i <= k ; i++ )
		C[i] = C[i] + C[i-1];
	
	//print_array( C , k+1 );	
		
	for( int i = n-1 ; i >= 0 ; i-- ){
		
		B[ C[A[i]]] = A[i];
		C[A[i]] = C[A[i]] - 1;
		
	}
	
}


int main() {
	
	int n;
	int* A;
	int* B;

	cin>>n;
	
	A = new int[n];
	B = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>A[i];
	
	CountingSort( A , B , n , 5 );
	print_array( B , n );
		
	return 0;

}
