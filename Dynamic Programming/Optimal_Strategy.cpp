//http://ideone.com/C3GeG8
//Optimal starategy for a game - Dynamic Programming

#include <iostream>
using namespace std;

int optimalStrategy( int* arr , int n ){
	
	int V[n][n];
	
	for ( int gap = 0; gap < n; gap++ ){
		
        for ( int i = 0, j = gap; j < n; ++i, ++j){
            
            int x = ((i+2) <= j) ? V[i+2][j] : 0;
            int y = ((i+1) <= (j-1)) ? V[i+1][j-1] : 0;
            int z = (i <= (j-2))? V[i][j-2]: 0;
 
            V[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }
	
	return V[0][n-1];
}

int main() {

	int n;
	int* arr;
	
	cin>>n;
	arr = new int[n];
	
	for( int i = 0 ; i < n ; i++ )
		cin>>arr[i];
		
	cout<<optimalStrategy(arr,n);	
	
	return 0;

}
