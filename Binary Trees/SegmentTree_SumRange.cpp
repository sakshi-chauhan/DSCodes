//http://ideone.com/muD9LO
//Segment trees - Sum of range

#include <iostream>

using namespace std;

int middle( int a , int b ){
	
	return a + (b-a)/2;	
	
}

int constructSegmentTree( int* arr , int seg_beg , int seg_end , int* seg_tree , int seg_in ){

	if( seg_beg == seg_end ){
		
		seg_tree[ seg_in ] = arr[ seg_beg ];
		return arr[ seg_beg ];
		
	}	
	
	int mid = middle( seg_beg , seg_end );
	
	seg_tree[ seg_in ] = constructSegmentTree( arr , seg_beg , mid , seg_tree , 2*seg_in+1 ) +
						 constructSegmentTree( arr , mid+1 , seg_end , seg_tree , 2*seg_in+2 );
						 
	return seg_tree[ seg_in ];
	
}

int getRangeSum( int* seg_tree , int seg_beg , int seg_end , int q_beg , int q_end , int seg_in ){
	
	if( q_beg <= seg_beg && q_end >= seg_end )
		return seg_tree[ seg_in ];
	
	if( q_beg > seg_end || q_end < seg_beg )
		return 0;
	
	int mid = middle( seg_beg , seg_end );
	
	return getRangeSum(seg_tree , seg_beg , mid , q_beg , q_end , 2*seg_in+1 ) +
		   getRangeSum(seg_tree , mid+1 , seg_end , q_beg , q_end , 2*seg_in+2 );	
	
}

void update( int* seg_tree , int seg_beg , int seg_end , int i , int diff , int seg_in ){
	
	if( i < seg_beg || i > seg_end )
		return;
		
	seg_tree[seg_in] = seg_tree[seg_in] + diff;
	
	if( seg_beg != seg_end ){
		
		int mid = middle( seg_beg , seg_end );
		
		update( seg_tree , seg_beg , mid , i , diff , 2*seg_in+1);
		update( seg_tree , mid+1 , seg_end , i , diff , 2*seg_in+2);
		
	}

}

int main() {
	// your code goes here

	int n;
	int* arr;
	int* stree;
	
	cin>>n;
	
	arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	int size = 2*n-1;
	stree = new int[size];
	constructSegmentTree( arr , 0 , n-1 , stree , 0 );
	
	
	cout<<getRangeSum( stree, 0 , n-1 , 3 ,6 , 0);
	//for( int i = 0 ; i < size; i++ )
	//	cout<<stree[i]<<" ";
	
	int i,new_val,diff;
	
	cin>>i;
	cin>>new_val;
	
	diff = new_val-diff; 
	arr[i] = new_val;
	
	update( stree, 0 , n-1 , i , diff , 0 );
	
	return 0;

}
