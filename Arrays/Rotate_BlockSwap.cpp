//http://ideone.com/DCVrWi
//Block swap algorithm for array rotation

#include <iostream>
using namespace std;

void print_array( int *arr , int size ){
	
	for( int i = 0 ; i < size ; i++ )	
		cout<<arr[i]<<" ";
	cout<<'\n';
	
}

void swap( int *arr , int st , int end , int d ){
	
	int temp;
	for( int i = 0 ; i < d ; i++ ){
		
		temp = arr[st+i];
		arr[st+i] = arr[end+i];
		arr[end+i] = temp;
		
	}
	
}

void leftRotate( int *arr , int n , int d ){
	
	if( d == 0 || n == d )
		return;
	
	if( d == n-d ){
		
		swap( arr , 0 , n-d , d);
		return;
		
	}
		
	if( d < n-d ){
		
		swap( arr , 0 , n-d , d );
		leftRotate( arr , n-d , d );
		
	}	
	
	else{
		
		swap( arr , 0 , d , n-d );
		leftRotate( arr+n-d , d , 2*d-n );
		
	}
	
}
int main() {
	
	int n,d;
	cin>>n>>d;
	
	int *arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
		
	leftRotate( arr , n , d );
	print_array( arr , n );
	
	return 0;

}
