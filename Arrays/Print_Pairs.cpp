//http://ideone.com/F2p8Tv
//Print pairs with a given sum

#include <iostream>
using namespace std;

void printPairs( int* arr , int n , int sum ){
	
	bool disc[10000] = {0};
	
	for( int i = 0 ; i < n ; i++ ){
		
		int temp = sum - arr[i];
		
		if( temp >= 0 && disc[temp] ){
			cout<<arr[i]<<" "<<temp;
			break;
		}
		
		disc[arr[i]]=1;
	}
	
}


int main() {
	
	int n,sum;
	
	cin>>n>>sum;
	int* arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
		
	printPairs(arr,n,sum);		
		
	return 0;
}
