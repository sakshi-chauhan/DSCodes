//http://ideone.com/EsRVCh
//Bucket Sort Implementation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_array( float* arr , int size ){
 
	for( int i = 0 ; i < size ; i++ )
		cout<<arr[i]<<" ";
	cout<<'\n';
 
}

void BucketSort( float* arr , int n ){
	
	vector<float> b[n];
	
	for( int i = 0 ; i < n ; i++ ){
		
		int in = n*arr[i];
		b[in].push_back(arr[i]);
		
	}
	
	for( int i = 0 ; i < n ; i++ )
		sort( b[i].begin() , b[i].end() );
	
	int k = 0;
	for( int i = 0 ; i < n ; i++ )
		for( int j = 0 ; j < b[i].size() ; j++ )
			arr[k++] = b[i][j];
	
}

int main() {
	
	int n;
	float* arr;
	
	cin>>n;
	arr = new float[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	BucketSort( arr , n );
	
	print_array( arr , n );	
	
	return 0;

}
