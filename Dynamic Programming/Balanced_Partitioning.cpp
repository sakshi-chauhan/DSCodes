//http://ideone.com/OaGtWt
//Balanced Partitioning Problem - Dynamic Programming

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int balancedPartition( int* arr , int n ){
	
	int sum = 0;
	
	for( int i = 0 ; i < n ; i++ )
		sum += arr[i];
	
	int P[n+1][sum+1];
	
	for( int i = 0 ; i <= n ; i++ ){
		
		for( int j = 0 ; j <= sum ; j++ ){
			
			if( j == 0 )
				P[i][j] = 1;
			
			else if( i == 0 )
				P[i][j] = 0;
			
			else{
				if( j >= arr[i-1] )
					P[i][j] = max( P[i-1][j] , P[i-1][j-arr[i-1]] );
				else
					P[i][j] = P[i-1][j];
			}
		}
		
	}
	
	/*for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= sum ; j++ ){
			cout<<P[i][j]<<" ";
		}	cout<<'\n';	
	}*/
	
	int s1 = sum/2;
	int s2 = sum - s1;
	
	while( s1 > 0 ){
		
		if( P[n][s1]==1 && P[n][s2]==1 )
			break;
		
		s1--;
		s2++;
			
	}
	
	return abs(s1-s2);
}

int main() {

	int n;
	int* arr;
	
	cin>>n;
	arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
	
	cout<<balancedPartition(arr,n);	
	
	return 0;

}
