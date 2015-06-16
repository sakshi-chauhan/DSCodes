//http://ideone.com/4h8OM8
//Search an element in a pivoted array

#include <iostream>
using namespace std;

int FindPivot( int *arr, int l , int h ){
	
	if( l > h )
		return -1;
		
	if( l == h )
		return l;
	
	int mid = (l+h)/2;
	
	if( mid < h && arr[mid] > arr[mid+1] )
		return mid;
	
	if( mid > l && arr[mid] < arr[mid-1] )
		return mid-1;
	
	if( arr[l] >= arr[mid] )
		return FindPivot( arr, l , mid-1 );
		
	else	
		return FindPivot( arr, mid+1 , h );
		
}

int BinarySearch( int *arr , int l , int h , int n ){
	
	if( l > h )
		return -1;
	
	int mid = (l+h)/2;
	
	if( arr[mid] == n )
		return mid;
	
	if( n > arr[mid] )
		return BinarySearch( arr, mid+1, h, n );
	else	
		return BinarySearch( arr, l, mid-1, n );
		
}

int FindElement( int *arr , int l , int h , int n ){
	
	int pivot = FindPivot( arr, l, h );
	//cout<<"Pivot = "<<pivot;
	
	if( pivot == -1 )
		return BinarySearch( arr, l, h, n );
	
	if( arr[pivot] == n )
		return pivot;
		
	if( arr[0] > n )
		return BinarySearch( arr, pivot+1 , h , n );
	else
		return BinarySearch( arr, l , pivot-1 , n );
	
}


int main() {
	
	int n,el;
	int *arr;
	
	cin>>n>>el;
	arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
		
	//cout<<BinarySearch(arr,0,n-1,el);
	//cout<<FindPivot(arr,0,n-1);
	cout<<FindElement( arr , 0 , n-1 , el );
	
	return 0;
}
