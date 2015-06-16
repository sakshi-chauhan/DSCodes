//http://ideone.com/PJ30cP
//Coin change problem, Variant-II

#include <iostream>
using namespace std;

int DP_Change( int* d , int n , int k ){
	
	if( n == 0 )
		return 1;
	
	if( n < 0 )
		return 0;
	
	if( n >= 1 && k <= 0 )
		return 0;
	
	return DP_Change( d , n , k-1 ) + DP_Change( d , n - d[k-1] , k )	;
	
}

int main() {

	int n,k;
	int* d;
 
	cin>>n>>k;
 
	d = new int[k];
 
	for( int i = 0 ; i < k ; i++ )
		cin>>d[i];
 
	cout<<DP_Change( d , n , k );	
	
	return 0;

}
