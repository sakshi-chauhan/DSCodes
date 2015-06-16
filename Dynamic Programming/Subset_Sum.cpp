//http://ideone.com/39dtVq
//Subset Sum Problem in Dynamic Programming

#include <iostream>
using namespace std;

bool isSubsetSum( int* set , int n , int sum ){
	
	bool sub[sum+1][n+1];	//sub[i][j] means there's a subset of set[0..j] with sum = i
	
	for( int i = 0 ; i <= n ; i++ )
		sub[0][i] = 1;
	
	for( int i = 1 ; i <= sum ; i++ )
		sub[i][0] = 0;
		
	for( int i = 1 ; i <= sum ; i++ ){
		
		for( int j = 1 ; j <= n ; j++ ){
		
			if( i >= set[j-1] )
				sub[i][j] = sub[i][j-1]||sub[i-set[j-1]][j-1];
		
		}
	}	
		
	return sub[sum][n];
}

int main() {

	int n,sum;
	int* arr;
	
	cin>>n>>sum;
	arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	if( isSubsetSum(arr,n,sum) )
		cout<<"Sum exists";
	else	
		cout<<"Sum doesnt exist";
	return 0;

}
