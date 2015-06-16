//http://ideone.com/ZZKlmv
//0/1 Knapsack problem in dynamic programming

#include <iostream>
#include <algorithm>
using namespace std;

int Knapsack( int* wt , int* val , int W , int n ){
	
	int sack[n+1][W+1];	
	
	
	for( int i = 0 ; i <= n ; i++ ){
		
		for( int w = 0 ; w <= W ; w++ ){
		
			if( i == 0 || w == 0 )
				sack[i][w] = 0;
			
			else if( wt[i-1] <= w )
				sack[i][w] = max( sack[i-1][w] , val[i-1]+sack[i-1][w-wt[i-1]]);
			
			else
				sack[i][w] = sack[i-1][w];
		
		}
		
	}
	
	return sack[n][W];
	
}

int main() {

	int n;
	int* wt;
	int* val;
	
	cin>>n;
	
	wt = new int[n];
	val = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>wt[i];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>val[i];
	
	cout<<Knapsack(wt,val,5,n);
	
	return 0;

}
