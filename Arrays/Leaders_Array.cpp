//http://ideone.com/pepi4r
//Leaders in an array

#include <iostream>
using namespace std;

void print_leaders( int *arr , int n ){
	
	int max = arr[n-1];
	cout<<max<<" ";
	
	for( int i = n-2 ; i >= 0 ; i-- ){
		
		if( arr[i] > max ){
			
			cout<<arr[i]<<" ";
			max = arr[i];
			
		}
		
	}
	
}

int main() {

	int n;
	cin>>n;
	
	int *arr = new int[n];
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	print_leaders(arr,n);
		
	return 0;

}
