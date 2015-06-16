//http://ideone.com/Bpxlse
//Largest multiple of 3 using queues

#include <iostream>
#include<queue>
#include<algorithm>

using namespace std;

int compare_inc( const void *a , const void *b ){
	
	return *(int*)a > *(int*)b;
	
}

int compare_dec( const void *a , const void *b ){
	
	return *(int*)a < *(int*)b;
	
}

int LargestMultiple( int *arr , int n ){
	
	//Arrange into ascending order
	qsort( arr , n , sizeof(int) , compare_inc );
	
	queue<int> q0;
	queue<int> q1;
	queue<int> q2;
	
	int sum = 0;
	
	for( int i = 0 ; i < n ; i++ ){
		
		sum += arr[i];
		
		if( arr[i] % 3 == 0 )
			q0.push( arr[i] );
		
		else if( arr[i] % 3 == 1 )
			q1.push( arr[i] );
			
		else
			q2.push( arr[i] );
		
	}
	
	if( sum % 3 == 1 ){
		
		if( !q1.empty() ){
			
			q1.pop();
			
		}
		
		else{
			
			if( !q2.empty() )
				q2.pop();
			else
				return 0;
				
			if( !q2.empty() )
				q2.pop();
			else
				return 0;
			
		}
	}
	
	
	else if( sum % 3 == 2 ){
		
		if( !q2.empty() ){
			
			q2.pop();
			
		}
		
		else{
			
			if( !q1.empty() )
				q1.pop();
			else
				return 0;
				
			if( !q1.empty() )
				q1.pop();
			else
				return 0;
			
		}
	}
	
	int *aux = new int[n];
	int size = 0;
	
	while( !q0.empty() ){
		aux[ size++ ] = q0.front();
		q0.pop();
	}
	while( !q1.empty() ){
		aux[ size++ ] = q1.front();
		q1.pop();
	}
	while( !q2.empty() ){
		aux[ size++ ] = q2.front();
		q2.pop();
	}
	
	qsort( aux , size , sizeof(int) , compare_dec );
	for( int i = 0 ; i < size ; i++ )
		cout<<aux[i];
	
}

int main() {
	
	int n;
	int *arr;
	
	cin>>n;
	arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	LargestMultiple( arr , n );
	
	return 0;

}
