//http://ideone.com/MskIgZ
//Merge Sort - Implementation

#include <iostream>
#include <climits>
using namespace std;

void print_array( int* arr , int size ){
 
	for( int i = 0 ; i < size ; i++ )
		cout<<arr[i]<<" ";
	cout<<'\n';
 
}

void Merge( int* arr , int p , int q , int r ){
	
	int n1 = q-p+1;
	int n2 = r-q;
	
	int* l1 = new int[n1+1];
	int* l2 = new int[n2+1];
	
	for( int i = 0 ; i < n1 ; i++ )
		l1[i] = arr[p+i];
	
	for( int j = 0 ; j < n2 ; j++ )
		l2[j] = arr[q+j+1];
	
	l1[n1] = INT_MAX;
	l2[n2] = INT_MAX;
	
	int i = 0 , j = 0;
	
	for( int k = p ; k <=r ; k++ ){
		
		if( l1[i] <= l2[j] ){
		
			arr[k] = l1[i];
			i++;
		
		}
		else{
			
			arr[k] = l2[j];
			j++;
			
		}
	}
	
}

//p , r define the starting and ending index resp.

void MergeSort( int* arr , int p , int r ){
	
	if( p < r ){
		
		int q = (p+r)/2;
		MergeSort( arr , p , q );
		MergeSort( arr, q+1 , r );
		
		Merge( arr , p , q , r );
		
	}
		
}

int main() {
	// your code goes here
	
	int n;
	int* arr;

	cin>>n;
	
	arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	MergeSort( arr , 0 , n-1 );
	print_array(arr,n);
		
	return 0;

}
