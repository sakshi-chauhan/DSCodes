//http://ideone.com/8KwQ2r
//Maximum of all subarrays of size k in an array using queues
//Mood : <Tired>

#include<iostream>
#include<deque>

using namespace std;

void findMax( int *arr, int n , int k ){

	//A double ended queue of size k
	deque<int> Q(k);	
	
	int i;
	
	for( i = 0 ; i < k ; i++ ){
		
		while( !Q.empty() && arr[i] >= Q.back() )
			Q.pop_back();
			
		Q.push_back(i);
		
	}
	
	for( ; i < n ; i++){
		
		cout<<arr[Q.front()]<<" ";
		
		while( !Q.empty() && Q.front() <= i - k )
			Q.pop_front();
		
		while( !Q.empty() && arr[i] >= Q.back() )
			Q.pop_back();
			
		Q.push_back(i);	
		
	}
	cout<<arr[Q.front()];
}

int main() {
	// your code goes here

	int n,k;
	cin>>n>>k;
	
	int *arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
		
	findMax(arr,n,k);	
		
	return 0;

}
