//http://ideone.com/jwJnkM
//Coin change problem
 
#include <iostream>
#include <climits>
 
using namespace std;
 
int DP_Change( int* d , int n , int k ){
 
	int min,coin,p,i;
	int* C = new int[n];
	C[0] = 0;
 
	for( p = 1 ; p <= n ; p++ ){
 
		min = INT_MAX;
 
		for( i = 0 ; i < k ; i++ ){
 
			if( p >= d[i] ){
 
				if( C[ p - d[i] ] + 1 < min ){
 
					min = C[ p - d[i] ] + 1;
 
				}
 
			}	
 
		}
 
		C[p] = min;
 
	}
 
	return C[n];
 
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
