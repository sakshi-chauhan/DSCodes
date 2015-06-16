//http://ideone.com/OgPC4e
//Radix Sort Implementation

#include <iostream>
using namespace std;

void print_array( int* arr , int size ){
 
	for( int i = 0 ; i < size ; i++ )
		cout<<arr[i]<<" ";
	cout<<'\n';
 
}

int get_max( int* arr , int n ){
	
	int max = arr[0];
	for( int i = 1 ; i < n ; i++ )
		if( arr[i] > max )
			max = arr[i];
	return max;
	
}

void CountingSort( int* A , int* B , int n , int k ){
	
	int C[10];
	
	for( int i = 0 ; i < 10 ; i++ )
		C[i] = 0;
	
	//print_array( C , k+1 );	
	
	for( int i = 0 ; i < n ; i++ )
		C[ (A[i]/k)%10 ] = C[ (A[i]/k)%10 ]+1;
	
	//print_array( C , k+1 );
	
	for( int i = 1 ; i < 10 ; i++ )
		C[i] = C[i] + C[i-1];
	
	//print_array( C , k+1 );	
		
	for( int i = n-1 ; i >= 0 ; i-- ){
		
		B[C[ (A[i]/k)%10 ] - 1] = A[i];
		C[ (A[i]/k)%10 ]--;
		
	}
	
}

void RadixSort( int* arr , int* B , int n ){
	
	int m = get_max(arr,n);
	
	for( int k = 1 ; (m/k) > 0 ; k*=10 )
		CountingSort( arr, B , n , k );
	
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
	
	RadixSort( A , B , n );
	print_array( B , n );
		
	return 0;

}
